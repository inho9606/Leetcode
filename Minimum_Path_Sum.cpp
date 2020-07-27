// https://leetcode.com/problems/minimum-path-sum/
// Record the minimum sum on new grid. The number of each cell is minmum of it's up + itself or it's right one + itself.
// It's like DP solution
// time: O(nm), space: O(nm)
// Runtime: 16 ms, faster than 95.92% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 10.1 MB, less than 37.01% of C++ online submissions for Minimum Path Sum.
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if(grid.size() == 0) return 0;
		vector<vector<int>> f(grid.size(), vector<int>(grid[0].size()));
		for(int i=0; i<grid.size(); i++) {
			for(int j=0; j<grid[0].size(); j++) {
				if(i==0 && j==0) f[i][j] = grid[i][j];
				else if(i==0 && j!=0) f[i][j] = f[i][j-1]+grid[i][j];
				else if(i!=0 && j==0) f[i][j] = f[i-1][j]+grid[i][j];
			else f[i][j] = min(f[i-1][j]+grid[i][j], f[i][j-1]+grid[i][j]);
			}
		}
		return f[f.size()-1][f[0].size()-1];
	}
};