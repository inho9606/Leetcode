// https://leetcode.com/problems/valid-palindrome/submissions/
// time: O(n) memory: O(1)
// ������ �𸣰�����, string���� �ҹ��� �񱳿����� �� �ȴ�. 2�ð� ������ ���� �ذ��� ���� ����. * �����꿡 �����Ұ�

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