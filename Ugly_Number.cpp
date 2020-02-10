// https://leetcode.com/problems/ugly-number/submissions/
// Iteratively divide 2, 3, and 5 until it cannot be divided anymore. After that, return true if the result is 1, or return false.
// time: O(logn)? space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Ugly Number.
// Memory Usage: 8.2 MB, less than 60.00% of C++ online submissions for Ugly Number.
class Solution {
public:
	bool isUgly(int num) {
		int i;
		for(i=num; i>1 && i%2==0; i/=2) ;
		for(; i>1 && i%3==0; i/=3) ;
		for(; i>1 && i%5==0; i/=5) ;
		if(i != 1) return 0;
		return 1;
	}
};