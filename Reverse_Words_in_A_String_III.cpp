// https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/
// I. Find the first whitespace from the first character in each words.
// II. Reverse the characters between the first character and the last one before the whitespace in the word.
// III. Check the next word
// time: O(n) space: O(1)
// Runtime: 20 ms, faster than 85.65% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Reverse Words in a String III.
class Solution {
public:
	string reverseWords(string s) {
		int i, j;
		char t;
		for(i=0; i<s.size(); i++) {
			for(j=i; j<s.size() && s[j] != ' '; j++) ;
			for(int k=i; k<=(i+j-1)/2; k++) {
				t = s[k];
				s[k] = s[j-1-k+i];
				s[j-1-k+i] = t;
			}
		i = j;
		}
		return s;
	}
};