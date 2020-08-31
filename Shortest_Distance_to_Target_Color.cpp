// https://leetcode.com/problems/shortest-distance-to-target-color/submissions/
// I. Distribute colors with different vectors.
// II. Try to find the closest number in the color vector with Binary Search.
// time: O(n) space: O(n) O(n): Distribute whole colors, O(logn) for binary search.
// Runtime: 700 ms, faster than 83.93% of C++ online submissions for Shortest Distance to Target Color.
// Memory Usage: 122.9 MB, less than 59.53% of C++ online submissions for Shortest Distance to Target Color.
class Solution {
public:
	int bs(vector<int>& color, int i) {
		if(color.size()==0) return -1;
		int d = INT_MAX, s=0, e=color.size()-1, m;
		while(s<=e) {
			m = (s+e)/2;
			d = min(d, abs(i-color[m]));
			if(i-color[m]==0) break;
			else if(i-color[m]>0) s = m+1;
			else e = m-1;
		}
		return d;
	}
	vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		vector<int> answer;
		vector<int> a, b, c;
		for(int i=0; i<colors.size(); i++) {
			if(colors[i] == 1) a.push_back(i);
			else if(colors[i] == 2) b.push_back(i);
			else c.push_back(i);
		}
		for(int i=0; i<queries.size(); i++) {
			if(queries[i][1] == 1) answer.push_back(bs(a, queries[i][0]));
			else if(queries[i][1] == 2) answer.push_back(bs(b, queries[i][0]));
			else if(queries[i][1] == 3) answer.push_back(bs(c, queries[i][0]));
		}
		return answer;
	}
};