// https://leetcode.com/problems/remove-duplicate-letters/submissions/
class Solution {
public:
	string removeDuplicateLetters(string s) {
		string answer = "", tmp = "";
		int flag;
		for(int i=0; i<s.size(); i++) {
			flag = -1;
			for(int j=0; j<tmp.size(); j++) {
				if(tmp[j] == s[i]) flag = j;
				if(flag >= 0 && tmp[j] < s[i]) {
					tmp.erase(flag, 1);
					tmp += s[i];
					break;
				}
			}
			if(flag == -1) tmp += s[i];
			if(tmp.size() > answer.size()) answer = tmp;
			else if(answer.size() == tmp.size()) {
				for(int i=0; i<tmp.size(); i++) {
					if(answer[i] < tmp[i]) break;
					if(tmp[i] < answer[i]) {
						answer = tmp;
					break;
					}
				}
			}
		}
		return answer;
	}
};