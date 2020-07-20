// https://leetcode.com/problems/path-sum-ii/submissions/
// preorder
// Runtime: 24 ms, faster than 42.68% of C++ online submissions for Path Sum II.
// Memory Usage: 34.2 MB, less than 36.76% of C++ online submissions for Path Sum II.
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
	void dfs(vector<vector<int>>& path, TreeNode *root, int target, vector<int> cur, int sum) {
		if(root==NULL) return;
		sum += root->val;
		cur.push_back(root->val);
		if(sum == target && root->left == NULL && root->right == NULL) {
			path.push_back(cur);
			return;
		}
		if(root->left) dfs(path, root->left, target, cur, sum);
		if(root->right) dfs(path, root->right, target, cur, sum);
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> answer;
		dfs(answer, root, sum, {}, 0);
		return answer;
	}
};