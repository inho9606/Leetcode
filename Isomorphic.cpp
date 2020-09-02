// https://leetcode.com/problems/isomorphic-strings/submissions/
// I. Each character in both s and t should be marked with number.
// II. If the marked number on each characters in s and t are different, then return false.
// time: O(n) space: O(1)
// Runtime: 8 ms, faster than 99.79% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 7.2 MB, less than 40.41% of C++ online submissions for Isomorphic Strings.
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int> mapping1(128, -1), mapping2(128, -1);
		for(int i=0; i<s.size(); i++) {
			if(mapping1[s[i]] != mapping2[t[i]]) return 0;
			mapping1[s[i]] = i;
			mapping2[t[i]] = i;
		}
		return 1;
	}
};