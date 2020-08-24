// https://leetcode.com/problems/guess-number-higher-or-lower/submissions/
// It's  just binary search solution.
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Guess Number Higher or Lower.
// Memory Usage: 5.9 MB, less than 82.08% of C++ online submissions for Guess Number Higher or Lower.
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
	int guessNumber(int n) {
		long long s=1, e=n, m;
		while(s<=e) {
			m = (s+e)/2;
			if(guess(m) == 0) break;
			else if(guess(m) == -1) e=m-1;
			else s = m+1;
		}
		return m;
	}
};