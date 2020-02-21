// https://leetcode.com/problems/number-of-segments-in-a-string/submissions/
// Count the words by the whitespace.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Segments in a String.
// Memory Usage: 8.4 MB, less than 62.50% of C++ online submissions for Number of Segments in a String.
class Solution {
public:
	int countSegments(string s) {
		if(s.size() == 0) return 0;
		int answer = 0, ch=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i] != ' ') ch = 1;
			else {
				if(ch == 1) { answer += 1; ch = 0; }
			}
		}
		if(s[s.size()-1] != ' ') answer+=1;
		return answer;
	}
};