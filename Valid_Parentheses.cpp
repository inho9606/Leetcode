// time: O(n) n = the number of the given characters
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for(int i=0; i<s.length(); i++) {
			if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
			else {
				if(s[i] == ')' && st.empty() == 0 && st.top() == '(') st.pop();
				else if(s[i] == '}' && st.empty() == 0 && st.top() == '{') st.pop();
				else if(s[i] == ']' && st.empty() == 0 && st.top() == '[') st.pop();
				else return 0;
			}
		}
		if(st.empty() == 1) return 1;
		else return 0;
	}
};