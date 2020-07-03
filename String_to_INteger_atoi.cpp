// https://leetcode.com/problems/string-to-integer-atoi/submissions/
// I. Jump to the first non-white space.
// II. Return 0 if the first non-space character is plus or minus sign. Move the index to the next if the character is plus or minus, and record it if it is minus.
// III. convert the characters into numeric value until non-numeric character is found or str ends. If the result of converting exceeds the range of 32-bit, then record it and stop loop.
// IV. Multiply -1 if the sign was minus. and return the value.
// time: O(n) space: O(1)
// Runtime: 4 ms, faster than 81.99% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 6.2 MB, less than 58.52% of C++ online submissions for String to Integer (atoi).
class Solution {
public:
	int myAtoi(string str) {
		int i, minus=0, exceed=0;
		long long answer=0;
		for(i=0; i<str.size() && str[i] == ' '; i++) ;
		if(i == str.size() || (str[i] < '0' && str[i] > '9')) return 0;
		if(str[i] == '-') { minus = 1; i+=1; }
		else if(str[i] == '+') i+=1;
		for(; i<str.size() && str[i] >= '0' && str[i] <= '9'; i++) {
			if(answer*10 > INT_MAX) { exceed = 1; break; }
			else answer *= 10;
			if(answer + str[i]-48 > INT_MAX) { exceed = 1; break; }
			else answer += str[i]-48;
		}
		if(exceed == 1 && minus == 1) answer = INT_MIN;
		else if(exceed == 1 && minus == 0) answer = INT_MAX;
		else if(minus == 1) answer *= -1;
		return answer;
	}
};