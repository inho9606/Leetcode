// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/
// I. Make new vector containing all nodes on ascending order with inorder traversal.
// II. Find the sum that equals to k by adding from the first and the last.
// time: O(n) space: O(n)
// Runtime: 52 ms, faster than 30.15% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 22.5 MB, less than 100.00% of C++ online submissions for Two Sum IV - Input is a BST.
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
	void inorder(vector<int>& nums, TreeNode* root) {
		if(root==NULL) return;
		inorder(nums, root->left);
		nums.push_back(root->val);
		inorder(nums, root->right);
	}
	bool findTarget(TreeNode* root, int k) {
		vector<int> nums;
		inorder(nums, root);
		int i=0, j=nums.size()-1;
		while(i<j) {
			if(nums[i] + nums[j] == k) return 1;
			else if(nums[i] + nums[j] < k) i+=1;
			else j-=1;
		}
		return 0;
	}
};