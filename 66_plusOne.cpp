class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        int size = digits.size();
        for (int i = size - 1; i > -1 && c; --i) {
            digits[i] += 1;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        if (c) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
