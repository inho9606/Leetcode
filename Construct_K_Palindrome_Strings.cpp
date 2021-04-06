// https://leetcode.com/problems/construct-k-palindrome-strings/submissions/
// I. Count odd numbers of characters, and if the number is greater than k, then return false. Return treu otherwise.
// time: O(n) space: O(1)
// Runtime: 28 ms, faster than 82.28% of C++ online submissions for Construct K Palindrome Strings.
// Memory Usage: 11.7 MB, less than 96.25% of C++ online submissions for Construct K Palindrome 
class Solution {
public:
	bool canConstruct(string s, int k) {
		if(s.size() == k) return 1;
		if(s.size() < k) return 0;
		vector<int> cnt(26, 0);
		int t = 0;
		for(int i=0; i<s.size(); i++)
			cnt[s[i]-'a'] += 1;
		for(int i=0; i<cnt.size(); i++) {
			if(cnt[i] % 2 == 1) t += 1;
		}
		return t <= k;
	}
};