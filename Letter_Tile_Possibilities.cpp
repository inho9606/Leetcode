// https://leetcode.com/problems/letter-tile-possibilities/submissions/
// I. Record what characters can be chosen on map.
// II. For each turn, choose one among available characters from map until mpa doesn't have available element.
// time: O(n) space: O(n)
// Runtime: 208 ms, faster than 23.92% of C++ online submissions for Letter Tile Possibilities.
// Memory Usage: 44.6 MB, less than 5.07% of C++ online submissions for Letter Tile Possibilities.
class Solution {
public:
	void make(vector<string>& s, unordered_map<char,int> m, char ch, string t) {
		t += ch;
		s.push_back(t);
		m[ch] -= 1;
		for(auto p=m.begin(); p!=m.end(); p++) {
			if(p->second > 0)
				make(s, m, p->first, t);
		}
	}
	int numTilePossibilities(string tiles) {
		vector<string> s;
		unordered_map<char,int> m;
		for(int i=0; i<tiles.size(); i++)
			m[tiles[i]] += 1;
		for(unordered_map<char,int>::iterator  p=m.begin(); p!=m.end(); p++) {
			make(s, m, p->first, "");
		}
		return s.size();
	}
};