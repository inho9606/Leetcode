// https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/
// I. BST 특성 상 오른쪽 밑에있는  노드의 합 + 자신의 값 + 부모 노드의 합 하면 될거같은데 값을 수정하는 과정에서 오류가 발생에서 안됨..
// 이 솔루션은 n^2 아주 안 좋음..
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
	void inorder(TreeNode* root, vector<TreeNode*> &t) {
		if(root==NULL) return;
		inorder(root->left, t);
		t.push_back(root);
		inorder(root->right, t);
	}
	TreeNode* convertBST(TreeNode* root) {
		if(root==NULL) return root;
		vector<TreeNode*> t;
		inorder(root, t);
		for(int i=0; i<t.size()-1; i++) {
			for(int j=i+1; j<t.size(); j++)
				t[i]->val += t[j]->val;
		}
		return root;
	}
};