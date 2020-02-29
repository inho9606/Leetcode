// https://leetcode.com/problems/max-consecutive-ones/submissions/
// Linear Search.
// time: O(n) space: O(1)
// Runtime: 36 ms, faster than 86.10% of C++ online submissions for Max Consecutive Ones.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Max Consecutive Ones.
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int answer=0, cnt=0;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] == 1) cnt++;
			else {
				if(cnt > answer) answer = cnt;
				cnt = 0;
			}
		}
		if(cnt > answer) answer = cnt;
		return answer;
	}
};