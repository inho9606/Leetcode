// https://leetcode.com/problems/distribute-candies/submissions/
// I. The maximum number of kinds of candies should be the half of given numbers of candies.
// II. Convert given candy array into set.
// III. The size of a new set is the answer.
// time: O(nlogn) space: O(n)
// Runtime: 364 ms, faster than 34.74% of C++ online submissions for Distribute Candies.
// Memory Usage: 42.7 MB, less than 66.67% of C++ online submissions for Distribute Candies.
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> s(candies.begin(), candies.end());
		if(s.size() > candies.size()/2) return candies.size()/2;
		return s.size();
	}
};