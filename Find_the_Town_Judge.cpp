// https://leetcode.com/problems/find-the-town-judge/submissions/
// It should be directed graph, and town judge have n-1 degrees and 0 outgoing.
// time: O(e+v) space: O(v)
// Runtime: 324 ms, faster than 99.07% of C++ online submissions for Find the Town Judge.
// Memory Usage: 61 MB, less than 64.75% of C++ online submissions for Find the Town Judge.
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> degrees(n+1, 0), outgoing(n+1, 0);
		for(int i=0; i<trust.size(); i++) {
			outgoing[trust[i][0]] += 1;
			degrees[trust[i][1]] += 1;
		}
		for(int i=1; i<=n; i++) {
			if(degrees[i] == n-1 && outgoing[i] == 0) return i;
		}
		return -1;
	}
};