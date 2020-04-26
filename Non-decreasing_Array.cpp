// https://leetcode.com/problems/non-decreasing-array/submissions/
// I. Check the current element is greater than the next one.
// II. If so, Consider the order of the privious one and the next one to decide which one should be copied to the current position. And copy it to keep the non-decreasing rule.
// III. If this process is repeated more than once, return false, otherwise return true.
// time: O(n) space: O(1)
// Runtime: 40 ms, faster than 9.39% of C++ online submissions for Non-decreasing Array.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Non-decreasing Array.
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int i, cnt=0;
		for(i=0; i<nums.size()-1; i++) {
			if(nums[i] > nums[i+1] && cnt == 0) {
				if(i==0 || nums[i+1] > nums[i-1]) nums[i] = nums[i+1];
				else nums[i+1] = nums[i];
				cnt++;
			}
			else if(nums[i] > nums[i+1] && cnt != 0) return 0;
		}
		return 1;		
	}
};