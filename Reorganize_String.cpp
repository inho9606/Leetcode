// https://leetcode.com/problems/reorganize-string/submissions/
//I. Count each characters, and the maximum character should not be great than the half of given string's length.
// II. Fill the string with the most frequent character one by one.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reorganize String.
// Memory Usage: 6.2 MB, less than 79.15% of C++ online submissions for Reorganize String.
class Solution {
public:
	string reorganizeString(string S) {
		vector<int> cnt(26, 0);
		int max_cnt = 0, i;
		for(i=0; i<S.size(); i++) {
			cnt[S[i]-'a'] += 1;
			if(cnt[S[i]-'a'] > cnt[max_cnt])
				max_cnt = S[i]-'a';
		}
		if((S.size()%2==0 && cnt[max_cnt] > S.size()/2) || (S.size()%2==1 && cnt[max_cnt] > S.size()/2+1)) return "";
		for(i=0; i<S.size() && cnt[max_cnt] > 0; i+=2) {
			S[i] = max_cnt+'a';
			cnt[max_cnt] -= 1;
		}
		for(int j=0; j<26; j++) {
			while(cnt[j] > 0) {
				if(i >= S.size()) i = 1;
				S[i] = j+'a';
				cnt[j] -= 1;
				i += 2;
			}
		}
		return S;
	}
};