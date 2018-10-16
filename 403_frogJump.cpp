class Solution {
    unsigned int target;
    map<pair<unsigned int, unsigned int>, bool> memory;
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;

        unordered_set<int> stone_pos(stones.begin(), stones.end());
        unordered_map<int, set<int>> moves;
        moves[1].insert(1);
        
        for (auto stone : stones) {
            if (!moves.count(stone)) continue; 

            auto& move = moves[stone];
            for (int k : move) {
                for (int i = -1; i < 2; ++i) {
                    if (k + i <= 0) continue;
                    int next_pos = k + i + stone;
                    if (stone_pos.count(next_pos))
                        moves[next_pos].insert(k + i);
                }
            }
        }
        return moves.count( stones.back() );
    }
};
