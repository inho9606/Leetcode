// https://leetcode.com/problems/valid-perfect-square/submissions/
// Perfect square numbers from 1 to n are 1, 4, 9, 16, 25 .... Let's say those of perfect numbers S. S[1] = 1, S[2] = 4... S[n]-S[n-1] is odd number from 1 (i.e. 1, 3, 5, 7...) Therefore, subtract 1, 3, 5, 7... from the given number num. If the result is 0, then it is perfect number.
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 8 MB, less than 95.24% of C++ online submissions for Valid Perfect Square.
class Solution {
public:
	bool isPerfectSquare(int num) {
		for(int i=1; num>0; i+=2) num -= i;
		if(num==0) return 1;
		return 0;
	}
};