// https://leetcode.com/problems/course-schedule/submissions/
// If the graph is a cycle, then it should be false.
// 위상정렬
// 1. map으로 그래프 표현. 키는 정점, 값은 키와 인접한 정점들
// 2. 그래프를 만들면서 각 정점이 자신에게 향하는 간선의 개수를 기록. (degree, 차수)
// 3. 차수가 0인 정점을 queue에 저장. queue에 저장되는 정점을 removed 배열에 추가. 해당 정점이 그래프에서 제거되었음을 의미.
// 4. queue가 빌 때까지 차수가 0인 정점에서 출발하는 간선 제거 => (차수가 0인 정점에 인접한 정점의 차수를 1 감소)
// 5. 차수가 감소된 정점의 차수가 0이 되면 queue에 추가
// 6. queue가 비었을 때 제거된 정점 removed의 크기가 전체 그래프의 정점과 같으면 사이클이 없음. 그렇지 않으면 사키을 존재.
// time: O(nlogn) space: O(n)
// Runtime: 44 ms, faster than 63.62% of C++ online submissions for Course Schedule.
// Memory Usage: 14.1 MB, less than 47.13% of C++ online submissions for Course Schedule.
class Solution {
public:
	bool canFinish(int num, vector<vector<int>>& pre) {
		unordered_map<int,vector<int>> graph;
		vector<int> degree(num, 0), removed, neighbors;
		int to, from;
		queue<int> degree_zero;
		for(int i=0; i<pre.size(); i++) {
			from = pre[i][1];
			to = pre[i][0];
			degree[to] += 1;
			graph[from].push_back(to);
		}
		for(int i=0; i<degree.size(); i++) {
			if(degree[i] == 0) degree_zero.push(i);
		}
		while(degree_zero.empty() == 0) {
			from = degree_zero.front();
			degree_zero.pop();
			removed.push_back(from);
			neighbors = graph[from];
			for(int i=0; i<neighbors.size(); i++) {
				to = neighbors[i];
				degree[to] -= 1;
				if(degree[to] == 0) degree_zero.push(to);
			}
		}
		return removed.size() == num;
	}
};

/** 
* 고전적인 dfs 탐색 방법
* time: O(n^2) space: O(n)
class Solution {
public:
	bool is_cycle(vector<vector<int>>& g, vector<bool>& vv, vector<bool> v, int i) {
		if(v[i] == 1) return 1;
		v[i] = 1;
		if(g[i].size() == 0) {
			for(int j=0; j<v.size(); j++) {
				if(v[j] == 1) vv[j] = v[j];
			}
			return 0;
		}
		for(int j=0; j<g[i].size(); j++) {
			if(is_cycle(g, vv, v, g[i][j]) == 1) return 1;
		}
		return 0;
	}
	bool canFinish(int num, vector<vector<int>>& pre) {
		vector<vector<int>> graph(num);
		vector<bool> v(graph.size(), 0), vv(graph.size(), 0);
		for(int i=0; i<pre.size(); i++)
			graph[pre[i][1]].push_back(pre[i][0]);
		for(int i=0; i<v.size(); i++) {
			if(vv[i] == 1) continue;
			if(is_cycle(graph, vv, v, i) == 1) return 0;
		}
		return 1;
	}
};
*/