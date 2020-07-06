// https://leetcode.com/problems/generate-parentheses/submissions/
// I. We can decide to open or close parenthesis according to the number of previous parentheses.
// II. If ther are parentheses left, then open it. If there are parentheses that are not closed, then close it recursively.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 87.68% of C++ online submissions for Generate Parentheses.
// Memory Usage: 16.4 MB, less than 16.20% of C++ online submissions for Generate Parentheses.
class Solution {
public:
	void make(vector<string>& a, string t, int open, int close, int n) {
		if(open>n) return;
		if(close == n) {
			a.push_back(t);
			return;
		}
		if(open-close>0) make(a, t+")", open, close+1, n);
		make(a, t+"(", open+1, close, n);
	}
	vector<string> generateParenthesis(int n) {
		vector<string> answer;
		string t = "";
		make(answer, t, 0, 0, n);
		return answer;
	}
};