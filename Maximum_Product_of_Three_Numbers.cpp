// https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/
// I. Sort the elements
// II. Think three different ways. 1: All elements are negative 2) All elements are positive, and there are both.
// time: O(nlogn) space: O(1)
// Runtime: 96 ms, faster than 30.50% of C++ online submissions for Maximum Product of Three Numbers.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Maximum Product of Three 
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if(nums[0] >=0) return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
		if(nums[nums.size()-1] <= 0) return nums[0]*nums[1]*nums[2];
		int tmp = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
		if(tmp > nums[0]*nums[1]*nums[nums.size()-1]) return tmp;
		return nums[0]*nums[1]*nums[nums.size()-1];
	}
};