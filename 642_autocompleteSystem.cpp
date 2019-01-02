class AutocompleteSystem {
    struct TrieNode {
        int times;
        array<TrieNode*, 27> nodes;
        TrieNode() {
            times = 0;
            nodes.fill(nullptr);
        }
    };
    
    struct Candidate {
        int times;
        string str;
        Candidate(int times, const string& str):times(times), str(str) {}
        bool operator< (const Candidate& rhs) const {
            return times > rhs.times || (times == rhs.times && str.compare(rhs.str) < 0);
        }
    };
    
    string path;
    TrieNode trie;
    TrieNode* p = &trie;
public:
    AutocompleteSystem(const vector<string>& sentences, const vector<int>& times) {
        int size = sentences.size();
        for (int i = 0; i < size; ++i) {
            auto curr = &trie;
            for (auto ch: sentences[i]) {
                auto& next = (ch == ' ') ? curr->nodes.back() : curr->nodes[ch - 'a'];
                if (!next) next = new TrieNode();
                curr = next;
            }
            curr->times = times[i];
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            path.clear();
            ++p->times;
            p = &trie; // reset;
            return {};
        }
        
        if (p == nullptr) return {};
        
        path.push_back(c);
        auto& curr = (c == ' ') ? p->nodes.back() : p->nodes[c - 'a'];
        if (!curr) {
            curr = new TrieNode();
            p = curr;
            return {};
        }
        
        p = curr;
        
        string str;
        priority_queue<Candidate> pq;
        
        dfs(p,str, pq);        

        vector<string> ret;
        while (!pq.empty()) {
            ret.emplace_back(path + pq.top().str);
            pq.pop();
        }
        reverse(begin(ret), end(ret));
        return ret;
    }
    
    static void dfs(TrieNode* root, string& str, priority_queue<Candidate>& pq) {
        
        int times = root->times;
        auto& nodes = root->nodes;
        
        if (times) {
            Candidate cand(times, str);
            if (pq.size() < 3) {
                pq.push(cand);
            } else if (cand < pq.top()) {
                pq.pop();
                pq.push(cand);
            }
        }
        
        str.push_back(' ');
        if (nodes.back()) dfs(nodes.back(), str, pq);
        str.pop_back();
        
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            str.push_back(ch);
            if (nodes[ch - 'a']) dfs(nodes[ch - 'a'], str, pq);
            str.pop_back();
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
