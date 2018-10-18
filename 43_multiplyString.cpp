class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return 0;
        int len1 = num1.length(), len2 = num2.length();

        // using '\0' to avoid converting char to int
        string result(len1+len2, '\0');
        for (int i = len1-1; i > -1; --i) {
            int x = num1[i] - '0';
            for (int j = len2-1; j > -1; --j) {
                int y = num2[j] - '0';
                int mul = x * y + result[i+j+1];
                result[i+j+1] = mul % 10;
                result[i+j] += mul / 10;
            }
        }

        // infact, only the first bit can be 0
        result.erase(0, result.find_first_not_of('\0'));
        // convert to char
        for (auto& ch : result) ch += '0';

        return result;
    }
};
