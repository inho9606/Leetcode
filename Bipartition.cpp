// https://leetcode.com/problems/possible-bipartition/submissions/
// Bipartite graph
// I. Mark each vertices with 1 or 2. If any vertix is already marked and try to makr it again, then return false.
// time: O(n) space: O(n)
// Runtime: 480 ms, faster than 49.57% of C++ online submissions for Possible Bipartition.
// Memory Usage: 64.5 MB, less than 92.98% of C++ online submissions for Possible Bipartition.
class Solution {
public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<int> g(n+1, 0);
		vector<vector<int>> graph(n+1);
		int from, to;
		queue<int> q;
		for(int i=0; i<dislikes.size(); i++) {
			graph[dislikes[i][0]].push_back(dislikes[i][1]);
			graph[dislikes[i][1]].push_back(dislikes[i][0]);
		}
		for(int i=1; i<=n; i++) {
			if(g[i] != 0) continue;
			while(q.empty() == 0) q.pop();
			q.push(i);
			g[i] = 1;
			while(q.empty() == 0) {
				from = q.front();
				q.pop();
				for(int j=0; j<graph[from].size(); j++) {
					to = graph[from][j];
					if(g[to] != 0 && g[to] == g[from]) return 0;
					else if(g[to] == 0) {
						if(g[from] == 1) g[to] = 2;
						else g[to] = 1;
						q.push(to);
					}
				}
			}
		}
		return 1;
	}
};