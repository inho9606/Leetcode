// https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/submissions/
// I. The indexed 0 can be 2 if the next one is less than 4. Otherwise it can be 1.
// II. The indexed 1 can be 9 if the indexed 0 is grater than 2. Otherwise, it can be 4.
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Latest Time by Replacing Hidden Digits.
// Memory Usage: 5.9 MB, less than 61.70% of C++ online submissions for Latest Time by Replacing 
// time: O(n) space: O(1)
class Solution {
public:
	string maximumTime(string time) {
		for(int i=0; i<time.size(); i++) {
			if(time[i] == ':') continue;
			if(time[i] == '?') {
				if(i==0 && (time[1] < '4' || time[1] == '?')) time.replace(i, 1, "2");
				else if(i==0) time.replace(i, 1, "1");
				else if(i==1 && time[0] == '2') time.replace(i, 1, "3");
				else if(i==1) time.replace(i, 1, "9");
				else if(i==3) time.replace(i, 1, "5");
				else if(i==4) time.replace(i, 1, "9");
			}
		}
		return time;
	}
};