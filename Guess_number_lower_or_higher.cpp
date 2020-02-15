// https://leetcode.com/problems/guess-number-higher-or-lower/submissions/
// Solved this problem with just binary search
// time: O(logn) space: O(1)
// Runtime: 4 ms, faster than 51.93% of C++ online submissions for Guess Number Higher or Lower.
// Memory Usage: 8.2 MB, less than 83.33% of C++ online submissions for Guess Number Higher or Lower.

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		long long start=1, end=n, mid;
		while(start <= end) {
			mid = (start+end)/2;
			if(guess(mid) == -1) end = mid-1;
			else if(guess(mid) == 1) start = mid+1;
			else break;
		}
		return mid;
	}
};