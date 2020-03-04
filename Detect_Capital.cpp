// https://leetcode.com/problems/detect-capital/submissions/
// I. If the first letter is a capital or not.
// II. If the previous letter was a lowercase, then the next one must not be capital.
// III. If the previous letter was capital and it was the first, then the next one can be both of uppercase and lowercase. But if it was not the first one, then it must be capital.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Detect Capital.
class Solution {
public:
bool detectCapitalUse(string word) {
		bool capital = 0;
		for(int i=0; i<word.size(); i++) {
			if(i==0) {
				if(word[i] >= 'a' && word[i] <= 'z') capital = 0;
				else capital = 1;
			}
			else {
				if(word[i] >= 'A' && word[i] <= 'Z' && capital == 0) return 0;
				else if(word[i] >= 'a' && word[i] <= 'z') {
					if(capital == 1 && i > 1) return 0;
					capital = 0;
				}
			}
		}
		return 1;
	}
};