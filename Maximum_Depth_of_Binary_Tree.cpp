// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
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
	int maxDepth(TreeNode* root) {
		int cnt, t;
		if(root == NULL) return 0;
		cnt = maxDepth(root->left);
		t = maxDepth(root->right);
		if(cnt >= t) return cnt+1;
		else return t+1;
	}
};