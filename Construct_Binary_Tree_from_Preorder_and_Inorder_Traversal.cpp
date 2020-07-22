// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
// I. The most rootnode is the first item of preorder.
// II. From the rootnode in preorder, the next items are rightchilds as many as the number of leftnodes of the root in inorder.
// III. the  rightchilds start from the root through the number of leftchilds in preorder, which is the number of leftsides of the root in inorder.
// time: O(n) space: O(n)
// Runtime: 16 ms, faster than 93.10% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal. 
// Memory Usage: 23.5 MB, less than 51.40% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
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
	TreeNode* make(unordered_map<int,int>& m, vector<int>& preorder, int s, int e, int i) {
		if(s> e) return 0;
		TreeNode* root = new TreeNode(preorder[i]);
		int t = m[preorder[i]];
		root->left = make(m, preorder, s, t-1, i+1);
		root->right = make(m, preorder, t+1, e, i+1+(t-s));
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		unordered_map<int,int> m;
	TreeNode *root;
		for(int i=0; i<inorder.size(); i++)
			m[inorder[i]] = i;
		root = make(m, preorder, 0, inorder.size()-1, 0);
		return root;
	}
};