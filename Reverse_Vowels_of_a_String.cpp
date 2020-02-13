// https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/
// from the first and the last, check if each character is a vowel or not. and Swap two vowels.
// time: O(n) space: O(1)
// Runtime: 8 ms, faster than 92.88% of C++ online submissions for Reverse Vowels of a String.
// Memory Usage: 10 MB, less than 87.88% of C++ online submissions for Reverse Vowels of a String.
class Solution {
public:
	string reverseVowels(string s) {
		int i=0, j=s.size()-1, temp;
		while(i<j) {
			for(; i<s.size(); i++) {
				if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I') break;
			}
			for(; j>=0; j--) {
				if(s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'u' || s[j] == 'i' || s[j] == 'A' || s[j] == 'E' || s[j] == 'O' || s[j] == 'U' || s[j] == 'I') break;
			}
			if(i>=j) break;
			temp = s[j];
			s[j] = s[i];
			s[i] = temp;
			i++;
			j--;
		}
		return s;
	}
};