// https://leetcode.com/problems/employee-importance/submissions/
// Brute Force * DFS can make it faster, I think
// time: O(n?n^2)? space: O(1)
// Runtime: 36 ms, faster than 89.74% of C++ online submissions for Employee Importance.
// Memory Usage: 23.1 MB, less than 35.71% of C++ online submissions for Employee Importance.
/*
// Definition for Employee.
class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};
*/

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		int i, answer = 0;
		for(i=0; i<employees.size(); i++) {
			if(employees[i]->id == id) {
				answer += employees[i]->importance;
				break;
			}
		}
		for(int j=0; j<employees[i]->subordinates.size(); j++) {
			answer += getImportance(employees, employees[i]->subordinates[j]);
		}
		return answer;
	}
};