// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/
// I. Make new  array with sorted data.
// II. Subtract the length of continuous same values from the first and from the last.
// time: O(nlogn) space: O(n)
// Runtime: 72 ms, faster than 8.05% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Shortest Unsorted Continuous Subarray.
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> s(nums.begin(), nums.end());
		int answer=s.size();
		sort(s.begin(), s.end());
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] != s[i]) {
				answer -= i;
				break;
			}
			if(i == nums.size()-1) return 0;
		}
		for(int i=0; i<nums.size(); i++) {
			if(nums[nums.size()-1-i] != s[s.size()-1-i]) {
				answer -= i;
				break;
			}
		}
		return answer;
	}
};