class Solution {
    struct Ops {
        int index;
        string source;
        string target;
        Ops(int index, string&& source, string&& target):
            index(index), source(source), target(target) {}
        bool operator< (const Ops& rhs) const {
            return index < rhs.index;
        }
    };
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int ops_cnt = indexes.size();
        vector<Ops> operations;
        for (int i = 0; i < ops_cnt; ++i) 
            operations.emplace_back(indexes[i], move(sources[i]), move(targets[i]));
        sort(operations.begin(), operations.end());
        
        string result;
        int begin = 0;
        for (int i = 0; i < ops_cnt; ++i) {
            Ops& op = operations[i];
            
            while (begin < op.index) {
                result.push_back(S[begin]);
                ++begin;
            }

            if (S.compare(begin, op.source.length(), op.source) == 0) {
                result += op.target;
                begin += op.source.length();
            }
        }

        while (begin < S.length()) {
            result.push_back(S[begin]);
            ++begin;
        }

        return result;
    }
};
