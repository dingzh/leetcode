class Solution {
    vector<string> ret;
public:
    vector<string> generateAbbreviations(string word) {
        string tmp;
        aux(word, 0, 0, tmp);
        return ret;
    }
    
    void aux(const string& word, int start, int prev, string tmp) {
        if (start == word.length()) {
            if (prev) tmp += to_string(prev);
            
            ret.emplace_back(move(tmp));
            return ;
        }
        
        aux(word, start + 1, prev + 1, tmp);
        
        if (prev) tmp += to_string(prev);
        tmp.push_back(word[start]);
        aux(word, start + 1, 0, tmp);
    }
};
