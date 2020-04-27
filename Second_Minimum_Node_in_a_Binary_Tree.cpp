// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/submissions/
// I. Make two integer values and update them for every each node's value with preorder traversal.
// II. If the current node's value is less than either two integers, then update it.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.

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
	void traversal(TreeNode* root, vector<int>& t) {
		if(t[0] == -1) t[0] = root->val;
		else if(t[1] == -1) t[1] = root->val;
		else if(root->val < t[0]) {
			if(root->val < t[1] && t[1] > t[0]) t[1] = t[0];
			t[0] = root->val;
		}
		else if(root->val < t[1] && root->val != t[0]) t[1] = root->val;
		else if(t[0] == t[1]) t[1] = root->val;
		if(root->left == NULL && root->right == NULL) return;
		traversal(root->left, t);
		traversal(root->right, t);
	}

	int findSecondMinimumValue(TreeNode* root) {
		vector<int> t(2,-1);
		traversal(root, t);
		if(t[0] == -1 || t[1] == -1 || t[0] == t[1]) return -1;
		if(t[0] < t[1]) return t[1];
		return t[0];
	}
};