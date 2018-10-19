class Trie {
    struct TrieNode {
        bool word;
        TrieNode* child[26] = {nullptr};
        TrieNode():word(false) {}
    };

    TrieNode* trie;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = trie;
        for (char ch : word) {
            int idx = ch - 'a';
            auto& child = curr->child;
            if (child[idx]) {
                curr = child[idx];
            } else {
                curr = new TrieNode();
                child[idx] = curr;
            }
        }
        curr->word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* prefix = findPrefix(word);
        return prefix != nullptr && prefix->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return findPrefix(prefix) != nullptr;
    }

    TrieNode* findPrefix(string prefix) {
        TrieNode* curr = trie;
        for (char ch : prefix) {
            int idx = ch - 'a';
            auto& child = curr->child;
            if (child[idx]) {
                curr = child[idx];
            } else {
                return nullptr;
            }
        }
        return curr;
    }

    ~Trie() {
        clear(trie);
    }

    void clear(TrieNode* root) {
        if (!root) return ;
        for (auto node : root->child) {
            clear(node);
        }
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
