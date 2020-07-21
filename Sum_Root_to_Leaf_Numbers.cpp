// https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/
// Idea: Basic DFS with preorder.
// I. For each nodes, add it's value to sum.
// II. If the rootnode doesn't have both leftchild and rightchild, then return the sum.
// III. For a nodethat has borth childs, return the sum of two child's results.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
// Memory Usage: 12.3 MB, less than 98.12% of C++ online submissions for Sum Root to Leaf Numbers.
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
	int dfs(TreeNode *root, int sum) {
		if(root==NULL) return 0;
		sum *= 10;
		sum += root->val;
		if(root->left == NULL && root->right == NULL) {
			return sum;
		}
		int left = dfs(root->left, sum);
		int right = dfs(root->right, sum);
		return left + right;
	}
	int sumNumbers(TreeNode* root) {
		int answer = dfs(root, 0);
		return answer;
	}
};