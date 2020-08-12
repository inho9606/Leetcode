// https://leetcode.com/problems/next-closest-time/submissions/
// I. Valid time format consists of four digits, so store those in vector with 4 size.
// II. The first digit can be from 0 through 2 since it is prefix of time part, and the third digit can be from 0 through 5 since it is the prefix of minutes. The rest can be from 0 through 9.
// III. The postfix of time part, which is the second digit, should be less than 5 when the prefix, the first digit, is 2 since we have 24 hours system.
// IV. From the last digit, find the greater digit among candidates than the current digit. Candidates compose of the given time. If there is no grater number with range of valid number, then change it the smallest number among valid digits. If found the greater digit, then return the new time.
// time: O(1) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Closest Time.
// Memory Usage: 5.8 MB, less than 92.11% of C++ online submissions for Next Closest Time.	
class Solution {
public:
	string nextClosestTime(string time) {
		string answer = time;
		vector<char> d;
		int done=0, j;
		for(int i=0; i<time.size(); i++) {
			if(time[i] == ':') continue;
			d.push_back(time[i]);
		}
		sort(d.begin(), d.end());
		for(int i=answer.size()-1; i>=0; i--) {
			if(answer[i] == ':') continue;
			done = 0;
			for(j=0; j<4; j++) {
				if(i==3 && d[j] > '5') { answer[i] = d[0]; break; }
//				if(i==1 && d[j] > '3') { answer[i] = d[0]; break; }
				if(i==0 && d[j] > '2') { answer[i] = d[0]; break; }
				if(d[j] > answer[i]) {
					answer[i] = d[j];
					done = 1;
					break;
				}
				if(j==3) answer[i] = d[0];
			}
			if(done == 1) break;
		}
		if(answer[0] == '2' && answer[1] > '3') {
			for(j=0; j<3; j++) {
				if(d[j] > time[1] && d[j] <= '3') { answer[1] = d[j]; break; }
				if(d[j] > '3' || j==3) { answer[1] = d[0]; break; }
			}
		}
		return answer;
	}
};