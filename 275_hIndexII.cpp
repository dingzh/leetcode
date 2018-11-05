class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ret = 0;
        int size = citations.size();
        int lt = 0, rt = size - 1;

        while (lt <= rt) {
            int mid = lt + (rt - lt)/2;
            int num_paper = size - mid;
            int num_cite = citations[mid];
            if ( num_paper < num_cite ) {
                rt = mid - 1;
            } else if (num_cite < num_paper){
                lt = mid + 1;
            } else {
                return num_paper;
            }
        }
        return size - lt;
    }
};
