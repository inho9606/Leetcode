// https://leetcode.com/problems/add-bold-tag-in-string/
// Maybe I did not understand specification well..
// Failed on hidden testcases, but I think it is not mentioned on the question..
class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		string answer="";
		vector<vector<int>> t, range;
		int c, u;
		for(int i=0; i<dict.size(); i++) {
		c= s.find(dict[i]);
			if(!(c < s.size())) continue;
		u = c+dict[i].size()-1;
			t.push_back({c, u});
		}
		sort(t.begin(), t.end());
		c=0;
		for(int i=0; i<t.size(); i++) {
			if(i==0) range.push_back(t[i]);
			else {
				if(range[range.size()-1][1]+1 >= t[i][0] && t[i][1] >= range[range.size()-1][1])
					range[range.size()-1][1] = t[i][1];
				else if(range[range.size()-1][1] >= t[i][1]) continue;
				else range.push_back(t[i]);
			}
		}
		for(int i=0; i<range.size(); i++) {
			if(c < range[i][0]) answer += s.substr(c, range[i][0]-c);
			answer += "<b>" + s.substr(range[i][0], range[i][1]-range[i][0]+1) + "</b>";
			c = range[i][1]+1;
		}
		if(c<s.size()) answer += s.substr(c);
		return answer;
	}
};