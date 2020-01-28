// https://leetcode.com/problems/implement-strstr/submissions/
// KMP study more
class Solution {
public:
	int strStr(string haystack, string needle) {
		if(needle.size() == 0) return 0;
		int i, j, n=needle.size();
		vector<int> failure(n,0);
		failure[0] = -1;
		for(j=1; j<n; j++) {
			i = failure[j-1];
			while(needle[j] != needle[i+1] && i>=0) i = failure[i];
			if(needle[i+1] == needle[j]) failure[j] = i+1;
			else failure[j] = -1;
		}
		i=0; j=0;
		while(i< haystack.size() && j < n) {
			if(haystack[i] == needle[j]) { i++; j++; }
			else if(j==0) i++;
			else j = failure[j-1] + 1;
		}
	if(j==n) return i-n;
	return -1;
	}
};