// time: O(n) space: O(n)
// Runtime: 20 ms, faster than 73.76% of C++ online submissions for Minimum Absolute Difference in BST.
// Memory Usage: 21.7 MB, less than 100.00% of C++ online submissions for Minimum Absolute Difference 
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
	void inorder(TreeNode* root, vector<int>& v) {
		if(root==NULL) return;
		inorder(root->left, v);
		v.push_back(root->val);
		inorder(root->right, v);
	}
	int getMinimumDifference(TreeNode* root) {
		int answer=INT_MAX;
		vector<int> v;
		inorder(root, v);
		for(int i=1; i<v.size(); i++) {
			if(v[i]-v[i-1] < answer) answer = v[i]-v[i-1];
		}
		return answer;
	}
};