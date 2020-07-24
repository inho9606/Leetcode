// https://leetcode.com/problems/redundant-connection/submissions/
// Key idea: In tree, every node can have only one parent node, and every node should be in the same tree.
// Need to study Union Set datastructure.
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> answer(2);
		int n=0, u, v;
		for(int i=0; i<edges.size(); i++) {
			u = edges[i][0];
			v = edges[i][1];
			if(v > n) n= v;
		}
		vector<int> sets(n+1);
		for(int i=0; i<=n; i++)
			sets[i] = i;
		for(int i=0; i<edges.size(); i++) {
			u = edges[i][0];
			v = edges[i][1];
			while(u != sets[u]) u = sets[u];
			while(v != sets[v]) v = sets[v];

			if(u == v) {
				answer[0] = edges[i][0];
				answer[1] = edges[i][1];
			}
			else
				sets[u] = v;

		}
		return answer;
	}
};