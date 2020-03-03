// Using Dynamic Programming. m*n = (m-1)+(n-1)
// time: O(n*m) space: O(n*m)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Unique Paths.
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int> > dp(m, vector<int>(n, 1));
		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++)
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
		return dp[m-1][n-1];
	}
};