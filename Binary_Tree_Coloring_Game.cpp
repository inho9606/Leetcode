// https://leetcode.com/problems/binary-tree-coloring-game/submissions/
// I. Get the number of nodes with x root subtree.
// II. If the number of the subtree's nodes is less than n/2, then I can pick up the parent of x to win.
// III. If the number of subtree's nodes is grater than n, then check if the number of subtrees as child of x is greater than n/2. If so, then I can choose the childnode of x.
// time: O(n) space: O(n)
// Runtime: 8 ms, faster than 43.14% of C++ online submissions for Binary Tree Coloring Game.
// Memory Usage: 11 MB, less than 35.14% of C++ online submissions for Binary Tree Coloring Game.
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
	int dfs(TreeNode* root, vector<int>& sub) {
		if(root==NULL) return 0;
		int l = dfs(root->left, sub);
		int r = dfs(root->right, sub);
		sub[root->val] = l + r + 1;
		return l+r+1;
	}
	TreeNode* find(TreeNode* root, int x) {
		if(root==NULL) return NULL;
		if(root->val == x) return root;
		TreeNode* l = find(root->left, x);
		if(l!=NULL) return l;
		return find(root->right, x);
	}
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		if(n==1) return 0;
		vector<int> v(n+1, 0);
		dfs(root, v);
		if(v[x] <= n/2) return 1;
		else {
			TreeNode* cur = find(root, x);
			if(cur->left != NULL && v[cur->left->val] > n/2) return 1;
			if(cur->right != NULL && v[cur->right->val] > n/2) return 1;
		}
		return 0;
	}
};