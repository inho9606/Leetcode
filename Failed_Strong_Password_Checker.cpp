// Strong Password Checker Hard
// 30 / 42 Testcases Passed
class Solution {
public:
	int strongPasswordChecker(string s) {
		int answer=0, deletion=0, replace=0, insertion=0, r=0, l=0, u=0, d=0;
		if(s.size() < 6) return 6-s.size();
		for(int i=0; i<s.size(); i++) {
			if(s[i] >= '0' && s[i] <= '9') d+=1;
			else if(s[i] >= 'a' && s[i] <= 'z') l+=1;
			else if(s[i] >= 'A' && s[i] <= 'Z') u+=1;
		}
		for(int i=0; i<s.size(); i++) {
			if(i==0 || s[i] == s[i-1]) {
				r+=1;
				if(r==3) {
					if(u==0) u+=1;
					else if(l==0) l+=1;
					else if(d==0) d+=1;
					answer+=1;
					r=0;
				}
			}
			else if(s[i] != s[i-1]) r=1;
		}
		if(u==0) answer+=1;
		if(l==0) answer+=1;
		if(d==0) answer+=1;
		return answer;
	}
};