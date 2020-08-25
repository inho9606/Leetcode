// https://leetcode.com/problems/occurrences-after-bigram/submissions/
// I. Split text by whitespace.
// II. If the word is equal to the given first string, then first flag is 1.
// III. If the word is equal to the second and the previous word was equal to the first, then second flag is 1.
// IV. If both the first flag and second flag are 1, then push the current word to the answer.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Occurrences After Bigram.
// Memory Usage: 6.5 MB, less than 46.60% of C++ online submissions for Occurrences After Bigram.
class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> answer;
		int i=0, j=0, t1=0, t2=0;
		string word;
		while(i<text.size() && j<=text.size()) {
			if(text[j] == ' ' || j==text.size()) {
				word = text.substr(i, j-i);
				i = j+1;
				if(t1 == 1 && t2 == 1) { answer.push_back(word); t1 = 0; t2 = 0; }
				if(word == first) t1 = 1;
				else if(word == second && t1 == 1) t2 = 1;
				else { t1 = 0; t2 = 0; }
			}
			j+=1;
		}
		return answer;
	}
};