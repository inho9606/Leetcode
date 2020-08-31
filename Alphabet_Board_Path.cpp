// https://leetcode.com/problems/alphabet-board-path/submissions/
// I. Board has 5 rows and 5 cols. The character/5 is row, and character%5 is col.
// II. Get the location of target character, and compare it with the current position(r,c). And move it.
// III. If the character is 'z', then move the current position to the mostleft and the mostbottom.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Alphabet Board Path.
// Memory Usage: 6.2 MB, less than 65.23% of C++ online submissions for Alphabet Board Path.
class Solution {
public:
	string alphabetBoardPath(string target) {
		string answer= "";
		int r=0, c=0, x, y;
		for(int i=0; i<target.size(); i++) {
			if(target[i] == 'z') {
				for(; c>0; c--) answer += 'L';
				for(; r<5; r++) answer += 'D';
			}
			x = (target[i]-'a')/5;
			y = (target[i]-'a')%5;
			if(r-x < 0) {
				for(; r<x; r++) answer += 'D';
			}
			else if(r-x > 0) {
				for(; r>x; r--) answer += 'U';
			}
			if(c-y < 0) {
				for(; c<y; c++) answer += 'R';
			}
			else if(c-y > 0) {
				for(; c>y; c--) answer += 'L';
			}
			answer += '!';
		}
		return answer;
	}
};