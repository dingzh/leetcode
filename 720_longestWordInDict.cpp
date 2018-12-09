class Solution {
    struct TrieNode {
        bool isword;
        array<TrieNode*, 26> next;
        TrieNode() {
            isword = false;
            next.fill(nullptr);
        }
    };
    class Trie {
        TrieNode root;
    public:
        Trie(vector<string>& words) {
            root.isword = true;
            for (string& word : words) {
                TrieNode* p = &root;
                for (char ch : word) {
                    auto& next = p->next[ch-'a'];
                    if (next== nullptr) next = new TrieNode;
                    p = next;
                }
                p->isword = true;
            }
        }
        
        TrieNode* getRoot() { return &root; };
    };
    
public:
    string longestWord(vector<string>& words) {
        Trie trie(words);
        TrieNode* root = trie.getRoot();
        
        string ret, tmp;
        dfs(root, tmp, ret);
        return ret;
    }
    
    void dfs(TrieNode* node, string& tmp, string& ret) {
        if (node == nullptr || !node->isword) {
            return ;
        }
        
        if (tmp.length() > ret.length()) ret = tmp;
        
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            tmp.push_back(ch);
            dfs(node->next[ch-'a'], tmp, ret);
            tmp.pop_back();
        }
    }
};
