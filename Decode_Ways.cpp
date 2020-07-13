// https://leetcode.com/problems/decode-ways/submissions/
// I. From the last, check if it can be decoded or not (26)
// Refered to discuss board..

class Solution {
public:
	int numDecodings(string s) {
		int t1=1, t2=0, answer;
		for(int i=s.size()-1; i>=0; i--) {
			answer = 0;
				if(s[i] != '0') {
					answer=t1;
				if(i<s.size()-1) {
					if((s[i]-48)*10 + (s[i+1]-48) <= 26) answer += t2;
				}
			}
		t2 = t1;
		t1 = answer;
		}
		return answer;
	}
};