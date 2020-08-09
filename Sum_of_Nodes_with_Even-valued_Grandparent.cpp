// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/submissions/
// I. Traversal with dfs.
// II. If the current node is even number, then add all it's grandchildren.
// time: O(n) space: O(1)
// Runtime: 64 ms, faster than 72.55% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
// Memory Usage: 38.1 MB, less than 88.59% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
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
	int dfs(TreeNode* root, int sum) {
		if(root==NULL) return 0;
		int left = dfs(root->left, sum);
		int right = dfs(root->right, sum);
		if(root->val % 2 == 0) {
			if(root->left != NULL) {
				if(root->left->left != NULL) sum += root->left->left->val;
				if(root->left->right != NULL) sum += root->left->right->val;
			}
			if(root->right != NULL) {
				if(root->right->left != NULL) sum += root->right->left->val;
				if(root->right->right != NULL) sum += root->right->right->val;
			}
		}
		return sum+left+right;
	}
	int sumEvenGrandparent(TreeNode* root) {
		int answer=0;
		answer = dfs(root, 0);
		return answer;
	}
};