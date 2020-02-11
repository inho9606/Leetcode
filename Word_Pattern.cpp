// https://leetcode.com/problems/word-pattern/submissions/
// Declare two amaps, one is to store pattern as key and word as value. Another one has word as key and pattern as value. Return false if the given word and pattern are different in two maps or the word or the pattern either is in the map.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 60.14% of C++ online submissions for Word Pattern.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Word Pattern.
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int i, j=0, k=0;
		unordered_map<char,string> m;
		unordered_map<string,char> m2;
		string word;
		for(i=0; i<pattern.size(); i++) {
			if(j>=str.size()) return 0;
			for(; j<str.size() && str[j] != ' '; j++) ;
			word = str.substr(k,j-k);
			if(m.count(pattern[i]) == 0 && m2.count(word) == 0) {
				m[pattern[i]] = word;
				m2[word] = pattern[i];
				}
			else if(m.count(pattern[i]) == 1 && m2.count(word) == 1) {
				if(m[pattern[i]] != word) return 0;
				if(m2[word] != pattern[i]) return 0;
			}
			else return 0;
			j += 1;
			k=j;
		}
		if(j <= str.size()) return 0;
		return 1;
	}
};