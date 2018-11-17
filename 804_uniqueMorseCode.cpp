class Solution {
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> morse_word;
        
        for (string& word : words) {
            string tran;
            for (char ch : word) {
                tran += morse_code[ch - 'a'];
            }
            morse_word.insert(tran);
        }
        return morse_word.size();
    }
};
