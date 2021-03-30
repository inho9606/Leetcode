// https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/
// Runtime: 20 ms, faster than 65.47% of C++ online submissions for Partition Array for Maximum Sum.
// Memory Usage: 8.4 MB, less than 81.34% of C++ online submissions for Partition Array for Maximum Sum.
// time: O(n^2) when k is n, space: O(n)
class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int kMax, kCnt;
		vector<int> dp(arr.size(), 0);
		for (int i=0; i<arr.size(); i++) {
			kMax = arr[i];
			kCnt=0;
			for (int j=i; j>=0 && j>=i-k+1; j--) {
			if(arr[j] == kMax && j != i) break;
				if(arr[j] > kMax) kMax = arr[j];
				kCnt+=1;
				if(i-kCnt >= 0) dp[i] = max(dp[i], dp[i-kCnt]+kCnt*kMax);
				else dp[i] = max(dp[i], kCnt*kMax);
			}
		}
		return dp[dp.size()-1];
	}
};

// 1 30 45 54 56 72 84
// 1 8 12 20 29 32 40 48 65 74