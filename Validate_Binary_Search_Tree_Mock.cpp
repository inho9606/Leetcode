// Mock Interview
// I. All leftnodes should be less than it's parent and grater than it's grandparent.
// II. All rightnodes should be grater than it's parent and less than it's grandparent.
// time: O(nlogn) space: O(1)
// Spent 15 mins
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
	bool check(TreeNode* root, long long lower, long long upper) {
		if(root==NULL) return 1;
		for(TreeNode *ptr=root->left; ptr!=NULL; ptr=ptr->left) {
			if(ptr->val <= lower || ptr->val >= root->val) return 0;
		}
		for(TreeNode *ptr=root->right; ptr!=NULL; ptr=ptr->right) {
			if(ptr->val >= upper || ptr->val <= root->val) return 0;
		}
		return check(root->left, lower, root->val) && check(root->right, root->val, upper);
	}
	bool isValidBST(TreeNode* root) {
		return check(root, LLONG_MIN, LLONG_MAX);
	}
};