// https://leetcode.com/problems/binary-tree-right-side-view/submissions/
// Level traversal with BFS. And store the most right node on each level.
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 11.7 MB, less than 74.62% of C++ online submissions for Binary Tree Right Side View.
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> answer;
		TreeNode *cur;
		int level;
		queue<pair<TreeNode*,int>> q;
		q.push({root, 0});
		while(q.empty() == 0) {
			cur = q.front().first;
			level = q.front().second;
			q.pop();
			if(cur == NULL) continue;
			if(q.empty() == 1 || q.front().second > level)
				answer.push_back(cur->val);
			if(cur->left != NULL) q.push({cur->left, level+1});
			if(cur->right != NULL) q.push({cur->right, level+1});
		}
		return answer;
	}
};