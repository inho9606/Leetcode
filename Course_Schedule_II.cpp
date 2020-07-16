// https://leetcode.com/problems/course-schedule-ii/submissions/
// If the graph is a cycle, then it should be false.
// Same solution as Course I problem. 
// 차수가 0인것부터 벡터에 넣기 때문에 결국 처음 수강해야하는 강의부터 넣게 되는 것.
// 위상정렬
// 1. map으로 그래프 표현. 키는 정점, 값은 키와 인접한 정점들
// 2. 그래프를 만들면서 각 정점이 자신에게 향하는 간선의 개수를 기록. (degree, 차수)
// 3. 차수가 0인 정점을 queue에 저장. queue에 저장되는 정점을 removed 배열에 추가. 해당 정점이 그래프에서 제거되었음을 의미.
// 4. queue가 빌 때까지 차수가 0인 정점에서 출발하는 간선 제거 => (차수가 0인 정점에 인접한 정점의 차수를 1 감소)
// 5. 차수가 감소된 정점의 차수가 0이 되면 queue에 추가
// 6. queue가 비었을 때 제거된 정점 removed의 크기가 전체 그래프의 정점과 같으면 사이클이 없음. 그렇지 않으면 사키을 존재.
// time: O(nlogn) space: O(n)
// Runtime: 44 ms, faster than 74.47% of C++ online submissions for Course Schedule II.
// Memory Usage: 14.1 MB, less than 65.62% of C++ online submissions for Course Schedule II.
class Solution {
public:
	vector<int> findOrder(int num, vector<vector<int>>& pre) {
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
		if(removed.size() != num) removed.clear();
		return removed;
	}
};