// https://leetcode.com/problems/merge-intervals/submissions/
// I. Sort the given intervals.
// II. Compare two sequence elements. If the first element's upper bound is greater than or equal to the second element's lower bound, then merge those.
// time: O(nlogn) space: O(n)
// Runtime: 44 ms, faster than 77.65% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.5 MB, less than 56.85% of C++ online submissions for Merge Intervals.
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> answer;
		if(intervals.size() <= 1) return intervals;
		int l1, l2, u1, u2;
		sort(intervals.begin(), intervals.end());
		for(int i=0; i<intervals.size(); i++) {
			if(i==0) {
				answer.push_back(intervals[i]);
				continue;
			}
			l1 = answer[answer.size()-1][0]; u1 = answer[answer.size()-1][1];
			l2 = intervals[i][0]; u2 = intervals[i][1];
			if(u1 < l2)
				answer.push_back(intervals[i]);
			else if(u1 >= l2 && u1 <= u2)
				answer[answer.size()-1][1] = u2;
		}
		return answer;
	}
};