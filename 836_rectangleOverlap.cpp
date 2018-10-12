class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool seperate = false;
        seperate |= rec2[1] >= rec1[3];
        seperate |= rec2[0] >= rec1[2];
        seperate |= rec2[3] <= rec1[1];
        seperate |= rec2[2] <= rec1[0];

        return !seperate;
    }
};
