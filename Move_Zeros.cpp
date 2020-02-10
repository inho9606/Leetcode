// i is to check if the number of array is zero or nonzero. j is to remake the array. From j, the numbers should not be zero. So, if a ith number of the array is not zero, swap ith number and jth number, and then j moves to right.
// time: O(n) space: O(1)
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int temp, j=0;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] != 0) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				j+=1;
			}
		}
	}
};