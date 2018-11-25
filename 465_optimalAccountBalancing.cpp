class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> acct_to_balance;
        for (auto& tran : transactions) {
            acct_to_balance[ tran[0] ] += tran[2];
            acct_to_balance[ tran[1] ] -= tran[2];
        }

        vector<int> acct_send, acct_recv;
        for (auto& acct_balance : acct_to_balance) {
            int amount = acct_balance.second;
            if (amount < 0) {
                acct_send.push_back( -amount );
            } else if (amount > 0) {
                acct_recv.push_back( amount );
            }
        }

        if (acct_send.size() == 0) return 0;

        return minTranAux(acct_send, acct_recv, 0, 0);
    }

    int minTranAux(vector<int>& acct_send, vector<int>& acct_recv,
                    int s_start, int r_start) {
        int s_size = acct_send.size(), r_size = acct_recv.size();
        if (s_size == s_start + 1) return r_size - r_start;
        if (r_size == r_start + 1) return s_size - s_start;

        int ret = numeric_limits<int>::max();
        int& to_send = acct_send[s_start];
        for (int i = r_start; i < r_size; ++i) {

            if (to_send == acct_recv[i]) {
                swap(acct_recv[i], acct_recv[r_start]);
                ret = minTranAux(acct_send, acct_recv, s_start + 1, r_start + 1);
                swap(acct_recv[i], acct_recv[r_start]);
                break;
            }else if (to_send < acct_recv[i]) {
                acct_recv[i] -= to_send;
                ret = min(ret, minTranAux(acct_send, acct_recv, s_start + 1, r_start));
                acct_recv[i] += to_send;
            } else {
                swap(acct_recv[i], acct_recv[r_start]);
                to_send -= acct_recv[i];
                ret = min(ret, minTranAux(acct_send, acct_recv, s_start, r_start + 1));
                to_send += acct_recv[i];
                swap(acct_recv[i], acct_recv[r_start]);
            }
        }

        return ret + 1;
    }
};
