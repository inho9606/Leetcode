// https://leetcode.com/problems/relative-ranks/submissions/
// Create new vector to sort the given scores.
// Make the new vector unordered_map with a rank as key, and score as value.
// Restore the vector with ranks.
// time: O(nlogn) space: O(n)
// Runtime: 12 ms, faster than 98.55% of C++ online submissions for Relative Ranks.
// Memory Usage: 11.8 MB, less than 33.33% of C++ online submissions for Relative Ranks.
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> answer(nums.size());
		vector<int> ranked(nums.begin(), nums.end());
		unordered_map<int,string> ranks;
		sort(ranked.begin(), ranked.end());
		for(int i=0; i<ranked.size(); i++) {
			if(i == ranked.size()-1) ranks[ranked[i]] = "Gold Medal";
			else if(i == ranked.size()-2) ranks[ranked[i]] = "Silver Medal";
			else if(i == ranked.size()-3) ranks[ranked[i]] = "Bronze Medal";
			else ranks[ranked[i]] = to_string(ranked.size()-i);
		}
		for(int i=0; i<nums.size(); i++)
			answer[i] = ranks[nums[i]];
		return answer;
	}
};