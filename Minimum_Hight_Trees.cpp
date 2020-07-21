// https://leetcode.com/problems/minimum-height-trees/submissions/
// 위상정렬(Topological Ordering..)
// 1. 양방향 그래프를 구현한 이후, 간선의 개수가 1인 정점을 임시 벡터에 저장한다. 원래 위상정렬에서는 자기 자신을 향하는 간선의 개수가 없는 정점을 선택하지만, 지금은 양방향 그래프이므로 나와 연결된 간선이 하나만 있을 때 그 간선이 나한테 연결되어 있지 않고 나한테서 뻣어나가는 것만 있다고 가정한다. 즉, 양방향 그래프이지만 단방향 그래프라고 본다.
// 2. 일반적인 위상정렬과 마찬가지로 1번에서 선택된 정점과 이웃한 정점의 차수를 1 감소시킨다. 그렇게 감소한 정점의 차수가 1이 되면 벡터에 저장한다. 차수가 1이 되었다는 것은 이웃한 정점 기준으로 이웃한 정점과 현재 정점을 잇는 간선밖에 없다는 뜻.
// 3. 임시 벡터에 아무것도 저장되지 않을 때까지, 즉 모든 정점이 어떤 간선도 가지지 않을 때까지 2번을 반복한다. 그리고 모든 정점이 끊어지기 바로 직전에 간선이 존재하는 정점이 최종 답이 된다.
// 요약: 일반적으로 간선을 많이 가지고 있는 정점에서 출발하는 경로가 그래프의 끝 노드에 가는 데 최단거리일 확률이 높다. 따라서 그래프의 끝부분부터 잘라나가다 보면 그래프의 몸통이 나오고, 최종적으로 남은 몸통 정점들에서 출발하는 게 가장 빠르다고 볼 수 있다.
// * 위상정렬은 그래프의 가지부터 지워나간다.
// time: O(n) space: O(n)
// Runtime: 120 ms, faster than 98.90% of C++ online submissions for Minimum Height Trees.
// Memory Usage: 27.1 MB, less than 93.70% of C++ online submissions for Minimum Height Trees.
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> answer={0}, degrees(n, 0), t1;
		vector<vector<int>> graph(n);
		int from, to;
		for(int i=0; i<edges.size(); i++) {
			from = edges[i][0];
			to = edges[i][1];
			graph[from].push_back(to);
			degrees[from] += 1;
			graph[to].push_back(from);
			degrees[to] += 1;
		}
		for(int i=0; i<n; i++) {
			if(degrees[i] == 1) t1.push_back(i);
		}
		while(t1.size() > 0) {
			answer.clear();
			answer.assign(t1.begin(), t1.end());
			t1.clear();
			for(int i=0; i<answer.size(); i++) {
				from = t1[i];
				degrees[from] -= 1;
				for(int j=0; j<graph[from].size(); j++) {
					to = graph[from][j];
					degrees[to] -= 1;
					if(degrees[to] == 1) t1.push_back(to);
				}
			}
		}
		return answer;
	}
};
/*
* BFS solution
time: O(n^2) space: O(n)
Time Limit Exceeded
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> answer, hights(n);
		vector<vector<int>> graph(n);
		queue<pair<int,int>> q;
		int node, level, hight, minimum=INT_MAX;
		for(int i=0; i<edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		for(int i=0; i<n; i++) {
			vector<bool> v(n, 0);
			while(q.empty() == 0) q.pop();
			q.push({i, 0});
			v[i] = 1;
			hight = 0;
			while(q.empty() == 0) {
				node = q.front().first;
				level = q.front().second;
				q.pop();
				if(level > hight) hight = level;
				for(int j=0; j<graph[node].size(); j++) {
					if(v[graph[node][j]] == 0) {
						q.push({graph[node][j], level+1});
						v[graph[node][j]] = 1;
					}
				}
			}
			hights[i] = hight;
			if(hight < minimum) minimum = hight;
		}
		for(int i=0; i<n; i++) {
			if(hights[i] == minimum) answer.push_back(i);
		}
		return answer;
	}
};
*/