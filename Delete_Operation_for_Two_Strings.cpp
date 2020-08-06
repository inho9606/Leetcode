// https://leetcode.com/problems/delete-operation-for-two-strings/submissions/
// Find LCS, and subtract lcs from word1.size and word2.size.
// time: O(nm) space: O(nm) n is the number of word1, n is the number of word2.
// Runtime: 32 ms, faster than 48.41% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 11.9 MB, less than 45.63% of C++ online submissions for Delete Operation for Two 
class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> f(word1.size()+1, vector<int>(word2.size()+1, 0));
		for(int i=0; i<f.size(); i++) {
			for(int j=0; j<f[0].size(); j++) {
				if(i==0 || j==0) f[i][j] = 0;
				else if(word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1]+1;
				else f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
		return word1.size() - f[word1.size()][word2.size()] + word2.size() - f[word1.size()][word2.size()];
	}
};