// https://leetcode.com/problems/subtree-of-another-tree/submissions/
// I. Check if the nodes are same or not for all nodes.
// I tried to find the equal value first, and check the subtree is same or not. but it doesn't work..
// time: O(n^2) space: O(1)
// Runtime: 44 ms, faster than 13.09% of C++ online submissions for Subtree of Another Tree.
// Memory Usage: 18.7 MB, less than 100.00% of C++ online submissions for Subtree of Another Tree.
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
	bool inorder(TreeNode* s, TreeNode* t) {
		if(s==NULL && t==NULL) return 1;
		if(s==NULL || t==NULL) return 0;
		if(s->val != t->val) return 0;
		return inorder(s->left,t->left) && inorder(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if(s==NULL) return 0;
		if(inorder(s,t) == 1) return 1;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};