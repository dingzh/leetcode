class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        unordered_map<int, int> corner_count;
        
        int row = grid.size();
        if (row < 2) return 0;
        int col = grid[0].size();
        if (col < 2) return 0;
        
        int ret = 0;
        for (int r = 0; r < row; ++r) {
            vector<int> ones;
            for (int i = 0; i < col; ++i) {
                if (grid[r][i]) ones.push_back(i);
            }
            
            vector<int> corner_pairs = get_pairs(ones);
            for (auto& cp : corner_pairs) {
                ret += corner_count[cp]++;
            }
        }
        
        return ret;
    }
    
    vector<int> get_pairs(vector<int>& ones) {
        int size = ones.size();
        vector<int> ret;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                ret.push_back(ones[i]* 201 + ones[j]);
            }
        }
        return ret;
    }
};
