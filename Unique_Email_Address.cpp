// https://leetcode.com/problems/unique-email-addresses/submissions/
// I. On local part of each given email, ignore '.' and all characters after '+'.
// II. From '@' to the end, copy domain part.
// III. To avoid repeated address, use set datastructure.
// time: O(n) space: O(n)
// Runtime: 52 ms, faster than 74.14% of C++ online submissions for Unique Email Addresses.
// Memory Usage: 13 MB, less than 93.75% of C++ online submissions for Unique Email Addresses.
class Solution {
public:
	int numUniqueEmails(vector<string>& email) {
		unordered_set<string> s;
		string t;
		int ignore;
		for(int i=0; i<email.size(); i++) {
			t="";
			ignore=0;
			for(int j=0; j<email[i].size(); j++) {
				if(email[i][j] == '@') { t += email[i].substr(j); break; }
				if(ignore == 1 || email[i][j] == '.') continue;
				if(email[i][j] == '+') ignore = 1;
				else t += email[i][j];
			}
			s.insert(t);
		}
		return s.size();
	}
};