class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        
        // nums1 has smaller size
        int size1 = nums1.size(), size2 = nums2.size();
        int half = (size1 + size2) / 2;
        // half wont be zero
        
        int lt = 0, rt = size1;  // binary search range, inclusive
        while (lt <= rt) {
            int pivot1 = lt + (rt - lt) / 2;
            int pivot2 = half - pivot1;
            bool pred1 = (pivot1 == 0 || pivot2 == size2 || nums1[pivot1-1] <= nums2[pivot2]);
            bool pred2 = (pivot2 == 0 || pivot1 == size1 || nums2[pivot2-1] <= nums1[pivot1]);
            if (pred1 && pred2) {
                // right division
                int minr;
                if (pivot1 == size1) minr = nums2[pivot2];
                else if (pivot2 == size2) minr = nums1[pivot1];
                else minr = min(nums1[pivot1], nums2[pivot2]);
                if ((size1 + size2) & 1) {
                    return minr;
                }
                
                int maxl;
                if (pivot1 == 0) maxl = nums2[pivot2-1];
                else if (pivot2 == 0) maxl = nums1[pivot1-1];
                else maxl = max(nums1[pivot1-1], nums2[pivot2-1]);
                return (double (minr + maxl)) / 2;
                
            } else if (pred1 && !pred2) {
                lt = pivot1 + 1;
            } else if (!pred1 && pred2){
                rt = pivot1 - 1;
            } else {
                // which is impossible
            }
        }
    }
};
