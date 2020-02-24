// https://leetcode.com/problems/number-of-boomerangs/submissions/
// using map to store dists between each points. If there exists same distance between two points from the same point, then it means it can be a pair to reverse the order.
// time: O(n^2) space: O(n)
// Runtime: 380 ms, faster than 87.26% of C++ online submissions for Number of Boomerangs.
// Memory Usage: 86.5 MB, less than 94.12% of C++ online submissions for Number of Boomerangs.
class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		unordered_map<int, int> s;
		int cnt=0, dist;
		for(int i=0; i<points.size(); i++) {
			s.clear();
			for(int j=0; j<points.size(); j++) {
				if(i==j) continue;
				dist = ((points[j][0] - points[i][0]) * (points[j][0] - points[i][0])) + ((points[j][1] - points[i][1]) * (points[j][1] - points[i][1]));
				if(s[dist] > 0)
					cnt += s[dist] * 2;
				s[dist] += 1;
			}
		}
		return cnt;
	}
};