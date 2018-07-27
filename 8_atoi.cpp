#include <iostream>

using namespace std;

const unsigned int max_int_abs = (1u << 31) - 1;
const unsigned int min_int_abs = (1u << 31);

class Solution {
public:
    int myAtoi(string str) {
	unsigned int abs = 0;
	int sign = 1;

	auto sit = str.begin();
	
	// find first non-whitespace charactor
	while(sit != str.end() && *sit == ' ') ++sit;
	// first char must be sign or num
	
	if (sit == str.end()) return 0;
	if (*sit == '+') ++sit;
	else if (*sit == '-') {sign = -1; ++sit;}
	
	for (; sit != str.end(); ++sit) {
		int tmp = *sit - '0';
		if (tmp < 0 || tmp > 9) break;
		if (sign > 0 && (abs > max_int_abs/10 || (abs == max_int_abs/10 && tmp > max_int_abs % 10))) {abs = max_int_abs; break;}
		if (sign < 0 && (abs > min_int_abs/10 || (abs == min_int_abs/10 && tmp > min_int_abs % 10))) {abs = min_int_abs; break;}
		abs = abs * 10 + tmp;
	}

	return sign * abs;
    }
};
