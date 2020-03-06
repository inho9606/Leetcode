// https://leetcode.com/problems/longest-uncommon-subsequence-i/submissions/
// I misunderstood this problem. Came up with this solution after brute force simulation implementation.
// I. Compare the length of two strings.
// II. If the length is different, Return the longer length because I have to return the longest uncommon subsequence. Shorter one does not contain the rest of the longer string.
// III. If the length is same and the contents are also same, then return a size of them.
// IV. Otherwise, return -1.
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Uncommon Subsequence I .
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Longest Uncommon Subsequence I 
class Solution {
public:
	int findLUSlength(string a, string b) {
		if(a.size() > b.size()) return a.size();
		if(b.size() > a.size()) return b.size();
		if(a.size() == b.size() && a!=b) return a.size();
		return -1;
	}
};