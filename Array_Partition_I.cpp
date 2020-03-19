// https://leetcode.com/problems/array-partition-i/submissions/
// I. Sort
// II. Sum of the oddth numbers
// time: O(nlogn) space: O(1)
// Runtime: 76 ms, faster than 71.12% of C++ online submissions for Array Partition I.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Array Partition I.
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int answer=0;
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size(); i+=2)
			answer += nums[i];
		return answer;
	}
};