// https://leetcode.com/problems/ransom-note/submissions/
// Count each letters in each string, and compare those. If ransomNote has more many characters than magazine on the same letter, return false.
// time: O(n) space: O(n)
// Runtime: 20 ms, faster than 91.28% of C++ online submissions for Ransom Note.
// Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Ransom Note.
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> p(26, 0), q(26, 0);
		for(int i=0; i<magazine.size(); i++)
			p[magazine[i]-'a'] += 1;
		for(int i=0; i<ransomNote.size(); i++) {
			q[ransomNote[i]-'a'] += 1;
			if(q[ransomNote[i]-'a'] > p[ransomNote[i]-'a'])
				return 0;
		}
		return 1;
	}
};