// https://leetcode.com/problems/single-row-keyboard/submissions/
// I. Record the value and index into map.
// II. For each character in word, add the distance between the current character and the next character.
// time: O(n) space: O(n)
// Runtime: 16 ms, faster than 64.82% of C++ online submissions for Single-Row Keyboard.
// Memory Usage: 7.2 MB, less than 14.32% of C++ online submissions for Single-Row Keyboard.
class Solution {
public:
	int calculateTime(string keyboard, string word) {
		int answer=0, i=0;
		unordered_map<char,int> m;
		for(int j=0; j<keyboard.size(); j++)
			m[keyboard[j]] = j;
		for(int j=0; j<word.size(); j++) {
			answer += abs(m[word[j]] - i);
			i = m[word[j]];
		}
		return answer;
	}
};