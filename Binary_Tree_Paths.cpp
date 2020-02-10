// https://leetcode.com/problems/binary-tree-paths/submissions/
// DFS postorder traversal can check the path from the root to each leap.
// O(n) space: O(n)
// Runtime: 4 ms, faster than 76.77% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 11.8 MB, less than 57.89% of C++ online submissions for Binary Tree Paths.
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
	void postorder(TreeNode *root, string path, vector<string> &answer) {
		if(root == NULL) return;
		if(path.size() != 0) path += "->";
		path += to_string(root->val);
		if(root->left == NULL && root->right == NULL) {
			answer.push_back(path);
			return;
		}
		postorder(root->left, path, answer);
		postorder(root->right, path, answer);
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> answer;
		postorder(root, "", answer);
		return answer;
	}
};