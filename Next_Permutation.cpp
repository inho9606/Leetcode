// https://leetcode.com/problems/next-permutation/submissions/
// I. Find the last index increasing values.
// II. If there is no that index, then sort whole elements. If there is at least one, then find an element that is grater than it's value and the smallest one after the index.
// III. Swap the smallest one and index. and Sort elements after the swapped one.
// time: O(nlogn) space: O(1)
// Runtime: 4 ms, faster than 93.22% of C++ online submissions for Next Permutation.
// Memory Usage: 12 MB, less than 97.62% of C++ online submissions for Next Permutation.
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int p=-1, t=-1;
		for(int i=0; i<nums.size()-1; i++) {
			if(nums[i+1] > nums[i]) p=i;
		}
		if(p==-1) sort(nums.begin(), nums.end());
		else {
			t = p+1;
			for(int i=p+1; i<nums.size(); i++) {
				if(nums[i] > nums[p] && nums[i] < nums[t]) t = i;
			}
			swap(nums[p], nums[t]);
			sort(nums.begin()+p+1, nums.end());
		}
	}
};