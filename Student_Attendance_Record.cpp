// Counts 'A' and 'L'. Return false if 'A' appears twice or 'L' appears three times continueously.
// time: O(n) space: O(1)
// Runtime: 0 ms
// Memory Usage: 8.4 MB
// 8 mins
class Solution {
public:
	bool checkRecord(string s) {
		int a=0, l=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i] == 'A') { l = 0; a++; }
			else if(s[i] == 'L') l++;
			else l = 0;
			if(a > 1 || l > 2) return 0;
		}
		return 1;
	}
};