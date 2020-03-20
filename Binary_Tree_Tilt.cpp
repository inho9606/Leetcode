// https://leetcode.com/problems/binary-tree-tilt/submissions/
// I. Use postorder traversal. Return values are two, one is its tilt, and the other one is sum of the subtree's all nodes.
// II. tilt: Left subtree's tilt + right subtree's tilt + |sum of left subtree's nodes - sum of right subtree's nodes|
// III. Sum of current subtree's nodes: Sum of left subtree's nodes + sum of right subtree's nodes + current nodes
// time: O(n) space: O(1)
// Runtime: 12 ms, faster than 98.80% of C++ online submissions for Binary Tree Tilt.
// Memory Usage: 19.9 MB, less than 100.00% of C++ online submissions for Binary Tree Tilt.
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
	pair<int,int> postorder(TreeNode* root) {
		if(root==NULL) return {0,0};
		pair<int,int> l = postorder(root->left);
		pair<int,int> r = postorder(root->right);
		int tilt = l.first+r.first + abs(l.second-r.second);
		int sum = l.second+r.second + root->val;
		return {tilt, sum};
	}
	int findTilt(TreeNode* root) {
		pair<int,int> answer = postorder(root);
		return answer.first;
	}
};