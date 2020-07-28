// https://leetcode.com/problems/unique-paths-ii/submissions/
// I. Make new table to record how many pathes there are until at the point from the top-left cell.
// II. If the cell on the given grid is 0, then update table on the same spot. Updating is to add previous values from the right cell or up cell.
// Note: Return 0 if the given grid does not exist or the start point is 1.
// time: O(nm) space: O(nm)
// Runtime: 4 ms, faster than 96.86% of C++ online submissions for Unique Paths II.
// Memory Usage: 8 MB, less than 28.48% of C++ online submissions for Unique Paths II.
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid.size() == 0 || obstacleGrid[0][0] == 1) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> table(m, vector<int>(n, 0));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(i==0 && j==0) table[i][j] = 1;
				if(j!=0 && obstacleGrid[i][j] == 0) table[i][j] += table[i][j-1];
				if(i!=0 && obstacleGrid[i][j] == 0) table[i][j] += table[i-1][j];
			}
		}
		return table[m-1][n-1];
	}
};