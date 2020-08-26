// https://leetcode.com/problems/word-break/submissions/
// I. Record the index where the next word starts at if the current word, which is characters from starting index through current character, is in dict; dp[i] = i+1. Otherwise, dp[i] = 0.
// II. If the previous character has index which is not zero, it means that at least it can be broken until the previous character. So, we can just start to find the next word in dict after the current character. 
// time: O(n^2logm) space: O(m) n is the length of string s, m is the number of wordDict.
// Runtime: 8 ms, faster than 91.51% of C++ online submissions for Word Break.
// Memory Usage: 13.1 MB, less than 48.59% of C++ online submissions for Word Break.
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<int> dp(s.size(), 0);
		unordered_set<string> d;
		for(int i=0; i<wordDict.size(); i++)
			d.insert(wordDict[i]);
		for(int i=0; i<s.size(); i++) {
			if(i==0) {
				if(d.count(s.substr(0, 1)) == 1) dp[0] = 1;
				else dp[0] = 0;
				continue;
			}
			for(int j=i-1; j>=0; j--) {
				if(d.count(s.substr(dp[j], i-dp[j]+1)) == 1) {
					dp[i] = i+1;
					break;
				}
			}
		}
		return dp[dp.size()-1];
	}
};