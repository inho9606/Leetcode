// https://leetcode.com/problems/range-sum-query-immutable/submissions/
// Make new array for sum of given array. Each index i in the new array has a value as sum of from index 0 to index i in given array nums. And, sumRange function returns difference between jth value and i-1th value in new array.
// time: O(n), space: O(n)
// make new array : O(n), find the sum : O(1)
// Runtime: 32 ms, faster than 78.52% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 17.3 MB, less than 72.41% of C++ online submissions for Range Sum Query - Immutable.
class NumArray {
public:
	vector<int> v;
// O(n)
	NumArray(vector<int>& nums) {
		v.assign(nums.size(), 0);
		for(int i=0; i<nums.size(); i++) {
			if(i==0) v[i] = nums[i];
			else v[i] = v[i-1] + nums[i];
		}
	}
// O(1)
	int sumRange(int i, int j) {
		if(i>0) return v[j] - v[i-1];
		return v[j];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */