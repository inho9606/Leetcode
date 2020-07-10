// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
// I. Find the index where the value is increased to split given array into two parts.
// II. Compare the given target and splited arrays, and search it.
// time: O(logn) space: O(1)
// Runtime: 4 ms, faster than 96.64% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.4 MB, less than 14.54% of C++ online submissions for Search in Rotated Sorted Array.
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.size()==0) return -1;
		int s=0, m, e=nums.size()-1;
		for(int i=0; i<nums.size()-1; i++) {
			if(nums[i] > nums[i+1]) {
				if(target >= nums[0] && target <= nums[i]) {
					s = 0;
					e = i;
				}
				else {
					s = i+1;
					e = nums.size()-1;
				}
				break;
			}
		}
		while(s<=e) {
			m = (s+e)/2;
			if(nums[m] == target) return m;
			else if(nums[m] > target) e = m-1;
			else s = m+1;
		}
		return -1;
	}
};