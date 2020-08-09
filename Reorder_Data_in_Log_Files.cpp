// https://leetcode.com/problems/reorder-data-in-log-files/submissions/
// I. Recognize if each log is digit or letter.
// II. If the log is digit, then push the log into digits vector because digit logs should be ordered as given.
// III. If the log is letter, then insert it into map. Map has the log contents as it's key, and identifier as it's value. Value of the map should be set because same logs with different identifier can exist. Map and set will automatically order logs.
// IV. Push answer vector from map, and push digits.
// Time: O(n+logn) space: O(n)
// Runtime: 20 ms, faster than 78.40% of C++ online submissions for Reorder Data in Log Files.
// Memory Usage: 11 MB, less than 84.88% of C++ online submissions for Reorder Data in Log Files.
class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> answer, digits;
		map<string,set<string>> m;
		int i, j;
		string t;
		for(i=0; i<logs.size(); i++) {
			for(j=0; logs[i][j] != ' '; j++) ;
			if(logs[i][j+1] >= '0' && logs[i][j+1] <= '9')
				digits.push_back(logs[i]);
			else
				m[logs[i].substr(j+1)].insert(logs[i].substr(0, j));
		}
		for(auto ptr=m.begin(); ptr!=m.end(); ptr++) {
			for(auto ptr2=ptr->second.begin(); ptr2 != ptr->second.end(); ptr2++) {
				t = *ptr2 + " " + ptr->first;
				answer.push_back(t);
			}
		}
		for(int i=0; i<digits.size(); i++)
			answer.push_back(digits[i]);
		return answer;
	}
};