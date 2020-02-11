// https://leetcode.com/problems/hamming-distance/submissions/
// Use bit operation. Count if x & 1-bit and y & 1-bit is not same, and return the count.
// time: O(1) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
// Memory Usage: 8.2 MB, less than 77.27% of C++ online submissions for Hamming Distance.
class Solution {
public:
	int hammingDistance(int x, int y) {
		int cnt=0;
		for(int i=0; i<32; i++) {
			if((x & 1) != (y & 1)) cnt++;
			x = x>>1;
			y = y>>1;
		}
		return cnt;
	}
};