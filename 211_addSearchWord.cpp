class WordDictionary {
    struct TreeNode {
        bool isWord;
        array<TreeNode*, 26> nodes;
        
        TreeNode() {
            isWord = false;
            nodes.fill(nullptr);
        }
    };
    
    TreeNode trie;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = &trie;
        for (char ch : word) {
            int idx = ch - 'a';
            auto& np = p->nodes[idx];
            if (!np) np = new TreeNode; 
            p = np;
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchAux(word, 0, &trie);
    }
    
    bool searchAux(const string& word, int idx, TreeNode* p) {
        if (idx == word.size()) return p && p->isWord;
        if (word[idx] != '.') 
            return p->nodes[word[idx] - 'a'] && searchAux(word, idx + 1, p->nodes[word[idx] - 'a']);
        
        for (TreeNode* np : p->nodes) {
            if (np && searchAux(word, idx + 1, np)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
