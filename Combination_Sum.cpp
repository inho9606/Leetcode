// https://leetcode.com/problems/combination-sum/submissions/
// I. From the first to the last element, add each number.
// II. On the second step, the range is from the start point to the last element.
// recursive method
// time: O(n^2) space: O(n)
// Runtime: 56 ms, faster than 30.36% of C++ online submissions for Combination Sum.
// Memory Usage: 18.4 MB, less than 28.96% of C++ online submissions for Combination Sum.
class Solution {
public:
	void build(vector<int>& c, int target, vector<vector<int>>& result, int i, vector<int> cur, int sum) {
		if(sum+c[i] > target) return;
		sum += c[i];
		cur.push_back(c[i]);
		if(sum == target) {
			result.push_back(cur);
			return;
		}
		for(int j=i; j<c.size(); j++)
			build(c, target, result, j, cur, sum);
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> answer;
		for(int i=0; i<candidates.size(); i++) {
			build(candidates, target, answer, i, vector<int>(), 0);
		}
		return answer;
	}
};