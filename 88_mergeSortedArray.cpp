class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1, write_idx = m+n -1;

        while (p1 > -1 && p2 > -1) {
            nums1[write_idx--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        }

        while (p2 > -1) {
            nums1[write_idx--] = nums2[p2--];
        }
    }
};
