// https://leetcode.com/problems/valid-palindrome-ii/submissions/
// time: O(n^2) space: O(1)
// Runtime: 276 ms, faster than 5.97% of C++ online submissions for Valid Palindrome II.
// Memory Usage: 19.5 MB, less than 100.00% of C++ online submissions for Valid Palindrome II.
class Solution {
public:
	bool check(string& s, int i, int j, int cnt) {
		while(i < j) {
			if(s[i] == s[j]) {
				i++;
				j--;
			}
			else {
				if(cnt == 1) return 0;
				return check(s, i+1, j, cnt+1) || check(s, i, j-1, cnt+1);
			}
		}
		return 1;
	}
	bool validPalindrome(string s) {
		return check(s, 0, s.size()-1, 0);
	}
};