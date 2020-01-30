// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
// time: O(n) memory: O(1)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() == 0) return 0;
		int answer = 0, m=INT_MAX;
		for(int i=0; i<prices.size(); i++) {
			if(prices[i] < m) m = prices[i];
			else if(prices[i] - m > answer) answer = prices[i] - m;
		}
		return answer;
	}
};