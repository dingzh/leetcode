class Trie {
    struct TrieNode {
        bool word;
        array<TrieNode*, 26> child;
        TrieNode():word(false) {
            for (auto& p : child) p = nullptr;
        }
    };

    TrieNode root;
public:
    Trie(vector<string>& words) {
        for (string& word : words) {
            TrieNode* p = &root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (p->child[idx]) {
                    p = p->child[idx];
                } else {
                    p->child[idx] = new TrieNode();
                    p = p->child[idx];
                }
            }
            p->word = true;
        }
    }

    vector<string> prefix(string& s, int start) {
        string tmp;
        vector<string> ret;
        int len = s.length();
        TrieNode* p = &root;
        for (int i = start; i < len; ++i) {
            int idx = s[i] - 'a';
            if (p->child[idx]) {
                tmp.push_back(s[i]);
                p = p->child[idx];
                if (p->word) ret.push_back(tmp);
            } else {
                break;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie(wordDict);
        vector<string> tmp;
        vector<string> ret;

        // if empty means cannot break in s[start, len)
        unordered_map<int, vector<string>> cache;
        cache[s.length()].emplace_back("");
        
        return wordBreakAux(s, 0, trie, cache);
    }

    vector<string>& wordBreakAux(string& s, int start, Trie& trie,
                               unordered_map<int, vector<string>>& cache) {
        if (cache.count(start)) {
            return cache[start];
        }
        
        vector<string> ret;

        // match from given start, iterate through all
        vector<string> match = trie.prefix(s, start);
        for (string& str : match) {
            vector<string>& res = wordBreakAux(s, start + str.length(), trie, cache);
            for (string& r_str : res) {
                string tmp = str;
                if (r_str.length()) {
                    tmp.push_back(' ');
                    tmp += r_str;
                }
                ret.emplace_back(move(tmp));
            }
        }
        
        cache[start] =  move(ret);
        return cache[start];
    }
};
