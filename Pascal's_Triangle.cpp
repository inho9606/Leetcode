// https://leetcode.com/problems/pascals-triangle/submissions/
/ time: O(n^2) memory: O(n^2/2)
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int> > answer;
		vector<int> t(numRows);
		for(int i=1; i<=numRows; i++) {
			t.clear();
			for(int j=0; j<i; j++) {
				if(j ==0 || j == i-1) t.push_back(1);
				else t.push_back(answer[i-2][j-1] + answer[i-2][j]);
			}
			answer.push_back(t);
		}
		return answer;
	}
};