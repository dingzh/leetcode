class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();

        vector<int> gas_when_arrive(2 * N, 0);
        for (int i = 1; i < 2 * N; ++i) {
            gas_when_arrive[i] =
                gas_when_arrive[i-1] - cost[(i-1) % N] + gas[(i - 1) % N];
        }
        
        int start = 0;
        while (start < N) {
            int start_gas = gas_when_arrive[start];
            int i = start + 1;
            while (i <= start + N && gas_when_arrive[i] >= start_gas) ++i;
            if (i > start + N) return start;
            else start = i;
        }
        return -1;
    }
};
