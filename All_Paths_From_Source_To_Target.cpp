// https://leetcode.com/problems/all-paths-from-source-to-target/submissions/
// Runtime: 20 ms, faster than 48.01% of C++ online submissions for All Paths From Source to Target.
// Memory Usage: 15.3 MB, less than 38.82% of C++ online submissions for All Paths From Source to Target.
// Simply using DFS
// time: O(e+v) space: O(n)
class Solution {
public:
	void dfs(vector<vector<int>> &graph, vector<vector<int>> &answer, vector<int> path, int source, int target) {
		path.push_back(source);
		if(source == target) {
			answer.push_back(path);
			return;
		}
		for(int i=0; i<graph[source].size(); i++) {
			dfs(graph, answer, path, graph[source][i], target);
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int target = graph.size()-1;
		vector<vector<int>> answer;
		vector<int> p;
		dfs(graph, answer, p, 0, target);
		return answer;
	}
};