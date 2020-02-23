// https://leetcode.com/problems/arranging-coins/submissions/
// k(k+1) > n*2 -> 근의공식 k^2+k-n*2 -> (-1+-root(1+4*1*n*2))/2
// time: O(1) space: O(1)
// Runtime: 4 ms, faster than 87.25% of C++ online submissions for Arranging Coins.
// Memory Usage: 8.2 MB, less than 92.86% of C++ online submissions for Arranging Coins.
class Solution {
public:
	int arrangeCoins(int n) {
		double t = n, k;
		t += n;
		k = (-1+(sqrt(1+4*t)))/2;
		return (int)k;
	}
};

/*
* another solution with brute force
// k(k+1) > n*2 -> return k-1;
// time: O(logn) space: O(1)
class Solution {
public:
	int arrangeCoins(int n) {
		long long k=1;
		while((k*(k+1))/2 <= n) {
			k++;
		}
		return k-1;
	}
};
*/