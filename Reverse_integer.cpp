// https://leetcode.com/problems/reverse-integer/submissions/
// LEvel: easy, time: O(n/10) n is the given integer
class Solution {
public:
	int reverse(int x) {
		int d=0, answer = 0;
		if(x == INT_MIN) return 0;
		if(x<0) { d = 1; x = x * -1; }
		for(int i=x; i>0; i/=10) {
			if(answer <= INT_MAX/10) answer *= 10;
			else return 0;
		answer += i%10;
		}
		if(d == 1) answer *= -1;
		return answer;
	}
};