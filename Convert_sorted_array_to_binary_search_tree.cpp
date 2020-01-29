// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
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
	TreeNode* makeBST(vector<int> &nums, TreeNode* root, int l, int r) {
		if(l>r) return 0;
		int mid = (l+r)/2;
		root = new TreeNode(nums[mid]);
		root->left = makeBST(nums, root->left, l, mid-1);
		root->right = makeBST(nums, root->right, mid+1, r);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* head = NULL;
		head = makeBST(nums, head, 0, nums.size()-1);
		return head;
	}
};