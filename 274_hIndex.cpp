class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int ret = 0;
        for (int i = 0; i < size; ++i) {
            if ( size - i >= citations[i] ) {
                ret = max(citations[i], ret);
            } else {
                ret = max(size - i, ret);
            }
        }
        return  ret ;
    }
};
