// https://leetcode.com/problems/pascals-triangle-ii/submissions/
// time: O(n) memory: O(n)
// Couldn't find the clue for solution by myself..
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> answer;
		answer.push_back(1);
		if(rowIndex == 0) return answer;
		else {
			for(int i=0; i<rowIndex; i++) {
				for(int j=answer.size()-1; j>0; j--)
					answer[j] += answer[j-1];
				answer.push_back(1);
			}
		}
		return answer;
	}
};