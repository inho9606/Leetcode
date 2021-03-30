// https://leetcode.com/problems/maximum-subarray/submissions/
// time: O(n)
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int answer = nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for(int i=1; i<nums.size(); i++) {
			if(nums[i] > dp[i-1]+nums[i]) dp[i] = nums[i];
			else dp[i] = dp[i-1]+nums[i];
			if(dp[i] > answer) answer = dp[i];
		}
		return answer;
	}
};