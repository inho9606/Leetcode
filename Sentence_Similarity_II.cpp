// https://leetcode.com/problems/sentence-similarity-ii/submissions/
// I. Construct undirected graph with pairs.
// II. Find the path from words1[i] to words2[i] with bfs traversal.
// time: O(n^2) space: O(n)
// disjoint set will speed up.
// Runtime: 940 ms, faster than 18.89% of C++ online submissions for Sentence Similarity II.
// Memory Usage: 131.5 MB, less than 6.06% of C++ online submissions for Sentence Similarity II.
class Solution {
public:
	bool is_similar(unordered_map<string,vector<string>>& g, string source, string target) {
		if(g.find(source) == g.end()) return 0;
		unordered_set<string> visited;
		queue<string> q;
		string cur;
		q.push(source);
		visited.insert(source);
		while(q.empty() == 0) {
			cur = q.front();
			q.pop();
			if(cur == target) return 1;
			for(int i=0; i<g[cur].size(); i++) {
				if(visited.find(g[cur][i]) != visited.end()) continue;
				q.push(g[cur][i]);
				visited.insert(g[cur][i]);
			}
		}
		return 0;
	}
	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
		if(words1.size() != words2.size()) return 0;
		unordered_map<string,vector<string>> graph;
		for(int i=0; i<pairs.size(); i++) {
			graph[pairs[i][0]].push_back(pairs[i][1]);
			graph[pairs[i][1]].push_back(pairs[i][0]);
		}
		for(int i=0; i<words1.size(); i++) {
			if(words1[i] == words2[i]) continue;
			if(is_similar(graph, words1[i], words2[i]) == 0) return 0;
		}
		return 1;
	}
};