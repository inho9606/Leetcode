// https://leetcode.com/problems/binary-number-with-alternating-bits/submissions/
// I. Remember the previous bit's value, and compare the next one.
// II. If the duplicate numbers are grater than 1, then return false.
// time: O(1) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Number with Alternating Bits.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Binary Number with Alternating Bits.
class Solution {
public:
	bool hasAlternatingBits(int n) {
		int cnt=0, tmp=(n&1);
		for(int i=0; i<32; i++) {
			if((n&1) == tmp) cnt++;
			else {
				if(cnt>1) return 0;
				cnt=1;
			}
				tmp = n & 1;
			n = n >> 1;
		}
		return 1;
	}
};