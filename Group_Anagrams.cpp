// https://leetcode.com/problems/group-anagrams/submissions/
// I. Sort each word alphabetically in the given string.
// II. Make a group using map as sorted word for key and original word for value.
// III. Keep it into the answer container from map.
// time: Onlogn) space: O(n)
// Runtime: 72 ms, faster than 67.28% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.4 MB, less than 73.02% of C++ online submissions for Group Anagrams.
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> answer;
		string t;
		unordered_map<string,vector<string>> m;
		for(int i=0; i<strs.size(); i++) {
			t = strs[i];
			sort(t.begin(), t.end());
			m[t].push_back(strs[i]);
		}
		for(auto ptr = m.begin(); ptr != m.end(); ptr++)
			answer.push_back(ptr->second);
		return answer;
	}
};

/** Brute Force method.
* time: O(n^2) space: O(1)
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> answer;
		vector<string> t2;
		vector<int> c1(26), c2(26);
		vector<bool> visited(strs.size(), 0);
		int j=0, anagram;
		for(int i=0; i<strs.size(); i++) {
			if(visited[i] == 1) continue;
			t2.clear();
			for(int t=0; t<26; t++)
				c1[t] = 0;
			for(int t=0; t<strs[i].size(); t++)
				c1[strs[i][t]-'a'] += 1;
			visited[i] = 1;
			t2.push_back(strs[i]);
			for(int j = i+1; j<strs.size(); j++) {
				if(visited[j] == 1) continue;
				anagram = 1;
				for(int t=0; t<26; t++)
					c2[t] = 0;
				for(int t=0; t<strs[j].size(); t++)
					c2[strs[j][t]-'a'] += 1;
				for(int t=0; t<26; t++) {
					if(c1[t] != c2[t]) { anagram=0; break; }
				}
				if(anagram == 1) {
					t2.push_back(strs[j]);
					visited[j] = 1;
				}
			}
			if(t2.size()!=0) answer.push_back(t2);
		}
		return answer;
	}
};
*/