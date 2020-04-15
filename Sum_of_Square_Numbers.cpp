// https://leetcode.com/problems/sum-of-square-numbers/submissions/
// I. Subtract the closest root number of given c.
// II. Check if the number from I can be divided by itself.
// time: O(n) space: O(1)
// Runtime: 4 ms, faster than 63.53% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Sum of Square Numbers.
class Solution {
public:
	bool judgeSquareSum(int c) {
		for(int a=(int)sqrt(c); a>=0; a--) {
			int b = c-a*a;
			if((int)sqrt(b)*(int)sqrt(b) == b) return 1;
		}
		return 0;
	}
};