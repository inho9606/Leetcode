// https://leetcode.com/problems/compare-version-numbers/submissions/
// I. Split numbers by '.'. And compare two numbers.
// stoi도 있었다..
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Compare Version Numbers.
// Memory Usage: 6.1 MB, less than 98.12% of C++ online submissions for Compare Version Numbers.
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int t1, t2, i=0, ii, j=0, jj;
		while(i<version1.size() && j<version2.size()) {
			for(; i<version1.size() && version1[i] == '0'; i++) ;
			if(i == version1.size() || version1[i] == '.') {
				t1 = 0;
				ii = i;
			}
			else {
				for(ii=i; ii<version1.size() && version1[ii] != '.'; ii++) ;
				t1 = atoi(version1.substr(i, ii-i).c_str());
			}
			for(; j<version2.size() && version2[j] == '0'; j++) ;
			if(j == version2.size() || version2[j] == '.') {
				t2 = 0;
				jj = j;
			}
			else {
				for(jj=j; jj<version2.size() && version2[jj] != '.'; jj++) ;
				t2 = atoi(version2.substr(j, jj-j).c_str());
			}
			if(t1<t2) return -1;
			else if(t1>t2) return 1;
			i = ii+1;
			j = jj+1;
		}
		while(i<version1.size()) {
			if(version1[i] >= '1' && version1[i] <= '9') return 1;
			i++;
		}
		while(j<version2.size()) {
			if(version2[j] >= '1' && version2[j] <= '9') return -1;
			j++;
		}
		return 0;
	}
};