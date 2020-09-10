// https://leetcode.com/problems/sentence-similarity/submissions/
// I. Store pairs in map like graph.
// II. Check the pairs are right or not.
// time: O(nlogn) space: O(n)
// Runtime: 20 ms, faster than 56.20% of C++ online submissions for Sentence Similarity.
// Memory Usage: 11.7 MB, less than 54.26% of C++ online submissions for Sentence Similarity.
class Solution {
public:
	bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
		if(sentence1.size() != sentence2.size()) return 0;
		unordered_map<string,unordered_set<string>> m;
		for(int i=0; i<similarPairs.size(); i++) {
			m[similarPairs[i][0]].insert(similarPairs[i][1]);
			m[similarPairs[i][1]].insert(similarPairs[i][0]);
		}
		for(int i=0; i<sentence1.size(); i++) {
			if(sentence1[i] == sentence2[i]) continue;
			if(m.find(sentence1[i]) == m.end()) return 0;
			if(m[sentence1[i]].find(sentence2[i]) == m[sentence1[i]].end()) return 0;
		}
		return 1;
	}
};