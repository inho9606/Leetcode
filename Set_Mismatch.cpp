// https://leetcode.com/problems/set-mismatch/submissions/
// I. Count each numbers in the array.
// time: O(n) space: O(n)
// Runtime: 36 ms, faster than 85.50% of C++ online submissions for Set Mismatch.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Set Mismatch.
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> t(nums.size()+1, 0);
		vector<int> answer(2);
		for(int i=0; i<nums.size(); i++) {
			t[nums[i]] += 1;
			if(t[nums[i]] ==2 ) answer[0] = nums[i];
		}
		for(int i=1; i<t.size(); i++) {
			if(t[i] == 0) answer[1] = i;
		}
		return answer;
	}
};