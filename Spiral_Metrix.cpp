// https://leetcode.com/problems/spiral-matrix/submissions/
// Idea: Traversal the most boundary, and do it again inside of done boundary, which means we should access indeices of (0, n), (1, n-1), (2, n-2)...
// I. For selected row, add all element from the first to the last. And for selected colum, Add all element between the most top and the most bottom of the colum.
// II. If the selected rows and colums cannot consist of a ractangle, then scan only from the last to the right, and from the top to the bottom.
// 전략: 가장 바깥쪽 사각형부터 안쪽으로 사각형을 좁히면서 그린다.
// 이때 가로 길이나 세로 길이가 1이면 사각형을 만들 수 없으므로, 이럴 때에는 가로나 세로로를 한 번만 확인한다. 예) 가로가 1이면 위에서 아래로 한 번만 스캔, 세로가 1이면 왼쪽에서 오른쪽 한 번만 스캔
// 중복된 부분을 피하기 위해 가로는 처음부터 끝까지, 세로는 양 끝점을 제외한 가운데 부분만 읽는다.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
// Memory Usage: 7 MB, less than 54.69% of C++ online submissions for Spiral Matrix.
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> answer;
		if(matrix.size() == 0) return answer;
		int m=matrix.size(), n=matrix[0].size();
		for(int i=0; i<=(n-1)/2; i++) {
			for(int j=i; m-1-i >= i && j<=n-1-i; j++)
				answer.push_back(matrix[i][j]);
			for(int j=i+1; j<m-1-i; j++)
				answer.push_back(matrix[j][n-1-i]);
			for(int j=n-1-i; m-1-i > i && j>=i; j--)
				answer.push_back(matrix[m-1-i][j]);
			for(int j=m-2-i; i < n-1-i && j>i; j--)
				answer.push_back(matrix[j][i]);
		}
		return answer;
	}
};