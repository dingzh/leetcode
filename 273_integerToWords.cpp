const vector<string> digits = {
    "", "One ", "Two ", "Three ", "Four ",
    "Five ", "Six ", "Seven ", "Eight ","Nine "
};
const vector<string> irregs = {
    "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
    "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
};
const vector<string> tens =  {
    "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ",
    "Sixty ", "Seventy ", "Eighty ", "Ninety "
};
const vector<string> conn = {"", "Thousand ", "Million ", "Billion "};

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        stack<string> stk;
        for (int i = 0; num != 0; ++i) {
            int part = num % 1000;
            num /= 1000;
            if (part != 0) {
                stk.push(conn[i]);
                stk.push(helper(part));
            }
        }
        string ret = "";
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
        ret.pop_back();

        return ret;
    }

    string helper(int num) {
        string ret = "";
        if (num >= 100) {
            ret += digits[num/100];
            ret += "Hundred ";
            num %= 100;
        }

        if ( 10 <= num && num < 20 ) {
            ret += irregs[num % 10];
            return ret;
        }

        ret += tens[num/10];
        ret += digits[num%10];
        return ret;
    }
};
