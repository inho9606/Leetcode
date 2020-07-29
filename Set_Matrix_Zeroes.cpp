// https://leetcode.com/problems/set-matrix-zeroes/submissions/
// Keep the last set zero index for followup.
// No enough time.. So just Trivial solution 
// time: O(nm) space: O(nm)
// Runtime: 24 ms, faster than 95.40% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.7 MB, less than 5.00% of C++ online submissions for Set Matrix Zeroes.
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.size()==0) return;
		int m=matrix.size(), n = matrix[0].size();
		vector<vector<int>> v(m, vector<int>(n, 0));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(matrix[i][j] == 0 && v[i][j] == 0) {
					v[i][j] = 1;
					for(int k=0; k<m; k++) {
						if(matrix[k][j] != 0) v[k][j] = 1;
						matrix[k][j] = 0;
					}
					for(int k=0; k<n; k++) {
						if(matrix[i][k] != 0) v[i][k] = 1;
						matrix[i][k] = 0;
					}

				}
			}
		}
	}
};