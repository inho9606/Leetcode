// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/
// time: O(n)? memory: O(n^2)
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
	void dfs(vector<vector<int> > &answer, TreeNode* root, int level) {
		if(root == NULL) return;
		if(answer.size() < level) { vector<int> t; answer.insert(answer.begin(), t); }
		answer[answer.size()-level].push_back(root->val);
		dfs(answer, root->left, level+1);
		dfs(answer, root->right, level+1);
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int> > answer;
		if(root == NULL) return answer;
		dfs(answer, root, 1);
		return answer;
	}
};