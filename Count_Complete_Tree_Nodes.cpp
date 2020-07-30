// https://leetcode.com/problems/count-complete-tree-nodes/submissions/
// I. Compute how many levels in the given tree and the number of completed nodes. If n is the number of nodes in complete binary tree, n is 2^(k-1). k is hight of the tree.
// II. From the total number of nodes, add one for each leaf node.
// time: Almost O(n) space: O(n)
// Runtime: 36 ms, faster than 96.46% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 31.2 MB, less than 14.00% of C++ online submissions for Count Complete Tree Nodes.
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
	int countLeaf(TreeNode *root, int bottom, int level) {
		if(root==NULL) return 0;
		if(bottom == level) return 1;
		int left = countLeaf(root->left, bottom, level+1);
		int right = countLeaf(root->right, bottom, level+1);
		return left+right;
	}
	int countNodes(TreeNode* root) {
		int answer, h=0;
		TreeNode* ptr;
		for(ptr=root; ptr != NULL; ptr = ptr->left)
			h+=1;
		if(h==0) return 0;
		answer = pow(2, h-1)-1;
		answer += countLeaf(root, h, 1);
		return answer;
	}
};

/*
* Most voted solution on discuss board
class Solution {
public:
int countNodes(TreeNode* root) {
if(!root) return 0;
int hl=0, hr=0;
TreeNode *l=root, *r=root;
while(l) {hl++;l=l->left;}
while(r) {hr++;r=r->right;}
if(hl==hr) return pow(2,hl)-1;
return 1+countNodes(root->left)+countNodes(root->right);
}
};
*/