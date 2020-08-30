// https://leetcode.com/problems/graph-valid-tree/submissions/
// I. First, check if the graph has a cycle or not. If it has any cycle, then it should be false. I used topological order to check cycles. But, we can know without using it from the number of edges. The minimum number of edges in graph is vertices - 1. So, if there are edges more than the number of vertices-1, it means there might be a cycle.
// II. If there are no cycle, then check if the cycle is parted or not. If there are two or more graphs, it should be false because every vertices should be connected in tree. I used BFS to traversal a graph.
// time: O(n) space: O(n)
// Runtime: 44 ms, faster than 62.16% of C++ online submissions for Graph Valid Tree.
// Memory Usage: 13.9 MB, less than 42.06% of C++ online submissions for Graph Valid Tree.
class Solution {
public:
	bool validTree(int n, vector<vector<int>>& edges) {
		if(n==1) return 1;
		vector<vector<int>> graph(n);
		int from, to;
		vector<int> degrees(n, 0), removed, visited(n,0);
		queue<int> q;
		for(int i=0; i<edges.size(); i++) {
			from = edges[i][0];
			to = edges[i][1];
			graph[from].push_back(to);
			graph[to].push_back(from);
			degrees[from] += 1;
			degrees[to] += 1;
		}
		for(int i=0; i<n; i++) {
			if(degrees[i] == 1) q.push(i);
		}
		while(q.empty() == 0) {
			from = q.front();
			q.pop();
			removed.push_back(from);
			for(int i=0; i<graph[from].size(); i++) {
				to = graph[from][i];
				degrees[to] -= 1;
				if(degrees[to] == 1) q.push(to);
			}
		}
		if(removed.size() != n) return 0;
		q.push(0);
		visited[0] = 1;
		while(q.empty() == 0) {
			from = q.front();
			q.pop();
			for(int i=0; i<graph[from].size(); i++) {
				to = graph[from][i];
				if(visited[to] == 1) continue;
				q.push(to);
				visited[to] = 1;
			}
		}
		for(int i=0; i<n; i++) {
			if(visited[i] == 0) return 0;
		}
		return 1;
	}
};

/*
* Without topological order
* Runtime: 40 ms, faster than 70.84% of C++ online submissions for Graph Valid Tree.
* Memory Usage: 12.4 MB, less than 67.00% of C++ online submissions for Graph Valid Tree.
class Solution {
public:
	bool validTree(int n, vector<vector<int>>& edges) {
		if(edges.size()>n-1) return 0;
		vector<vector<int>> graph(n);
		vector<int> visited(n,0);
		int from, to;
		queue<int> q;
		for(int i=0; i<edges.size(); i++) {
			from = edges[i][0];
			to = edges[i][1];
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		q.push(0);
		visited[0] = 1;
		while(q.empty() == 0) {
			from = q.front();
			q.pop();
			for(int i=0; i<graph[from].size(); i++) {
				to = graph[from][i];
				if(visited[to] == 1) continue;
				q.push(to);
				visited[to] = 1;
			}
		}
		for(int i=0; i<n; i++) {
			if(visited[i] == 0) return 0;
		}
		return 1;
	}
};
*/