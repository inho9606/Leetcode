// https://leetcode.com/problems/repeated-substring-pattern/submissions/
// Idea: The first n characters and the last n characters should be same to need given requirement.
// time: O(n^2) space: O(n)
//Runtime: 400 ms, faster than 15.70% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 422 MB, less than 9.60% of C++ online submissions for Repeated Substring Pattern.
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		string t;
		for(int i=1; i<=s.size()/2; i++) {
			t = s.substr(0, i);
			for(int j=i; j<s.size(); j+=i) {
				if(j+i > s.size() || t != s.substr(j, i)) break;
				if(j+i == s.size()) return 1;
			}
		}
		return 0;
	}
};

/* MOck Interview
class Solution {
public:
	bool check(string &s, int i, int j, int n) {
		if(s.substr(i, j) == s.substr(n-j, j)) {
			for(i=i+j; i<n-j; i+=j) {
				if(s.substr(i, j) != s.substr(n-j, j)) return 0;
			}
			return 1;
		}
		else return 0;
	}
	bool repeatedSubstringPattern(string s) {
		string t;
		for(int i=1; i<=s.size()/2; i++) {
			if(check(s, 0, i, s.size()) == 1) return 1;
		}
		return 0;
	}
};
*/