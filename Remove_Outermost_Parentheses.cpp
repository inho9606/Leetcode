// https://leetcode.com/problems/remove-outermost-parentheses/submissions/
// I. Find each group by counting (). If the number of opened parentheses is zero, then it is one group.
// II. From each group, pop the first character and the last character, which are '(' and ')'. And add it to new string.
// time: O(n) space: O(n)
// Runtime: 8 ms, faster than 82.00% of C++ online submissions for Remove Outermost Parentheses.
// Memory Usage: 6.9 MB, less than 45.84% of C++ online submissions for Remove Outermost Parentheses.
class Solution {
public:
	string removeOuterParentheses(string S) {
		string answer = "";
		int d=0, cnt=0;
		for(int i=0; i<S.size(); i++) {
			if(S[i] == '(') cnt++;
			else if(S[i] == ')') {
				cnt--;
				if(cnt==0) {
					answer += S.substr(d+1, i-1-d);
					d=i+1;
				}
			}
		}
		return answer;
	}
};