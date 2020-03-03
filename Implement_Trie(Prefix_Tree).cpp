// I. Using set with insert, and count.
// time: O(n), n is the maximum numbers of input words. space: O(n)
// Runtime: 244 ms, faster than 5.06% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 23.4 MB, less than 100.00% of C++ online submissions for Implement Trie (Prefix Tree).
class Trie {
public:
	/** Initialize your data structure here. */
	set<string> s;
	Trie() {
		s.clear();
	}
    
	/** Inserts a word into the trie. */
	void insert(string word) {
		s.insert(word);
	}
    
	/** Returns if the word is in the trie. */
	bool search(string word) {
		if(s.count(word) == 1) return 1;
		return 0;
	}
    
	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		for(auto ptr = s.begin(); ptr != s.end(); ptr++) {
			for(int i=0; i<prefix.size(); i++) {
				if(prefix[i] != (*ptr)[i]) break;
				if(i == prefix.size()-1) return 1;
			}
		}
		return 0;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */