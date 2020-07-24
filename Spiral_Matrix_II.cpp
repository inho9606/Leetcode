// https://leetcode.com/problems/spiral-matrix-ii/submissions/
// I. Basic idea is same as spiral matrix I. From the most out of boundary, which is the biggest rectangle, Fill the boundary with increasing numbers.
// II. After completing the boundary, repeat it on the inner rectangle.until the number is equal to twice of given n.
// time: O(n^2) space: O(n^2)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 6.5 MB, less than 78.32% of C++ online submissions for Spiral Matrix II.
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> answer(n, vector<int>(n));
		int x = 1;
		for(int i=0; x<=n*n && i<=(n-1)/2; i++) {
			for(int j=i; x<=n*n && j<n-i; j++)
				answer[i][j] = x++;
			for(int j=i+1; x<=n*n && j<n-1-i; j++)
				answer[j][n-1-i] = x++;
			for(int j=n-1-i; x<=n*n && j>=i; j--)
				answer[n-1-i][j] = x++;
			for(int j=n-2-i; j>i; j--)
				answer[j][i] = x++;
		}
		return answer;
	}
};