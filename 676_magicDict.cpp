class MagicDictionary {
    unordered_set<string> dict_set;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        dict_set = unordered_set<string>( dict.begin(), dict.end() );
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.length(); ++i) {
            char tmp = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == tmp) continue;
                word[i] = ch;
                if (dict_set.count( word )) return true;
            }
            word[i] = tmp;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
