// https://leetcode.com/problems/reconstruct-itinerary/submissions/
// Idea: Visit all nodes with DFS in lexical order. When all nodes are visited, return it.
// I. Represent a graph with map: key is the vertix, and value is neighbors. Value is multiset because we should start searching by lexical order.
// II. From the first neighbor of JFK, try to visit all nodes. When visiting nodes, delete vertices that don't have neighbors anymore.
// III. When all vertices in the graph are deleted or only one vertix is left, which means that all nodes are visited, update and return answer.
// time: O(n^2logn) space: O(n)
// Runtime: 736 ms, faster than 5.04% of C++ online submissions for Reconstruct Itinerary.
// Memory Usage: 287.7 MB, less than 5.17% of C++ online submissions for Reconstruct Itinerary.
class Solution {
public:
	bool done = 0;
	void dfs(unordered_map<string,multiset<string>> route, vector<string>& result, string from, string to, vector<string> path) {
		unordered_map<string,multiset<string>>::iterator ptr = route.find(from);
		multiset<string>::iterator sptr = (ptr->second).find(to);
		(ptr->second).erase(sptr);
		if((ptr->second).size() == 0) route.erase(ptr);
		path.push_back(from);
		ptr = route.find(to);
		if(ptr == route.end() || (ptr->second).size() == 0) {
			if(route.size() <= 1) {
				path.push_back(to);
				result.assign(path.begin(), path.end());
				done = 1;
			}
			return;
		}
		for(sptr = (ptr->second).begin(); sptr != (ptr->second).end(); sptr++) {
			dfs(route, result, to, *sptr, path);
			if(done == 1) return;
		}
	}
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> answer;
		unordered_map<string,multiset<string>> route;
		unordered_map<string,multiset<string>>::iterator ptr;
		multiset<string>::iterator sptr;
		string from, to;
		for(int i=0; i<tickets.size(); i++) {
			from = tickets[i][0];
			to = tickets[i][1];
			route[from].insert(to);
		}
		ptr = route.find("JFK");
		for(sptr = (ptr->second).begin(); sptr != (ptr->second).end(); sptr++) {
			dfs(route, answer, "JFK", *sptr, {});
			if(done == 1) break;
		}
		return answer;
	}
};