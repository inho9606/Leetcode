// https://leetcode.com/problems/valid-anagram/submissions/
// check the number of each characters in string s and t. And compare the number, return false if the number is different.
// follow up: if the input character is an unicode or ASCII code, the size of vector to check the number of each characters should be 128, 8-bit.
// time: O(n), space: O(n)
// Runtime: 8 ms, faster than 98.44% of C++ online submissions for Valid Anagram.
// Memory Usage: 9.4 MB, less than 82.09% of C++ online submissions for Valid Anagram.
class Solution {
public:
	bool isAnagram(string s, string t) {
		if(s.size() != t.size()) return 0;
		vector<int> v(128, 0);
		for(int i=0; i<s.size(); i++)
			v[s[i]] += 1;
		for(int i=0; i<t.size(); i++)
			v[t[i]] -= 1;
		for(int i=0; i<128; i++)
			if(v[i] != 0) return 0;
		return 1;
	}
};

// + sort can solve this problem
/**
// Sort the given strings, and check if two strings are same or not.
// time: O(nlogn) space: O(1)
class Solution {
public:
	bool isAnagram(string s, string t) {
		if(s.size() != t.size()) return 0;
		sort(t.begin(), t.end());
		sort(s.begin(), s.end());
		for(int i=0; i<s.size(); i++) {
			if(s[i] != t[i]) return 0;
		}
		return 1;
	}
};
*//