// https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/
// Runtime: 76 ms, faster than 56.47% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 20 MB, less than 47.89% of C++ online submissions for Kth Largest Element in a Stream.
class KthLargest {
public:
	priority_queue<int, vector<int>, greater<int>> array;
	int target;
	KthLargest(int k, vector<int>& nums) {
		target = k;
		for (int i = 0; i < nums.size(); i++)
			array.push(nums[i]);
	}
	int add(int val) {
		array.push(val);
		while (array.size() > target)
			array.pop(); 
		return array.top();
}
};
