/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int size = wordlist.size();
        
        vector<vector<int>> match(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            match[i][i] = 6;
            for (int j = i + 1; j < size; ++j) {
                int res = countMatch(wordlist[i], wordlist[j]);
                match[i][j] = match[j][i] = res;
            }
        }
        
        deque<int> candidates;
        for (int i = 0; i < size; ++i) candidates.push_back(i);
        
        int try_cnt = 10;
        while (try_cnt--) {
            int size = candidates.size();

            vector<int> guess_cand;
            int best_worstcase = -1;
            for (int cand : candidates) {
                int worstcase = getWorstCase(candidates, cand, match);
                if (worstcase > best_worstcase) {
                    best_worstcase = worstcase;
                    guess_cand = {cand};
                } else if (worstcase == best_worstcase) {
                    guess_cand.push_back(cand);
                }
            }
            
            int guess = guess_cand[guess_cand.size()/2];
            int res = master.guess(wordlist[guess]);
            
            if (res == 6) return ;
            
            while (size--) {
                int comp = candidates.front();
                candidates.pop_front();
                if (comp != guess && res == match[comp][guess]) candidates.push_back(comp);
            }
        }
    }
    
    int getWorstCase(deque<int>& candidates, int cand, vector<vector<int>>& match) {
        vector<int> count(7, 0);
        
        for (int comp : candidates) {
            ++count[match[cand][comp]];
        }
        count.pop_back(); // remove match with self
        
        return *min_element(begin(count), end(count));
    }
    
    int countMatch(string& a, string& b) {
        int ret = 0;
        for (int i = 0; i < 6; ++i) {
            if (a[i] == b[i]) ++ret;
        }
        return ret;
    }
};
