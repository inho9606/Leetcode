// https://leetcode.com/problems/evaluate-division/submissions/
// I. From A to B, the value is weight. When it's direct goes, we should multiply the weights, and reverse should be divided.
// II. To find the destination from the source, use BFS.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate Division.
// Memory Usage: 7.8 MB, less than 23.87% of C++ online submissions for Evaluate Division.
class Solution {
public:
	double bfs(unordered_map<string,vector<pair<string,double>>>& graph, string from, string to) {
		if(graph.count(from) == 0) return -1.0;
		if(from == to) return 1.0;
		unordered_map<string,bool> v;
		double w=1.0, t3;
		string t1, t2;
		queue<pair<string, double>> q;
		for(auto ptr = graph.begin(); ptr != graph.end(); ptr++)
			v[ptr->first] = 0;
		q.push({from, w});
		v[from] = 1;
		while(q.empty() == 0) {
			t1 = q.front().first;
			w = q.front().second;
			q.pop();
			if(t1 == to) return w;
			for(int i=0; i<graph[t1].size(); i++) {
				t2 = graph[t1][i].first;
				if(v[t2] == 1) continue;
				t3 = graph[t1][i].second;
				q.push({t2, w*t3});
				v[t2] = 1;
			}
		}
		return -1.0;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double> answer;
		unordered_map<string,vector<pair<string,double>>> graph;
		string from, to;
		double w;
		for(int i=0; i<equations.size(); i++) {
			from = equations[i][0];
			to = equations[i][1];
			w = values[i];
			graph[from].push_back({to, w});
			graph[to].push_back({from, 1.0/w});
		}
		for(int i=0; i<queries.size(); i++) {
			w = bfs(graph, queries[i][0], queries[i][1]);
			answer.push_back(w);
		}
		return answer;
	}
};