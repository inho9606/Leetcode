// I. Initialize a vecto with set of char. And store keyboard rows on each index of the vector. (i.e. 0: 'z','x','c','v','b'... 1: 'a','s','d'...)
// II. For each word, check the first character which keyboard row is from.
// III. for the rest of characters on a word, check the other characters all comming from the same row with the first one. If so, add the word on answer. If not, go to the next word.
// time: O(nlog1) space: O(c)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Keyboard Row.
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
		vector<string> answer;
		int n=0;
		vector<set<char> > keyboard(3);
		keyboard[0] = {'z','x','c','v','b','n','m'};
		keyboard[1] = {'a','s','d','f','g','h','j','k','l'};
		keyboard[2] = {'q','w','e','r','t','y','u','i','o','p'};
		for(int i=0; i<words.size(); i++) {
			if(keyboard[0].count(tolower(words[i][0])) == 1) n = 0;
			else if(keyboard[1].count(tolower(words[i][0])) == 1) n = 1;
			else n = 2;
			for(int j=0; j<words[i].size(); j++) {
				if(keyboard[n].count(tolower(words[i][j])) == 0) break;
				if(j == words[i].size()-1) answer.push_back(words[i]);
			}
		}
		return answer;
	}
};