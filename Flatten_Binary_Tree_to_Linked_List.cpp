// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
// I. From the most left leafnode, place the leftchilds between parent and it's childnode, and disconnect the leftchild from parent recursively.
// II. We have to do step I with all nodes in tree. So I traversal the tree with inorder traversal.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 96.77% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 13 MB, less than 5.07% of C++ online submissions for Flatten Binary Tree to Linked List.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void flatten(TreeNode* root) {
		if(root==NULL) return;
		flatten(root->left);
		TreeNode *ptr = root->right;
		root->right = root->left;
		root->left = NULL;
		for(TreeNode *end=root; end!=NULL; end=end->right) {
			if(end->right == NULL) {
				end->right = ptr;
				break;
			}
		}
		flatten(ptr);
	}
};