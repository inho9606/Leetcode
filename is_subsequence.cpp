// https://leetcode.com/problems/is-subsequence/submissions/
// Brute Force, just check characters and their indices in T. I have no idea for binary search or dynamic programming  ways..
// time: O(n) space: O(1)
// Runtime: 60 ms, faster than 87.65% of C++ online submissions for Is Subsequence.
// Memory Usage: 17.1 MB, less than 66.67% of C++ online submissions for Is Subsequence.


class Solution {
public:
    bool isSubsequence(string s, string t) {
		if(s.size() > t.size()) return 0;
		int i=0, j=0;
		while(i<s.size() && j<t.size()) {
			if(s[i] == t[j]) i++;
			j++;
		}
		if(s.size() > 0 && i < s.size()) return 0;
		return 1;
	}
};