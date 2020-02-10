// https://leetcode.com/problems/missing-number/submissions/
// subtract sum of the given numbers from sum of 1 to n. n is a maximum number of given numbers, which means n is the size of the numbers because the given numbers are from 0 though n, and it has ma missed number. That's why the size of the given numbers should be n+1.
// time: O(n) space: O(1)
// Runtime: 24 ms, faster than 80.87% of C++ online submissions for Missing Number.
// Memory Usage: 9.8 MB, less than 88.24% of C++ online submissions for Missing Number.
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum=0, n=nums.size();
		for(int i=0; i<n; i++)
			sum += nums[i];
		return (n*(n+1))/2 - sum;
	}
};