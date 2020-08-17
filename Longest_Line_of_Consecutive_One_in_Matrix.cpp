// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/submissions/
// Check only right, down, rightdown, and leftdown.
// Update the distance from left to right, from up to down, from leftup to rightdown, and from rightup to leftdown using DP idea.
// time: O(n^2) space: O(n^2)
// Runtime: 184 ms, faster than 49.16% of C++ online submissions for Longest Line of Consecutive One in Matrix.
// Memory Usage: 39.4 MB, less than 35.66% of C++ online submissions for Longest Line of Consecutive One in Matrix.
class Solution {
public:
	int longestLine(vector<vector<int>>& M) {
		if(M.size()==0) return 0;
		int answer=0;
		vector<vector<vector<int>>> d(M.size(), vector<vector<int>>(M[0].size(), vector<int>(4, 0)));
		for(int i=0; i<M.size(); i++) {
			for(int j=0; j<M[i].size(); j++) {
				if(M[i][j] == 1) {
					d[i][j] = {1,1,1,1};
					if(i!=0 && M[i-1][j] == 1) d[i][j][0] = d[i-1][j][0] + 1;
					if(j!=0 && M[i][j-1] == 1) d[i][j][1] = d[i][j-1][1] + 1;
					if(i!=0 && j!=0 && M[i-1][j-1] == 1) d[i][j][2] = d[i-1][j-1][2] + 1;
					if(i!=0 && j!=M[i].size()-1 && M[i-1][j+1] == 1) d[i][j][3] = d[i-1][j+1][3] + 1;
					answer = max(answer, max(d[i][j][0], max(d[i][j][1], max(d[i][j][2], d[i][j][3]))));
				}
			}
		}
		return answer;
	}
};