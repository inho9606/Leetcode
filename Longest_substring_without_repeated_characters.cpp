// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
// I. Record the index where each character located.
// II. The starting pointer moves after the previous character's index if a repeated character is found. And initialize indices located before the new starting pointer.
// III. Check if new range is longer than previous one.
// time: O(n) space: O(128)
// Runtime: 20 ms, faster than 77.12% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 7.8 MB, less than 76.48% of C++ online submissions for Longest Substring Without Repeating Characters.
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int answer=0, start=0;
		vector<int> a(128, -1);
		for(int i=0; i<s.size(); i++) {
			if(a[s[i]] != -1) {
				if(i-start > answer) answer = i-start;
				start = a[s[i]]+1;
				for(int j=0; j<128; j++) {
					if(a[j] < start) a[j] = -1;
				}
			}
			a[s[i]] = i;
			if(i == s.size()-1 && i-start+1 > answer) answer = i-start+1;
		}
		return answer;
	}
};