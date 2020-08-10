// https://leetcode.com/problems/rotated-digits/submissions/
// I. Invalid numbers: 3, 4, 7. It can't be a number if a number consists of at least invalid number.
// II. Good Number: 2, 5, 6, 9. If the number includes at least one good number and valid numbers, then it can be counted as good number.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotated Digits.
// Memory Usage: 6.1 MB, less than 48.18% of C++ online submissions for Rotated Digits.
class Solution {
public:
	int rotatedDigits(int n) {
		int answer = 0, t, good, invalid;
		for(int i=1; i<=n; i++) {
			good=0;
			invalid=0;
			for(t=i; t>0; t/=10) {
				if(t%10 == 3 || t%10 == 4 || t%10==7) invalid=1;
				if(t%10==2 || t%10==5 || t%10==6 || t%10 == 9) good = 1;
			}
			if(invalid==1) continue;
			if(good==1) answer+=1;
		}
		return answer;
	}
};