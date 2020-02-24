// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/
// Create new array with size of nums.size+1. And check if each digits from 1 to n has appeared or not. After that, find zero value in the new array, having zero as its value means the number didn't appeared.
// time: O(n) space: O(n)
// Runtime: 108 ms, faster than 97.59% of C++ online submissions for Find All Numbers Disappeared in an Array.
// Memory Usage: 15 MB, less than 50.00% of C++ online submissions for Find All Numbers Disappeared in an Array.
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> answer;
		vector<bool> m(nums.size()+1, 0);
		for(int i=0; i<nums.size(); i++)
			m[nums[i]] = 1;
		for(int i=1; i<=nums.size(); i++) {
			if(m[i] == 0)
				answer.push_back(i);
		}
		return answer;
	}
};