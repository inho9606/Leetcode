// https://leetcode.com/problems/third-maximum-number/submissions/
// using Set to remove repeated numbers in the array. And return the third value from the last.
// time: O(nlogn) space: O(n)
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		set<int> s;
		set<int>::iterator it;
		for(int i=0; i<nums.size(); i++)
			s.insert(nums[i]);
		it = s.end();
		it--;
		if(s.size() >= 3) {
			it--;
			it--;
		}
		return *it;
	}
};