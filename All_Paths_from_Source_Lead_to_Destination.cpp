// https://leetcode.com/problems/all-paths-from-source-lead-to-destination/submissions/
// I. To find paths from source to destination, use DFS traversal.
// II. It's just simulation, so brute force solution can be right.
// time: O(n) space: O(1)
// Runtime: 156 ms, faster than 78.88% of C++ online submissions for All Paths from Source Lead to Destination.
// Memory Usage: 29.6 MB, less than 95.03% of C++ online submissions for All Paths from Source Lead to Destination.
class Solution {
public:
	bool dfs(vector<vector<int>>& g, vector<bool>& v, int s, int d) {
		if(v[s] == 1) return 0;
		if(g[s].size() == 0 && s!=d) return 0;
		if(g[s].size() == 0 && s==d) return 1;
		v[s] = 1;
		for(int i=0; i<g[s].size(); i++) {
			if(s == g[s][i]) return 0;
			if(dfs(g, v, g[s][i], d) == 0) return 0;
		}
		return 1;
	}
	bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
		if(edges.size()==0) return 1;
		vector<bool> visited(n, 0);
		vector<vector<int>> graph(n);
		for(int i=0; i<edges.size(); i++)
			graph[edges[i][0]].push_back(edges[i][1]);
		if(graph[source].size() == 0) return 0;
		for(int i=0; i<graph[source].size(); i++) {
			visited.assign(n, 0);
			visited[source] = 1;
			if(source == graph[source][i]) return 0;
			if(dfs(graph, visited, graph[source][i], destination) == 0) return 0;
		}
		return 1;
	}
};