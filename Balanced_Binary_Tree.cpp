// https://leetcode.com/problems/balanced-binary-tree/submissions/
// time: O(n)
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
	int check(TreeNode* root) {
		if(root == NULL) return 0;
		int l, r;
		l = check(root->left);
		r = check(root->right);
		if(l != -1 && r != -1) {
			if(l>r && l-r < 2) return l+1;
			if(r>=l && r-l < 2) return r+1;
			else return -1;
		}
		else return -1;
	}
	bool isBalanced(TreeNode* root) {
		if(check(root) == -1) return 0;
		return 1;
	}
};