// https://leetcode.com/problems/find-eventual-safe-states/
// Idea: Similar to Topological order solution..
// I. Choose nodes that does not have any outgoing edges and push them into queue.
// II. Move each node's parent in queue and disconnect one edge connecting queued child.
// III. If the parent has no outgoing edge after disconnecting, then push it into queue.
// IV. Repeat II and III until queue is empty. Empty queue means that the unselected nodes have one or more outgoing edges.
// time: O(e) space: O(n) e is the number of edges and n is the number of nodes.
// Runtime: 524 ms, faster than 17.02% of C++ online submissions for Find Eventual Safe States.
// Memory Usage: 61.9 MB, less than 27.66% of C++ online submissions for Find Eventual Safe States.
class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n=graph.size(), start, terminal;
		vector<int> outgoing(n, 0), answer;
		vector<vector<int>> rgraph(n);
		queue<int> q;
		for(int i=0; i<n; i++) {
			outgoing[i] = graph[i].size();
			for(int j=0; j<graph[i].size(); j++)
				rgraph[graph[i][j]].push_back(i);
		}
		for(int i=0; i<n; i++) {
			if(outgoing[i] == 0) {
				answer.push_back(i);
				q.push(i);
			}
		}
		while(q.empty() == 0) {
			terminal = q.front();
			q.pop();
			for(int i=0; i<rgraph[terminal].size(); i++) {
				start = rgraph[terminal][i];
				outgoing[start] -= 1;
				if(outgoing[start] == 0) {
					q.push(start);
					answer.push_back(start);
				}
			}
		}
		sort(answer.begin(), answer.end());
		return answer;
	}
};