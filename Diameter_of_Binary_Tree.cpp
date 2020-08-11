// https://leetcode.com/problems/diameter-of-binary-tree/submissions//**
// I. The longest length of a subtree is dpeth of leftnodes + depth of rightnodes from root.
// II. A tree can have a subtree that has longer diameter than itself, so I would check the length of each subtree's diameter.
// time: O(n) space: O(n)
// Runtime: 8 ms, faster than 98.88% of C++ online submissions for Diameter of Binary Tree.
// Memory Usage: 20.8 MB, less than 67.53% of C++ online submissions for Diameter of Binary Tree.
/*
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
	int depth(TreeNode *root, int &dist) {
		if(root==NULL) return 0;
		int l = depth(root->left, dist);
		int r = depth(root->right, dist);
		if(l+r > dist) dist = l+r;
		return max(l, r) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int answer=0;
		depth(root, answer);
		return answer;
	}
};