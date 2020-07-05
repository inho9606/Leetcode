// https://leetcode.com/problems/flood-fill/submissions/
// DFS
// time: O(nm) space: O(nm)
// Runtime: 28 ms, faster than 13.65% of C++ online submissions for Flood Fill.
// Memory Usage: 14.2 MB, less than 52.66% of C++ online submissions for Flood Fill.
class Solution {
public:
	void dfs(vector<vector<int>>& image, vector<vector<bool>>& v, int i, int j, int c, int n) {
		if(i < 0 || i >= image.size()) return;
		if(j < 0 || j >= image[0].size()) return;
		if(v[i][j] == 1) return;
		if(image[i][j] != c) return;
		image[i][j] = n;
		v[i][j] = 1;
		dfs(image, v, i+1, j, c, n);
		dfs(image, v, i-1, j, c, n);
		dfs(image, v, i, j+1, c, n);
		dfs(image, v, i, j-1, c, n);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int c = image[sr][sc];
		vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), 0));
		dfs(image, v, sr, sc, c, newColor);
		return image;
	}
};