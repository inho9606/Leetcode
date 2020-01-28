// https://leetcode.com/problems/length-of-last-word/submissions/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int l = 0;
		for(int i=s.size()-1; i>=0; i--) {
			if(s[i] == ' ') {
				if(l == 0) continue;
				else break;
			}
			else l+=1;
		}
		return l;
	}
};