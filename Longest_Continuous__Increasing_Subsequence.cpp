// https://leetcode.com/problems/longest-continuous-increasing-subsequence/submissions/
// I. Keep the length of the first increasing order.
// II. If the next increasing order's length is longer than previous one, then update it.
// time: O(n) space: O(1)
// Runtime: 12 ms, faster than 89.98% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Longest Continuous Increasing Subsequence.
class Solution {
public:
int findLengthOfLCIS(vector<int>& nums) {
	if(nums.size()==0) return 0;
	int answer=1, cnt=1;
	for(int i=1; i<nums.size(); i++) {
		if(nums[i] > nums[i-1]) cnt+=1;
		else {
			if(cnt > answer) answer = cnt;
			cnt = 1;
		}
		if(i == nums.size()-1 && cnt > answer) answer = cnt;
	}
	return answer;
	}
};