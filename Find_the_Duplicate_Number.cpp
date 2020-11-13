// https://leetcode.com/problems/find-the-duplicate-number/submissions/
// I. Mark the appeared number by multiplying minus1.
// II. If the number is already negative, then return that number.
// time: O(n) space: O(1)
// Runtime: 8 ms, faster than 99.56% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 11.5 MB, less than 19.31% of C++ online submissions for Find the Duplicate Number.
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int t;
		for(int i=0; i<nums.size(); i++) {
			t = abs(nums[i]);
			if(nums[t-1]>0) nums[t-1] *= -1;
			else break;
		}
		return t;
	}
};