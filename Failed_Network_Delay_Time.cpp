// Using BFS with a directed graph presenting network nodes.
class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		int v, w, answer = 0;
		vector<vector<pair<int,int> > > graph(N+1);
		vector<int> visited(N+1, 0);
		queue<pair<int,int> > path;
		for(int i=0; i<times.size(); i++)
			graph[times[i][0]].push_back({times[i][1], times[i][2]});
		visited[K] = 1;
		for(int i=0; i<graph[K].size(); i++) {
			path.push({graph[K][i].first, graph[K][i].second});
			visited[graph[K][i].first] = 1;
		}
		while(path.empty() == 0) {
			v = path.front().first;
			w = path.front().second;
			path.pop();
			if(w > answer) answer = w;
			for(int i=0; i<graph[v].size(); i++) {
				if(visited[graph[v][i].first] == 0) {
					visited[graph[v][i].first] = 1;
					path.push({graph[v][i].first, w+graph[v][i].second});
				}
			}
		}
		if(answer > 0) return answer;
		return -1;
	}
};