// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/submissions/
// I. Find the minimum value of each sum in the given array.
// II. Return 1 - the minimum value.
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
// Memory Usage: 7.7 MB, less than 5.59% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
class Solution {
public:
	int minStartValue(vector<int>& nums) {
		int minsum=INT_MAX, sum=0, answer;
		for(int i=0; i<nums.size(); i++) {
			sum += nums[i];
			if(sum < minsum) minsum = sum;
		}
		answer = 1-minsum;
		if(answer<1) return 1;
		return answer;
	}
};