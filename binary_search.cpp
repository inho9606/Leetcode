// https://leetcode.com/problems/binary-search/submissions/
// Just normal binary search technique.
// Runtime: 76 ms, faster than 84.60% of C++ online submissions for Binary Search.
// Memory Usage: 27.8 MB, less than 19.07% of C++ online submissions for Binary Search.
// time: O(logn) space: O(1)

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int s=0, e=nums.size()-1, m;
		while(s<=e) {
			m = (s+e)/2;
			if(nums[m] == target) return m;
			else if(target < nums[m]) e = m-1;
			else s = m+1;
		}
		return -1;
	}
};