// https://leetcode.com/problems/is-graph-bipartite/submissions/
// I. Traversal the given raph with BFS, and return false if the node's group is same when accessing the visited node.
// time: O(n) space: O(n)
// Runtime: 56 ms, faster than 79.69% of C++ online submissions for Is Graph Bipartite?.
// Memory Usage: 13.7 MB, less than 57.50% of C++ online submissions for Is Graph Bipartite?.
class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> group(graph.size(), 0);
		queue<int> q;
		int node;
		for(int a=0; a<graph.size(); a++) {
			if(group[a] == 0) {
				q.push(a);
				group[a] = 1;
				while(q.empty() == 0) {
					node = q.front();
					q.pop();
					for(int i=0; i<graph[node].size(); i++) {
						if(group[node] == group[graph[node][i]]) return 0;
						if(group[graph[node][i]] != 0) continue;
						if(group[node] == 1) group[graph[node][i]] = 2;
						else group[graph[node][i]] = 1;
						q.push(graph[node][i]);
					}
				}
			}
		}
		return 1;
	}
};