// https://leetcode.com/problems/rotate-image/submissions/
// I. From the first element to the previous one before the last one, rotate each element to 90 degree.
// II. After doing I on a rwo, it becomes rotated image around border. Then repeat rotating inside border.
// time: O(n), space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 7.2 MB, less than 53.55% of C++ online submissions for Rotate Image.
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int t, n=matrix.size();
		for(int i=0; i < n/2; i++) {
			for(int j=i; j<n-1-i; j++) {
				t = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][i];
				matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
				matrix[j][n-1-i] = t;
			}
		}
	}
};