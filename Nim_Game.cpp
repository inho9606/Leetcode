// https://leetcode.com/problems/nim-game/submissions/
// Return false if the given stones are multiple of 4 because I cant' make it zero by removing one to three from the stones. It means that my friend cannot win if I can make it multiple of four. And if the given number of the stones are not multiple of four, I can make it by removing one to three stones. 
// time: O(1) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nim Game.
// Memory Usage: 8 MB, less than 83.33% of C++ online submissions for Nim Game.
class Solution {
public:
	bool canWinNim(int n) {
		if(n%4 == 0) return 0;
		return 1;
	}
};