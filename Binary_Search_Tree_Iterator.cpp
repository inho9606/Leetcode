// https://leetcode.com/problems/binary-search-tree-iterator/submissions/
// I. Push root node and it's all leftchildren into stack because left children have smaller values than rootnode in BST.
// II. If the stack is empty, it means that there are no available smallest number anymore.
// III. The smallest number is at top of stack. After poping the smallest number in stack, we have to update stack. From the topest node on the stack, it's rightnode has larger numbers than current smallest number. So, we have to push it's rightchild and all leftchildren of it's child into stack. Now, stack has the next smallest number at the top.
// time: O(log2n) space: O(log2n)
// Runtime: 88 ms, faster than 64.50% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 27.9 MB, less than 34.91% of C++ online submissions for Binary Search Tree Iterator.
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
class BSTIterator {
public:
	stack<TreeNode*> st;
	BSTIterator(TreeNode* root) {
		for(TreeNode* ptr = root; ptr != NULL; ptr = ptr->left)
			st.push(ptr);
	}
    
    /** @return the next smallest number */
	int next() {
		TreeNode* ptr = st.top();
		int t = ptr->val;
		st.pop();
		for(ptr = ptr->right; ptr != NULL; ptr = ptr->left)
			st.push(ptr);
		return t;
	}
    
    /** @return whether we have a next smallest number */
	bool hasNext() {
		if(st.empty() == 1) return 0;
		return 1;
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */