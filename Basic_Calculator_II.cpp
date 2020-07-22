// https://leetcode.com/problems/basic-calculator-ii/submissions/
// I. All expressions with numbers convert to add.
// II. Need to keep the last sign. If the last one was * or /, then we should calculate it first. If it is just + or -, then just add current number.
// III. Need to remember the last number as well because multiply or divide need the previous value.
// Refered to discuss board.. to get basic idea.
// time: O(n) space: O(1)
// Runtime: 20 ms, faster than 92.28% of C++ online submissions for Basic Calculator II.
// Memory Usage: 7.7 MB, less than 91.87% of C++ online submissions for Basic Calculator II.
class Solution {
public:
	int calculate(string s) {
		int answer=0, t=0, t2=0;
		char last='+';
		for(int i=0; i<s.size(); i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				t *= 10;
				t += s[i]-48;
			}
			if(i == s.size()-1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				if(last=='+')
					answer += t;
				else if(last == '-') {
					t *= -1;
					answer += t;
				}
				else if(last == '*') {
					answer -= t2;
					t *= t2;
					answer += t;
				}
				else if(last == '/') {
					answer -= t2;
					t = t2/t;
					answer += t;
				}
				t2 = t;
				t = 0;
				last = s[i];
			}		
		}
		return answer;
	}
};