// https://leetcode.com/problems/search-a-2d-matrix/submissions/
// I. Binary Search on columns. Find the row that may have the given target.
// II. On  found row, try to find the target with Binary search.
// time: O(log(mn)) space: O(1) m is the number of column n is the number of rows.
// Runtime: 16 ms, faster than 84.04% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 11.4 MB, less than 60.43% of C++ online submissions for Search a 2D Matrix.
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.size() == 0 || matrix[0].size()==0) return 0;
		int s=0, e=matrix.size()-1, m, row=-1;
		while(s<=e) {
			m = (s+e)/2;
			if(matrix[m][0] == target) return 1;
			else if(matrix[m][0] > target) e = m-1;
			else if(matrix[m][0] < target && matrix[m][matrix[m].size()-1] >= target) { row = m; break; }
			else if(matrix[m][0] < target) s = m+1;
		}
		if(row == -1) return 0;
		s = 0; e = matrix[row].size()-1;
		while(s<=e) {
			m = (s+e)/2;
			if(matrix[row][m] == target) return 1;
			else if(matrix[row][m] > target) e = m-1;
			else s = m+1;
		}
		return 0;
	}
};