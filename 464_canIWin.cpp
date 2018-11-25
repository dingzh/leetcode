class Solution {
    constexpr static int N = 21;
    unordered_map<bitset<N>, bool> memory;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ( (maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal ) return false;
        
        // one of the player will win
        bitset<N> candidates;
        candidates.set(0);
        for (int i = 0; i <= maxChoosableInteger; ++i) candidates.set(i);

        return canIWinAux(candidates, desiredTotal);
    }

    bool canIWinAux(bitset<N>& candidates, int desiredTotal) {
        if (desiredTotal <= 0) return false;
        if (memory.count(candidates)) return memory[candidates];

        bool ret = false;
        for (int i = 1; i < N; ++i) {
            if (candidates.test(i)) {

                candidates.reset(i);
                bool canNextWin = canIWinAux(candidates, desiredTotal - i);
                candidates.set(i);
                
                if (!canNextWin) {
                    ret = true;
                    break;
                }
            }
        }

        memory[candidates] = ret;
        return ret;
    }
};
