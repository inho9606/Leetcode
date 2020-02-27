// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/submissions/
// The number of moves to make all elements equal in the given array is equal to the number of each steps to make every element equal to the minimum value by subtracting 1 by 1 step.(Couldn't understand why..) So, first, find the minimum value in the given array, and then sum of differences between each elemtn and the minimum value.
// time: O(n) space: O(1)
// Runtime: 48 ms, faster than 93.11% of C++ online submissions for Minimum Moves to Equal Array Elements.
// Memory Usage: 11 MB, less than 66.67% of C++ online submissions for Minimum Moves to Equal Array Elements.
class Solution {
public:
	int minMoves(vector<int>& nums) {
		int answer=0, m = INT_MAX;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] < m) m = nums[i];
		}
		for(int i=0; i<nums.size(); i++) {
			answer += nums[i] - m;
		}
		return answer;
	}
};