// https://leetcode.com/problems/assign-cookies/submissions/
// First, sort g and s to compare each values on greedy and size of cookies. And, increase the number of content children if an element in g is less than or equal to an element in s.
// time: O(nlogn) space: O(1)
// Runtime: 40 ms, faster than 88.88% of C++ online submissions for Assign Cookies.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Assign Cookies.
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int i=0, j=0, answer=0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		while(i<g.size() && j<s.size()) {
			if(g[i] <= s[j]) {
				answer++;
				i++;
			}
			j++;
		}
		return answer;
	}
};