// https://leetcode.com/problems/duplicate-zeros/submissions/
// I. When facing the zero, insert zero after the index and pop the last element.
// time: O(n^2) space: O(1)
// Runtime: 20 ms, faster than 52.85% of C++ online submissions for Duplicate Zeros.
// Memory Usage: 9.8 MB, less than 62.25% of C++ online submissions for Duplicate Zeros.
class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		for(int i=0; i<arr.size(); i++) {
			if(arr[i] == 0) {
				arr.insert(arr.begin()+i, 0);
				arr.pop_back();
				i++;
			}
		}
	}
};