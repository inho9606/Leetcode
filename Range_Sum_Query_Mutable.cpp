// https://leetcode.com/problems/range-sum-query-mutable/submissions/
// Just Brute force..
// time: O(n) space: O(n)
// Runtime: 220 ms, faster than 25.32% of C++ online submissions for Range Sum Query - Mutable.
// Memory Usage: 19.2 MB, less than 96.47% of C++ online submissions for Range Sum Query - Mutable.
class NumArray {
public:
	vector<int> v;
	NumArray(vector<int>& nums) {
		v.assign(nums.begin(), nums.end());
	}
    
	void update(int i, int val) {
		v[i] = val;
	}
    
	int sumRange(int i, int j) {
		int sum=0;
		for(; i<=j; i++)
			sum += v[i];
		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */