// https://leetcode.com/problems/find-pivot-index/submissions/
// I. Get the sum of all numbers as right.
// II. From the most left, subtract the number from right one by one. And compare left and right.
// III. If left and right values are same, then return the index. Otherwise add the number to left.
// time: O(n) space: O(1)
// Runtime: 52 ms, faster than 46.62% of C++ online submissions for Find Pivot Index.
// Memory Usage: 31 MB, less than 74.24% of C++ online submissions for Find Pivot Index.
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int t, left=0, right=0, answer=-1;
		for(int i=0; i<nums.size(); i++)
			right += nums[i];
		for(int i=0; i<nums.size(); i++) {
			t = nums[i];
			right -= t;
			if(left == right) { answer = i; break; }
			left += t;
		}
		return answer;
	}
};