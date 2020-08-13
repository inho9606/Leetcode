// https://leetcode.com/problems/count-univalue-subtrees/submissions/
// I. Traversal the given tree with postorder way.
// II. Before traversaling, however, check if it does not any children. If it has no children, then it is uni-value subtree, so return true.
// III. It is univalue subtree if leftchild is univalue and rightchild is univalue and the values of root, leftchild and rightchild are same. If any of child is not univalue, then the subtree can't be univalue.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 93.82% of C++ online submissions for Count Univalue Subtrees.
// Memory Usage: 16.6 MB, less than 42.06% of C++ online submissions for Count Univalue Subtrees.
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
	bool postorder(TreeNode* root, int &n) {
		if(root==NULL) return 0;
		if(root->left == NULL && root->right == NULL) { n+=1; return 1; }
		bool l=0, r=0;
		l = postorder(root->left, n);
		r = postorder(root->right, n);
		if((root->left == NULL || (l==1 && root->val == root->left->val)) && (root->right == NULL || (r==1 && root->val == root->right->val))) {
			n += 1;
			return 1;
		}
		return 0;
	}
	int countUnivalSubtrees(TreeNode* root) {
		int answer=0;
		postorder(root, answer);
		return answer;
	}
};