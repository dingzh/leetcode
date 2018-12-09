class Solution {
    class DisjointSet {
        vector<int> parent;
    public:
        DisjointSet(int size) {
            parent = vector<int>(size, 0);
            for (int i = 0; i < size; ++i) parent[i] = i;
        }
        
        int find(int idx) {
            if (parent[idx] != idx) parent[idx] = find(parent[idx]);
            return parent[idx];
        }
        
        void join(int idx1, int idx2) {
            int p1 = find(idx1);
            int p2 = find(idx2);
            parent[p2] = p1;
        }
    };
public:
    int largestComponentSize(vector<int>& A) {
        // todo handle one in A
        constexpr int maxAi = 100000;
        
        int asize = A.size();
        if (asize < 2) return asize;
        
        auto primes = getPrime();
        int psize = primes.size();
        
        DisjointSet ds(maxAi + 1);
        
        for (int num : A) {
            const int orig = num;
            // factoring num
            for (int prime : primes) if (prime <= num) {
                if (num % prime == 0) {
                    ds.join(orig, prime);
                    while(num % prime == 0) num /= prime;
                }
            } else {
                break;
            }
            
            // num must be a prime now if not 1
            if (num > 1) ds.join(orig, num);
        }
        
        unordered_map<int, int> seen;
        int max_cnt = 0;
        for (int num : A) {
            int comp = ds.find(num);
            max_cnt = max(max_cnt, ++seen[comp]);
        }
        return max_cnt;
    }
    
    vector<int> getPrime() {
        constexpr int maxNum = 350;
        bitset<maxNum> is_prime;
        is_prime.set(); // set all bits to true
        
        vector<int> ret;
        ret.push_back(2);
        
        for (int i = 3; i < maxNum; i += 2) {
            if (is_prime.test(i)) ret.push_back(i);
            for (int j = 2 * i; j < maxNum; j += i) {
                is_prime.reset(j);
            }
        }
        
        return ret;
    }
};
