// https://leetcode.com/problems/search-insert-position/submissions/
// I. Find the given number or a greater number than the give number in the array.
// II. If the found number is exactly equal to the given number, then return the index. If it is greater than th give number, then also return the index.
// time: O(n) space: O(1)
// Runtime: 4 ms, faster than 98.15% of C++ online submissions for Search Insert Position.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Search Insert Position.
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int answer=0;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] >= target) {
				answer = i;
				break;
			}
			if(i == nums.size()-1) answer = i+1;
		}
		return answer;
	}
};