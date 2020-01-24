// time: O(nl(n is the number of given words, and l is the everage length of the words
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
	if(strs.size() == 0) return "";
	string answer = strs[0];
	for(int i=1; i<strs.size(); i++) {
		if(strs[i].size() == 0) answer = "";
		if(answer == "") break;
		for(int j=0; j<strs[i].size(); j++) {
			if(answer[j] != strs[i][j]) {
				answer = answer.substr(0, j);
				break;
			}
			if(j == answer.size()-1 || j == strs[i].size()-1) { answer = answer.substr(0, j+1); break; }
		}
	}
	return answer;
	}
};