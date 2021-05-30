// https://leetcode.com/problems/find-the-town-judge/submissions/
// Simulation
// Runtime: 168 ms, faster than 49.81% of C++ online submissions for Find the Town Judge.
// Memory Usage: 60.8 MB, less than 74.40% of C++ online submissions for Find the Town Judge.
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
	vector<int> trusting(n, 0), trusted(n, 0);
	for(int i=0; i<trust.size(); i++) {
		trusting[trust[i][0]-1] += 1;
		trusted[trust[i][1]-1] += 1;
	}
	for(int i=0; i<n; i++) {
		if (trusting[i] == 0 && trusted[i] == n-1) return i+1;
	}
	return -1;
	}
};