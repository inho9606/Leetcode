// https://leetcode.com/problems/reverse-words-in-a-string/submissions/
// Store each word using stack.
// I. Find the first non-whitespace character.
// II. From I, find the next non-whitespace.
// III. Keep the characters between I and II in stack. Repeat it until all characters are scanned.
// IV. Add words in stack to answer string.
// time: O(n) space: O(n)
// Runtime: 20 ms, faster than 70.76% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 8.8 MB, less than 39.47% of C++ online submissions for Reverse Words in a String.
class Solution {
public:
	string reverseWords(string s) {
		string answer = "";
		stack<string> st;
		int i, j;
		for(i=0; i<s.size() && s[i] == ' '; i++) ;
		for(; i<s.size(); i++) {
			for(j=i; j<s.size() && s[j] != ' '; j++) ;
			st.push(s.substr(i, j-i));
			for(; j<s.size() && s[j] == ' '; j++) ;
			i = j-1;
		}
		while(st.empty() == 0) {
			answer += st.top() + " ";
			st.pop();
		}
		if(answer.size() != 0) answer.pop_back();
		return answer;
	}
};