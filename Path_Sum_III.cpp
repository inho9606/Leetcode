// https://leetcode.com/problems/path-sum-iii/submissions/
// DFS with postorder using vector to record the sums on path.
// time: O(n^2) space: O(n^2)
// Runtime: 40 ms, faster than 13.61% of C++ online submissions for Path Sum III.
// Memory Usage: 53.6 MB, less than 6.45% of C++ online submissions for Path Sum III.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int postorder(TreeNode* root, vector<int> path, int target) {
		if(root == NULL) return 0;
		int sum = 0, cnt = 0;
		vector<int> temp(path.size()+1);
		for(int i=0; i<path.size(); i++) {
			sum = path[i]+root->val;
			if(sum == target) cnt += 1;
			temp[i] = sum;
		}
		if(root->val == target) cnt++;
		temp[path.size()] = root->val;
		cnt += postorder(root->left, temp, target);
		cnt += postorder(root->right, temp, target);
		return cnt;
	}
	int pathSum(TreeNode* root, int sum) {
		if(root==NULL) return 0;
		vector<int> temp;
		int cnt=0;
		cnt = postorder(root, temp, sum);
		return cnt;
	}
};