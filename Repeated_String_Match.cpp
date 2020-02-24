// https://leetcode.com/problems/repeated-string-match/submissions/
// Runtime: 12 ms, faster than 81.83% of C++ online submissions for Repeated String Match.
// Memory Usage: 9.2 MB, less than 90.91% of C++ online submissions for Repeated String Match.
class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		string repeated = "";
		int i=0, j=0, answer=0;
		while(repeated.size() <= B.size()) {
			repeated += A;
			answer++;
			if(repeated.find(B) < repeated.size()) return answer;
		}
		repeated += A;
		answer++;
		if(repeated.find(B) < repeated.size()) return answer;
		return -1;
	}
};