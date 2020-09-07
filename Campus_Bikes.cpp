// https://leetcode.com/problems/campus-bikes/submissions/
// I. For each workers and bikes, get the distance and keep the worker and bike's index.
// II. Choose worker and bike from stored distance info and mark used bike not to assign it again.
// Refered to discuss board to speed up.
// time: O(n*m) space: O(c)
// Runtime: 156 ms, faster than 87.61% of C++ online submissions for Campus Bikes.
// Memory Usage: 43.8 MB, less than 61.13% of C++ online submissions for Campus Bikes.
class Solution {
public:
	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		vector<int> answer(workers.size(), -1);
		vector<vector<pair<int,int>>> dist(2001);
		int d;
		for(int i=0; i<workers.size(); i++) {
			for(int j=0; j<bikes.size(); j++) {
				d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
				dist[d].push_back({i,j});
			}
		}
		for(int i=0; i<2001; i++) {
			for(int j=0; j<dist[i].size(); j++) {
				if(answer[dist[i][j].first] == -1 && bikes[dist[i][j].second][0] != -1) {
					answer[dist[i][j].first] = dist[i][j].second;
					bikes[dist[i][j].second][0] = -1;
				}
			}
		}
		return answer;
	}
};