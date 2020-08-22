// https://leetcode.com/problems/time-needed-to-inform-all-employees/submissions/
// Represent a directed graph or a tree using vector that has the given manager as root.
// I. Make vector that ith employee has it's subordinations.
// II. Traversal the tree with BFS recording inforTime.
// time: O(n) space: O(n)
// Runtime: 592 ms, faster than 70.86% of C++ online submissions for Time Needed to Inform All Employees.
// Memory Usage: 126.5 MB, less than 47.99% of C++ online submissions for Time Needed to Inform All Employees.
class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		int answer=0, emp;
		vector<int> t(n, -1);
		vector<vector<int>> sub(n);
		queue<int> q;
		for(int i=0; i<manager.size(); i++) {
			if(manager[i] != -1) sub[manager[i]].push_back(i);
		}
		q.push(headID);
		t[headID] = 0;
		while(q.empty() == 0) {
			emp = q.front();
			q.pop();
			for(int i=0; i<sub[emp].size(); i++) {
				q.push(sub[emp][i]);
				t[sub[emp][i]] = t[emp] + informTime[emp];
				if(t[sub[emp][i]] > answer) answer = t[sub[emp][i]];
			}
		}
		return answer;
	}
};