// https://leetcode.com/problems/unique-binary-search-trees/submissions/
// I. When the tree has only one node, the number of tree structures is 1. And it is two when the tree has two nodes.
// II. Tree has three nodes, it can have 1, 2 and 3 as it's root node. I have to know how many trees available for each root. When the rootnode is 1, there can be 2 trees because only 3 can be added to previous tree, and the new node 3 can be added on two places..
// III. Anyway, when nodes are three, it can be (2,1,2) trees for each root to have 1, 2 and 3. And (5,2,2,5) for 4 nodes. Finally, when there are five nodes, it has (14,5,4,5,14). It is multiplied number by the number of the 1-node tree and n-1-nodes tree, 2-tree and n-2-tree......
// time: O(n^2) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
// Memory Usage: 5.9 MB, less than 85.21% of C++ online submissions for Unique Binary Search Trees.
class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n+1, 0);
		f[0] = 1;
		if(n>=1) f[1] = 1;
		if(n>=2) f[2] = 2;
		for(int i=3; i<=n; i++) {
			for(int j=0; j<i; j++)
				f[i] += f[j]*f[i-j-1];
		}
		return f[n];
	}
};