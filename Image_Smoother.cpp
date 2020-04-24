// https://leetcode.com/problems/image-smoother/submissions/
// I. Simulation Implementation with Brute Force
// time: O(nm) space: O(nm) nm is the size of given 2D array
// Runtime: 140 ms, faster than 92.29% of C++ online submissions for Image Smoother.
// Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for Image Smoother.
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> answer(M.size(), vector<int>(M[0].size(), 0));
		int gray, cells;
		for(int i=0; i<M.size(); i++) {
			for(int j=0; j<M[i].size(); j++) {
				cells = 1;
				gray = M[i][j];
				if(j > 0) {
					gray += M[i][j-1];
					cells += 1;
					if(i < M.size()-1) {
						gray += M[i+1][j-1];
						cells+=1;
					}
				}
				if(j < M[i].size()-1) {
					gray += M[i][j+1];
					cells += 1;
					if(i > 0) {
						gray += M[i-1][j+1];
						cells += 1;
					}
				}
				if(i > 0) {
					gray += M[i-1][j];
					cells += 1;
					if(j > 0) {
						gray += M[i-1][j-1];
						cells+=1;
					}
				}
				if(i < M.size()-1) {
					gray += M[i+1][j];
					cells += 1;
					if(j < M[i].size()-1) {
						gray += M[i+1][j+1];
						cells += 1;
					}
				}
				answer[i][j] = gray/cells;
			}
		}
		return answer;
	}
};