// https://leetcode.com/problems/count-sorted-vowel-strings/submissions/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Sorted Vowel Strings.
// Memory Usage: 6.2 MB, less than 23.04% of C++ online submissions for Count Sorted Vowel Strings.
class Solution {
public:
	int countVowelStrings(int n) {
		vector<vector<int>> dp(n, vector<int>(5, 0));
		for(int i=0; i<5; i++)
			dp[0][i] = 5-i;
		for(int i=1; i<n; i++) {
			for(int j=0; j<5; j++) {
				for(int k=j; k<5; k++)
					dp[i][j] += dp[i-1][k];
			}
		}
	return dp[n-1][0];
	}
};
