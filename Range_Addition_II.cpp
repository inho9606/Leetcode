// https://leetcode.com/problems/range-addition-ii/submissions/
// Problem: Given ops, find the minimum rectangle.
// I. Initialize the rectangle with given width and hight m, n.
// II. Find the minimum width and hight among the given rectangle ops with for loop.
// time: O(n) space: O(1) n is the size of ops.
// Runtime: 12 ms, faster than 62.25% of C++ online submissions for Range Addition II.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Range Addition II.
class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int a=m, b=n, answer;
		for(int i=0; i<ops.size(); i++) {
			if(ops[i][0] < a) a = ops[i][0];
			if(ops[i][1] < b) b = ops[i][1];
		}
		answer = a*b;
		return answer;
	}
};