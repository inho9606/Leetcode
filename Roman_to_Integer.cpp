// https://leetcode.com/problems/roman-to-integer/submissions/
// time: O(n) n is the number of given characters
class Solution {
public:
	int romanToInt(string s) {
		int n=0;
		for(int i=s.size()-1; i>=0; i--) {
			if(s[i] == 'I') {
				if(i != s.size()-1 && (s[i+1] == 'V' || s[i+1] == 'X')) n -= 1;
				else n += 1;
			}
			else if(s[i] == 'V') n += 5;
			else if(s[i] == 'X') {
				if(i != s.size()-1 && (s[i+1] == 'L' || s[i+1] == 'C')) n -= 10;
				else n += 10;
			}
			else if(s[i] == 'L') n += 50;
			else if(s[i] == 'C') {
				if(i != s.size()-1 && (s[i+1] == 'D' || s[i+1] == 'M')) n -= 100;
				else n += 100;
			}
			else if(s[i] == 'D') n += 500;
			else if(s[i] == 'M') n += 1000;
		}
		return n;
	}
};