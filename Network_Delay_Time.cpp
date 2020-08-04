// https://leetcode.com/problems/network-delay-time/submissions/
// Idea: BFS on the given Graph recording time. If there is a node that is not visited at all, then it should return -1.
// If a visited node can take faster, then update it. It is like Dijkstra Algorithm
// time: O(n) space: O(n)
// Runtime: 220 ms, faster than 97.53% of C++ online submissions for Network Delay Time.
// Memory Usage: 40.2 MB, less than 63.41% of C++ online submissions for Network Delay Time.
class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		int answer=0;
		vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>());
		vector<int> visited(n+1, 0);
		queue<pair<int,int>> q;
		int u, v, t;
		for(int i=0; i<times.size(); i++) {
			u = times[i][0];
			v = times[i][1];
			t = times[i][2];
			graph[u].push_back({v, t});
		}
		q.push({k, 0});
		visited[k] = 1;
		while(q.empty() == 0) {
			u = q.front().first;
			t = q.front().second;
			q.pop();
			for(int i=0; i<graph[u].size(); i++) {
			v = graph[u][i].first;
			if(visited[v] != 0 && visited[v] <= t+graph[u][i].second) continue;
			q.push({v, t+graph[u][i].second});
			visited[v] = t+graph[u][i].second;
			}
		}
		for(int i=1; i<=n; i++) {
			if(visited[i] == 0) return -1;
			if(visited[i] > answer) answer = visited[i];
		}
		return answer;
	}
};