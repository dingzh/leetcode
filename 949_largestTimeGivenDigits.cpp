class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        auto perm_A = permute(A);
        
        vector<int> max_time;
        bool valid = false;
        // auto print = [&]() { for (int num : max_time) cout << num << ' '; cout << endl; };
        for (auto& perm : perm_A) {
            if (validCheck(perm) && (!valid || comp(perm, max_time))) {
                valid = true;
                max_time = perm;
                // print();
            }
        }
        
        return valid ? makeTime(max_time) : "";
    }
    
    bool comp(vector<int>& A, vector<int>& B) {
        for (int i = 0; i < 4; ++i) {
            if (A[i] < B[i]) return false;
            else if (A[i] > B[i]) return true;
        }
        
        return false;
    }
    
    bool validCheck(vector<int>& perm) {
        bool ret = true;
        ret = ret && perm[0] < 3;
        ret = ret && (perm[0] < 2 || perm[1] < 4);
        ret = ret && perm[2] < 6 && perm[3] < 10;
        return ret;
    }
    
    string makeTime(vector<int>& time) {
        string ret;
        ret.push_back(time[0] + '0');
        ret.push_back(time[1] + '0');
        ret.push_back(':');
        ret.push_back(time[2] + '0');
        ret.push_back(time[3] + '0');
        return ret;
    }
    
    vector<vector<int>> permute(vector<int>& A) {
        vector<vector<int>> ret;
        
        vector<int> tmp;
        permuteAux(A, ret, 0);
        return ret;
    }
    
    void permuteAux(vector<int>& A, vector<vector<int>>& ret, int start) {
        int size = A.size();
        if (size == start) {
            ret.emplace_back(A);
            return;
        }
        
        permuteAux(A, ret, start+1);
        for (int i = start+1; i < size; ++i) {
            swap(A[start], A[i]);
            permuteAux(A, ret, start+1);
            swap(A[start], A[i]);
        }
    }
};
