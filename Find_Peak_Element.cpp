// https://leetcode.com/problems/find-peak-element/submissions/
// Just Brute Force Solution with O(n)
// Couldn't come up with O(logn) solution on time
// Runtime: 4 ms, faster than 99.48% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.8 MB, less than 79.58% of C++ online submissions for Find Peak Element.
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if(nums.size()==1) return 0;
		for(int i=0; i<nums.size(); i++) {
			if(i==0) {
				if(nums[i] > nums[i+1]) return i;
			}
			else if(i==nums.size()-1) {
				if(nums[i] > nums[i-1]) return i;
			}
			else if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
		}
		return -1;
	}
};

/* Binary Search Solution O(logn)
* From discuss board
class Solution {
public:
int findPeakElement(const vector<int> &num) {
int low = 0, high = num.size() - 1;
while (low < high - 1) {
int mid = (low + high) / 2;
if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) 
return mid;
else if (num[mid] > num[mid + 1]) 
high = mid - 1;
else 
low = mid + 1; 
}
return num[low] > num[high] ? low : high;
}
};
*/