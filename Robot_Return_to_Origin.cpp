// https://leetcode.com/problems/robot-return-to-origin/submissions/
// I. Count U and D, and L and R. The number of the pairs of those is zero, then return true.
// time: O(n) space: O(1)
// Runtime: 16 ms, faster than 83.88% of C++ online submissions for Robot Return to Origin.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Robot Return to Origin.
class Solution {
public:
	bool judgeCircle(string moves) {
		int row=0, col=0;
		for(int i=0; i<moves.size(); i++) {
			if(moves[i] == 'R') col+=1;
			else if(moves[i] == 'L') col-=1;
			else if(moves[i] == 'U') row-=1;
			else if(moves[i] == 'D') row+=1;
		}
		if(row==0 && col==0) return 1;
		return 0;
	}
};