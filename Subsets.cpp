// https://leetcode.com/problems/subsets/
// I. Find all possible combinations.
// II. Choose one among the given numbers, and exclude it on the next round.
// II. After removing the chosen item, choose one again among the rest numbers, and exclude it on the next round.
// III. Repeat I and II until all numbers are chosen.
// IV. On each step, push the chosen items into the result subset.
// time: O(n^2) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 7.3 MB, less than 55.63% of C++ online submissions for Subsets.
class Solution {
public:
	void makeSet(vector<vector<int>>& subsets, vector<int>& nums, int i, vector<int> s) {
		if(i==nums.size()) return;
		s.push_back(nums[i]);
		subsets.push_back(s);
		for(int j=i+1; j<nums.size(); j++)
			makeSet(subsets, nums, j, s);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> answer;
		answer.push_back({});
		for(int i=0; i<nums.size(); i++)
			makeSet(answer, nums, i, {});
		return answer;
	}
};