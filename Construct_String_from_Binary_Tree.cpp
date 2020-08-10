// https://leetcode.com/problems/construct-string-from-binary-tree/submissions/
// I. The number itself + ( the next candidate number + )
// II. For doing I, traversal given tree with preorder.
// III. Omit if the node does not have any child. Also, the rightchild can be omitted if the node only has leftchild.
// time: O(n) space: O(n)
// Runtime: 36 ms, faster than 72.17% of C++ online submissions for Construct String from Binary Tree.
// Memory Usage: 55.8 MB, less than 33.23% of C++ online submissions for Construct String from Binary Tree.
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
	string tree2str(TreeNode* t) {
		if(t==NULL) return "";
		string answer = to_string(t->val);
		if(t->left == NULL && t->right == NULL) return answer;
		answer += "(" + tree2str(t->left) + ")";
		if(t->right != NULL) answer += "(" + tree2str(t->right) + ")";
		return answer;
	}
};