// https://leetcode.com/problems/longest-palindrome/submissions/
// Sum the number of letters appearing even numbers in the string S. And justp lus one for once if there are odd numbers of letters.
// time: O(n) space: O(c)
// Runtime: 4 ms, faster than 84.56% of C++ online submissions for Longest Palindrome.
// Memory Usage: 8.9 MB, less than 73.33% of C++ online submissions for Longest Palindrome.
class Solution {
public:
	int longestPalindrome(string s) {
		vector<int> counts(128,0);
		int answer=0;
		for(int i=0; i<s.size(); i++)
			counts[s[i]] += 1;
		for(int i=0; i<128; i++)
			if(counts[i] != 0) answer += (counts[i]/2)*2;
		for(int i=0; i<128; i++)
			if(counts[i] % 2 == 1) {
				answer += 1;
				break;
			}
		return answer;
	}
};