// https://leetcode.com/problems/shortest-way-to-form-string/submissions/
// I. Check if target string has any character that source does not have. If so, return -1 because it means target cannot be constructed by source.
// II. Compare two strings source and target. If the characters of those are same, then move two points to the next character. If it is not same, then move only a pointer of source to the next character.
// III. If any of pointers reach out the last character of each strings, then it means one subsequence were made. So initialize subsequence string, which means pointer should be index 0.
// time: O(nm) space: O(m) n is the length of target, and m is the length of source.
// Runtime: 4 ms, faster than 96.00% of C++ online submissions for Shortest Way to Form String.
// Memory Usage: 6.5 MB, less than 69.89% of C++ online submissions for Shortest Way to Form String.
class Solution {
public:
	int shortestWay(string source, string target) {
		int answer=0, i, j;
		unordered_set<char> t;
		for(i=0; i<source.size(); i++)
			s.insert(source[i]);
		for(i=0; i<target.size(); i++) {
			if(s.count(target[i]) == 0) return -1;
		}
		for(i=0, j=0; i<source.size() && j<target.size(); ) {
			if(source[i] == target[j]) { i++; j++; }
			else i++;
			if(i==source.size() || j==target.size()) {
				answer += 1;
			i=0;
			}
		}
		return answer;
	}
};