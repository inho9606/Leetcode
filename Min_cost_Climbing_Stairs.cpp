// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
// Runtime: 8 ms, faster than 67.83% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 13.6 MB, less than 75.56% of C++ online submissions for Min Cost Climbing Stairs.

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int answer;
		vector<int> dp(cost.size(), 0);
		for(int i=0; i<cost.size(); i++) {
			if(i<=1) dp[i] = cost[i];
			else {
				dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
			}
		}
		answer = min(dp[dp.size()-1], dp[dp.size()-2]);
		return answer;
	}
};