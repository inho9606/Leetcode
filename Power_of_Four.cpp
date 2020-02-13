// In 2-bit operation, there must be only one bit with 1 value for it to be power of four, and the only one bit should be on the odd numberth from the most right 9i.e. 0001, 0100, 10000)
// time: O(1) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Four.
// Memory Usage: 8.1 MB, less than 95.24% of C++ online submissions for Power of Four.
class Solution {
public:
	bool isPowerOfFour(int num) {
		int cnt=0;
		for(int i=0; i<32; i++) {
			if(i%2 == 1 && (num&1) == 1) return 0;
			if(num&1 == 1) cnt++;
			num = num>>1;
		}
		if(cnt != 1) return 0;
		return 1;
	}
};