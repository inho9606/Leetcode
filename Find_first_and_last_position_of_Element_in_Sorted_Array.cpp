// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// I. Find the target with Binary Search.
// II. From the target, plus one until it faces other number of subtract one.
// time: O(n) space: O(1)
// Runtime: 20 ms, faster than 60.46% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 14 MB, less than 22.42% of C++ online submissions for Find First and Last Position of Element in Sorted Array.


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int s=0, m, e=nums.size()-1;
		while(s<=e) {
			m = (s+e)/2;
			if(nums[m] == target) {
				for(s=m; s>=0 && nums[s] == target; s--);
				for(e=m; e<nums.size() && nums[e] == target; e++) ;
				return {s+1, e-1};
			}
			else if(nums[m] < target) s = m+1;
			else e = m-1;
		}
		return {-1,-1};
	}
};