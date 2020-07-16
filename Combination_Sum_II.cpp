// https://leetcode.com/problems/combination-sum-ii/submissions/
// Basic idea is same as combination sum I problem
// I. Sort the given array.
// II. From the first element, sum elements until the sum is greater than or equal to the target. If the sum is equal to the target, then add it to the result.
// III. If the adding number is equal to the previous one, then skip it to avoid duplicates.
// time: O(n^2) space: O(n)
// Runtime: 48 ms, faster than 28.21% of C++ online submissions for Combination Sum II.
// Memory Usage: 15.7 MB, less than 24.17% of C++ online submissions for Combination Sum II.
class Solution {
public:
	void make(vector<vector<int>>& result, vector<int>& c, vector<int> t, int target, int sum, int i) {
		if(sum+c[i] > target) return;
		sum += c[i];
		t.push_back(c[i]);
		if(sum == target) {
			result.push_back(t);
			return;
		}
		for(int j=i+1; j<c.size(); j++) {
			if(j>i+1 && c[j] == c[j-1]) continue;
			make(result, c, t, target, sum, j);
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> answer;
		sort(candidates.begin(), candidates.end());
		for(int i=0; i<candidates.size(); i++) {
			if(i>0 && candidates[i] == candidates[i-1]) continue;
			make(answer, candidates, {}, target, 0, i);
		}
		return answer;
	}
};