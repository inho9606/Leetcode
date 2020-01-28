// https://leetcode.com/problems/count-and-say/submissions/
// time: O(n^3/2)?
class Solution {
public:
	string countAndSay(int n) {
		int c;
		char num;
		string answer = "1";
		string t = "1";
		for(int i=2; i<=n; i++) {
			answer = "";
			num = t[0];
			c = 0;
			for(int j=0; j<t.size(); j++) {
				if(t[j] != num) {
					answer += c+48;
					answer += num;
					num = t[j];
					c = 0;
				}
				c++;
				if(j == t.size()-1) {
					answer += c+48;
					answer += num;
				}
			}
			t = answer;
		}
		return answer;
	}
};