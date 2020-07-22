// https://leetcode.com/problems/jump-game/submissions/
// I. Position should be the farthest index.
// II. Update farthest position checking available jump.
// III. Return true if the position is successfully grater than the range of total length. Return false if the position can't move forward to the end since available jump is 0.
// time: O(n) space: O(1)
// Runtime: 20 ms, faster than 83.49% of C++ online submissions for Jump Game.
// Memory Usage: 12.8 MB, less than 77.59% of C++ online submissions for Jump Game.
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int position = 0;
		for(int i=0; i<nums.size(); i++) {
			if(i+nums[i] > position) position = i+nums[i];
			if(position >= nums.size()-1) return 1;
			else if(nums[i] == 0 && i == position) break;
		}
		return 0;
	}
};