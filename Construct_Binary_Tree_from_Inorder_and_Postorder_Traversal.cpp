// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/
// Base: The last node in postorder is the rootnode.
// I. Store the index of each nodes in inorder traversal with map.
// II. From the last one in postorder traversal, choose the node and find the index of that node in inorder traversal.
// III. Make new node with selected node. and it's leftnode candidates can be those at left of index in inorder traversal, and rightnode candidates can be those at the right of index in inorder traversal.
// IV. The left index from the selected index in inorder traversal means that the index in postorder traversal should be the length of rightside from selected index in inorder traversal away far from the selected index in postorder because postorder represents the nodes from leftchild, rightchild and itself. I mean we have to jump rightchild area from itself.
// V. the rightchild candidates can be the next left one from the selected index in postorder, and it can be anyone from the selected index in inorder to the right.
// time: O(nlogn) space: O(n)
// Runtime: 24 ms, faster than 73.23% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
// Memory Usage: 23.8 MB, less than 40.35% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
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
	TreeNode *makeTree(vector<int>& postorder, unordered_map<int,int>& m, int mostleft, int mostright, int i) {
		if(mostleft > mostright) return NULL;
		TreeNode *root = new TreeNode(postorder[i]);
		int j = m[postorder[i]];
		root->left = makeTree(postorder, m, mostleft, j-1, i-(mostright-j+1));
		root->right = makeTree(postorder, m, j+1, mostright, i-1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int,int> m;
		TreeNode *answer;
		for(int i=0; i<inorder.size(); i++)
			m[inorder[i]] = i;
		answer = makeTree(postorder, m, 0, inorder.size()-1, postorder.size()-1);
		return answer;
	}
};