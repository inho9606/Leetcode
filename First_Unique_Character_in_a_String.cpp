// https://leetcode.com/problems/first-unique-character-in-a-string/submissions/
// Count each alphabets in given string s, and check it's index if there is a leeter that exists only one. Compare the indices of only one existing letters, and return the minimum one.
// time: almost O(n), space: O(1)
// Runtime: 36 ms, faster than 92.90% of C++ online submissions for First Unique Character in a String.
// Memory Usage: 12.9 MB, less than 64.06% of C++ online submissions for First Unique Character in a 
class Solution {
public:
	int firstUniqChar(string s) {
		int answer = INT_MAX;
		vector<int> counts(26, 0);
		for(int i=0; i<s.size(); i++)
			counts[s[i]-'a'] += 1;
		for(int i=0; i<26; i++) {
			if(counts[i] == 1) {
				for(int j=0; j<s.size(); j++) {
					if(s[j] == i+'a') {
						if(j < answer) answer = j;
						else break;
					}
				}
			}
		}
		if(answer == INT_MAX) return -1;
		return answer;
	}
};

/*
* O(nlogn) solution with map
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char,int> indices;
		unordered_map<char,int>::iterator ptr;
		int answer = INT_MAX;
		for(int i=0; i<s.size(); i++) {
			ptr = indices.find(s[i]);
			if(ptr == indices.end())
				indices[s[i]] = i;
			else
				indices[s[i]] = -1;
		}
		for(ptr=indices.begin(); ptr != indices.end(); ptr++) {
			if(ptr->second == -1) continue;
			if(ptr->second < answer)
				answer = ptr->second;
		}
		if(answer == INT_MAX) return -1;
		return answer;
	}
};
*/