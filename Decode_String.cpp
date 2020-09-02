// https://leetcode.com/problems/decode-string/submissions/
// I. Record a string with inside of brackets([]) and a number which means how many times repeat inside of brackets.
// II. If there is another brackets inside of breacktes, then push the current string and times into stack. And try to record a new bracket.
// III. When the bracket is closed, complete the string by repeating string inside of the bracket n times.
// IV. If it is still inside of another bracket, then pop the stack and add completed string to the top of stack. Or, add the completed string to answer if it exited the bracket.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
// Memory Usage: 6.6 MB, less than 52.98% of C++ online submissions for Decode String.
class Solution {
public:
	string decodeString(string s) {
		string answer= "", t="", c;
		int n=0, times=0, opened=0;
		stack<pair<int,string>> st;
		for(int i=0; i<s.size(); i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				n *= 10;
				n += s[i]-48;
			}
			else if(s[i] == '[') {
				opened+=1;
				if(opened>0) st.push({times, t});
				times = n;
				n=0;
				t="";
			}
			else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				if(opened>0) t += s[i];
				else answer += s[i];
			}
			else if(s[i] == ']') {
				c=t;
				for(int cnt=1; cnt<times; cnt++) t += c;
				opened-=1;
				if(opened>0) {
					t = st.top().second + t;
					times = st.top().first;
					st.pop();
				}
				else if(opened==0) answer += t;
			}
		}
		return answer;
	}
};