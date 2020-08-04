// https://leetcode.com/problems/sort-colors/submissions/
// Bubble Sort
// time: O(n^2) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.2 MB, less than 97.87% of C++ online submissions for Sort Colors.
class Solution {
public:
	void sortColors(vector<int>& nums) {
		for(int i=0; i<nums.size(); i++) {
			for(int j=0; j<nums.size()-i-1; j++) {
				if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
			}
		}
	}
};

/*
* Selection Sort
* time: O(n^2) space: O(1)
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
* Memory Usage: 8.3 MB, less than 95.14% of C++ online submissions for Sort Colors.
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int t;
		for(int i=0; i<nums.size(); i++) {
			t = i;
			for(int j=i; j<nums.size(); j++) {
				if(nums[j] < nums[t]) t = j;
			}
			swap(nums[i], nums[t]);
		}
	}
};
*/