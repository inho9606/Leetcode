// https://leetcode.com/problems/design-hashmap/submissions/
// Split the containers into 1000 by mod like hashset, and design new data; time.
// Runtime: 208 ms, faster than 72.15% of C++ online submissions for Design HashMap.
// Memory Usage: 46.6 MB, less than 78.09% of C++ online submissions for Design HashMap.
class MyHashMap {
public:
	typedef struct item {
		int k=-1, v=-1;
	}item;
	list<item> t[1000];
	int size=1000;
	MyHashMap() {
	}
    
	/** value will always be non-negative. */
	void put(int key, int value) {
		item temp;
		int i=key%size;
		for(auto ptr = t[i].begin(); ptr != t[i].end(); ptr++) {
			if((*ptr).k == key) {
				(*ptr).v = value;
				return;
			}
		}
		temp.k = key;
		temp.v = value;
		t[i].push_back(temp);
	}
    
	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int i=key%size;
		for(auto ptr = t[i].begin(); ptr != t[i].end(); ptr++) {
			if((*ptr).k == key) return (*ptr).v;
		}
		return -1;
	}
    
	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int i=key%size;
		for(auto ptr = t[i].begin(); ptr != t[i].end(); ptr++) {
			if((*ptr).k == key) { t[i].erase(ptr); break; }
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */