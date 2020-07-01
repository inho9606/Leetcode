// https://leetcode.com/problems/longest-palindromic-substring/submissions/
// I. Initialize n*n table with zero, and (i,i) with one.
// II. Check if there are same values from the last to the first. If so, then update table with (i+1,j-1) +2, which means the extended length of palindrome inside i and j.
// III. If the updated length is longer than previous palindrome, update substring.
// time: O(n^2) space: O(n^2)
// Runtime: 284 ms, faster than 26.40% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 192.2 MB, less than 5.04% of C++ online submissions for Longest Palindromic Substring.
class Solution {
public:
	string longestPalindrome(string s) {
		string answer="";
		vector<vector<int>> t(s.size(), vector<int>(s.size(), 0));
		for(int i=0; i<s.size(); i++) {
			t[i][i] = 1;
			answer = s[i];
		}
		for(int i=s.size()-1; i>=0; i--) {
			for(int j=i+1; j<s.size(); j++) {
				if(s[i] == s[j] && (t[i+1][j-1] > 0 || j-i == 1)) {
					t[i][j] = t[i+1][j-1]+2;
					if(t[i][j] > answer.size()) answer = s.substr(i, t[i][j]);
				}
			}
		}
		return answer;
	}
};