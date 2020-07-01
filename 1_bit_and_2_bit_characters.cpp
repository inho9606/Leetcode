// https://leetcode.com/problems/1-bit-and-2-bit-characters/submissions/
// I. Check the value of current index is one or zero. If it is one, jump two indices, and just move to the next element if it is zero.
// II. If you can access the last element, return true. otherwise return false.
// time: O(n) space: O(1)
// Runtime: 4 ms, faster than 98.67% of C++ online submissions for 1-bit and 2-bit Characters.
// Memory Usage: 9.9 MB, less than 38.53% of C++ online submissions for 1-bit and 2-bit Characters.
class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		for(int i=0; i<bits.size(); ) {
			if(i==bits.size()-1) return 1;
			if(bits[i] == 1) i += 2;
			else i++;
		}
		return 0;
	}
};