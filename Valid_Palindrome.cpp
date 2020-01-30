// https://leetcode.com/problems/valid-palindrome/submissions/
// time: O(n) memory: O(1)
// 왜인지 모르겠지만, string에서 소문자 비교연산이 안 된다. 2시간 가까이 문제 해결을 하지 못함. * 논리연산에 주의할것

class Solution {
public:
	bool isPalindrome(string s) {
		if(s.size() == 0) return 1;
		int n = s.size();
		int i=0, j=n-1;
		for(int i=0; i<s.size(); i++)
			s[i] = toupper(s[i]);
		while(i<=j) {
			if((s[i] < 48 || s[i] > 57 == 1) && (s[i] < 'A' || s[i] > 'Z' == 1)) { i++; continue; }
			if((s[j] < 48 || s[j] > 57 == 1) && (s[j] < 'A' || s[j] > 'Z' == 1)) { j--; continue; }
			if(s[i] != s[j]) return 0;
			i++;
			j--;
		}
		return 1;
	}
};