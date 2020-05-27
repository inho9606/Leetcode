// https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/
// Binary Search in Tree
// time: O(nlogn) space: O(1)
// Runtime: 64 ms, faster than 41.24% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 34.9 MB, less than 9.76% of C++ online submissions for Search in a Binary Search Tree.

/* Iterative version */
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
	TreeNode* searchBST(TreeNode* root, int val) {
		for(auto ptr = root; ptr!=NULL; ) {
			if(ptr->val == val) return ptr;
			else if(val < ptr->val) ptr = ptr->left;
			else ptr = ptr->right;
		}
		return NULL;
	}
};

/*
* Recursion Version
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if(root==NULL) return NULL;
		if(root->val == val) return root;
		else if(root->val > val) return searchBST(root->left, val);
		else if(root->val < val) return searchBST(root->right, val);
		return root;
	}
};
*/