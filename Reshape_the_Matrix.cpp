// https://leetcode.com/problems/reshape-the-matrix/submissions/
// I. If the sizes of original matrix and new matrix are different, then it cannot be resized.
// II. Make new matrix with r*c size, and fill it with original one from the first to the last.
// time: O(r*c) space: O(r*c)
// Runtime: 36 ms, faster than 56.23% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Reshape the Matrix.
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if(nums.size()*nums[0].size() != r*c) return nums;
		vector<vector<int>> answer(r, vector<int>(c));
		int k=0, l=0;
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				if(l == nums[k].size()) { l = 0; k += 1; }
				answer[i][j] = nums[k][l];
				l++;
			}
		}
		return answer;
	}
};