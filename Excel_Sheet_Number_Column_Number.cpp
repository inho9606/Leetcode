// https://leetcode.com/problems/excel-sheet-column-number/submissions/
// time: O(n) space: O(1) n is the size of a given string
// 26진수를 10진수로 바꾼다.
class Solution {
public:
	int titleToNumber(string s) {
		int answer=0;
		long long n=1;
		for(int i=s.size()-1; i>=0; i--) {
			answer += (s[i]-64)*n;
			// if(n <= INT_MAX/26) 
			n *= 26;
		}
		return answer;
	}
};