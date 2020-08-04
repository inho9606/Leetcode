// https://leetcode.com/problems/satisfiability-of-equality-equations/submissions/
// Unionset and disjoint
// I. Initialize all available elements to itself. --> all elemtns have itself as their parent.
// II. For given two elements, make them union, which means their parents should be same. Index is parent.
// III. If there exists any cases that the rule breaks, then return false.
// time: O(n) space: O(1)
// Runtime: 8 ms, faster than 95.49% of C++ online submissions for Satisfiability of Equality Equations.
// Memory Usage: 11.6 MB, less than 49.46% of C++ online submissions for Satisfiability of Equality Equations.
class Solution {
public:
	int find(vector<int>& v, int i) {
		if(v[i] == i) return i;
		v[i] = find(v, v[i]);
		return v[i];
	}
	void unionset(vector<int>& v, int a, int b) {
		int i = find(v, a);
		int j = find(v, b);
		if(i!=j) v[i] = j;
	}
	bool equationsPossible(vector<string>& equations) {
		vector<int> v(26), neq;
		int a, b;
		for(int i=0; i<26; i++)
			v[i] = i;
		for(int i=0; i<equations.size(); i++) {
			a = equations[i][0] - 'a';
			b = equations[i][3] - 'a';
			if(equations[i][1] == '=')
				unionset(v, a, b);
			else
				neq.push_back(i);
		}
		for(int i=0; i<neq.size(); i++) {
			a = equations[neq[i]][0] - 'a';
			b = equations[neq[i]][3] - 'a';
			if(find(v, a) == find(v, b)) return 0;
		}
		return 1;
	}
};