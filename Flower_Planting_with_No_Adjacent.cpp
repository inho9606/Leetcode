// https://leetcode.com/problems/flower-planting-with-no-adjacent/submissions/
// I. Construct undirected graph with given paths.
// II. Using BFS, traversal the graph marking with color. Neighbors must not be the same color.
// time: O(e+v) space: O(v)
// Runtime: 240 ms, faster than 85.07% of C++ online submissions for Flower Planting With No Adjacent.
// Memory Usage: 40.6 MB, less than 76.20% of C++ online submissions for Flower Planting With No Adjacent.
class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> answer(N, 0);
		vector<vector<int>> graph(N+1);
		queue<int> q;
		int from, to;
		for(int i=0; i<paths.size(); i++) {
			from = paths[i][0];
			to = paths[i][1];
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		for(int i=0; i<N; i++) {
			if(answer[i] != 0) continue;
			while(q.empty() == 0) q.pop();
			q.push(i+1);
			answer[i] = 1;
			while(q.empty() == 0) {
				from = q.front();
				q.pop();
				for(int j=0; j<graph[from].size(); j++) {
					to = graph[from][j];
					if(answer[to-1] == 0) {
						if(answer[from-1] < 4) answer[to-1] = answer[from-1]+1;
						else answer[to-1] = 1;
						q.push(to);
					}
					else if(answer[to-1] == answer[from-1]) {
						if(answer[from-1] < 4) answer[to-1] = answer[from-1]+1;
						else answer[to-1] = 1;
					}
				}
			}
		}
		return answer;
	}
};