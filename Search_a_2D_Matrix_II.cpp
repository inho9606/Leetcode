// https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/
// I. At the most rightbottom, all left elements and all up elements are less than the current number. So, compare all elements from the most rightbottom.
// II. For selected point, find the target using binary search on the left cols and up rows.
// time: O(min(n,m)*(logm+logn)) space: O(c) m is the number of row, and m is the number of col.
// Runtime: 316 ms, faster than 18.37% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 10.7 MB, less than 72.61% of C++ online submissions for Search a 2D Matrix II.
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.size() == 0) return 0;
		int i=matrix.size()-1, j=matrix[0].size()-1, s, e, m;
		while(i>=0 && j>=0) {
			s=0; e=i;
			while(s<=e) {
				m=(s+e)/2;
				if(matrix[m][j] == target) return 1;
				else if(matrix[m][j] > target) e = m-1;
				else s = m+1;
			}
			s=0; e=j;
			while(s<=e) {
				m=(s+e)/2;
				if(matrix[i][m] == target) return 1;
				else if(matrix[i][m] > target) e = m-1;
				else s = m+1;
			}
			i--;
			j--;
		}
		return 0;
	}
};

/*
* O(n+m) from discuss board most voted solution.
* Start searching from the most top right element. 
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int m = matrix.size();
if (m == 0) return false;
int n = matrix[0].size();
int i = 0, j = n - 1;
while (i < m && j >= 0) {
if (matrix[i][j] == target)
return true;
else if (matrix[i][j] > target) {
j--;
} else 
i++;
}
return false;
}
};
*/