class Solution {
    struct TrieNode {
        bool word;
        array<TrieNode*, 26> next;
        TrieNode():word(false), next({nullptr}) {}
    };

    class Trie {
        TrieNode root;
    public:
        Trie() = default;
        Trie(vector<string>& words) {
            for (auto& word : words) {
                TrieNode* p = &root;
                for (char ch : word) {
                    TrieNode* &next = p->next[ch - 'a'];
                    if (next == nullptr) next = new TrieNode;
                    p = next;
                }
                p->word = true;
            }
        }

        static TrieNode* next(TrieNode* node, char ch) {
            if (node) return node->next[ch - 'a'];
            else return nullptr;
        }

        TrieNode* getRoot() { return &root; }
    };

    int row;
    int col;
    vector<string> ret;
    Trie t_words;
    vector<vector<int>> visited;
    vector<pair<int,int>> positions;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        if (!row) return {};
        col = board[0].size();
        if (!col) return {};

        t_words = Trie(words);
        positions = {{-1,0},{1,0}, {0,-1}, {0,1}};
        visited = vector<vector<int>>(row, vector<int>(col, 0));

        string word;
        TrieNode* root = t_words.getRoot();
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) {
                dfs(board, r, c, word, root);
            }
        return ret;
    }

    void dfs(vector<vector<char>>& board, int r, int c, string& word, TrieNode* p) {
        if (p == nullptr || r < 0 || r >= row || c < 0 || c >= col || visited[r][c]) return ;

        visited[r][c] = 1;
        
        word.push_back(board[r][c]);
        p = t_words.next(p, board[r][c]);
        if (p != nullptr) {
            if (p->word) {
                ret.push_back(word);
                p->word = false;
            }
        
            for (auto& pos : positions) {
                dfs(board, r + pos.first, c + pos.second, word, p);
            }
        }

        word.pop_back();
        visited[r][c] = 0;
    }
};
