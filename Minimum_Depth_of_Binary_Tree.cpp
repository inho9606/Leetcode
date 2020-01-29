// https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/
// time: O(n) memory: O(n)
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
	int minDepth(TreeNode* root) {
		if(root == NULL) return 0;
		int level;
		queue<pair<TreeNode*,int> > t;
		t.push({root, 1});
		while(t.empty() == 0) {
			auto ptr = t.front().first;
			level = t.front().second;
			t.pop();
			if(ptr->left == NULL && ptr->right == NULL) return level;
			if(ptr->left != NULL) t.push({ptr->left, level+1});
			if(ptr->right != NULL) t.push({ptr->right, level+1});
		}
	return 0;
	}
};