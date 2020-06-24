// https://leetcode.com/problems/design-hashset/submissions/
// Used mod operation as bucket value.
// Found it is almost fastest when bucket size is around 5000. Started slower over 10000.
// time: O(n/5000) space: O(n) n is the number of operations.
// Runtime: 160 ms, faster than 91.20% of C++ online submissions for Design HashSet.
// Memory Usage: 44.7 MB, less than 44.76% of C++ online submissions for Design HashSet.
class MyHashSet {
public:
	list<int> s[5000];
	MyHashSet() {
	}
	void add(int key) {
		int i=key%5000;
		for(auto ptr = s[i].begin(); ptr != s[i].end(); ptr++) {
			if(*ptr == key) return;
		}
		s[i].push_back(key);
	}
    
	void remove(int key) {
		int i=key%5000;
		for(auto ptr = s[i].begin(); ptr != s[i].end(); ptr++) {
			if(*ptr == key) {
				s[i].erase(ptr);
				return;
			}
		}
	}
    
	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int i=key%5000;
		for(auto ptr = s[i].begin(); ptr != s[i].end(); ptr++) {
			if(*ptr == key) return 1;
		}
		return 0;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */