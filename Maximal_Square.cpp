// https://leetcode.com/problems/maximal-square/submissions/
// I. Get the maximum square area on each index.
// time: O(nm*nm) space: O(c) n is the number of given row, and m is the number of given col. When every part is '1', then it's the worst case.
// Runtime: 48 ms, faster than 64.74% of C++ online submissions for Maximal Square.
// Memory Usage: 11.1 MB, less than 82.47% of C++ online submissions for Maximal Square.
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int answer=0, row, col, area, flag;
		for(int i=0; i<matrix.size(); i++) {
			for(int j=0; j<matrix[i].size(); j++) {
				row=0; col=0; flag=0, area=0;
				for(int k=j; k<matrix[i].size(); k++) {
					if(matrix[i][k] == '0') break;
					else {
						col += 1;
						for(int l=i; l<i+col-1; l++) {
							if(l>=matrix.size()) { flag = 1; break; }
							if(matrix[l][k] == '0') { flag=1; break; }
						}
						if(flag == 1) break;
						for(int l=k-col+1; l<=k; l++) {
							if(i+col-1 >= matrix.size()) { flag = 1; break; }
							if(matrix[i+col-1][l] == '0') { flag = 1; break; }
						}
						if(flag == 1) break;
						area = col*col;
						if(area>answer) answer = area;
					}
				}
			}
		}
		return answer;
	}
};