class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set( wordList.begin(), wordList.end() );
        if (!word_set.count( endWord )) return 0;

        queue<string> q; q.push( beginWord );
        unordered_set<string> marked; 
        marked.insert( beginWord );

        int step = 0, size = 1;
        while (size) {
            ++step;
            while (size--) {
                auto word = move(q.front());
                q.pop();
                if (word == endWord) return step;

                for (int i= 0; i < word.length(); ++i) {
                    char tmp = word[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        word[i] = ch;
                        if (word_set.count( word ) && !marked.count( word )) {
                            marked.insert( word );
                            q.push( word );
                        }
                    }
                    word[i] = tmp;
                }
            }
            size = q.size();
        }
        return 0;
    }
};
