// https://leetcode.com/problems/isomorphic-strings/submissions/
// ������ �˻�. ���� �� �� ����. ���ĺ� ������ ���ڷ� ����. �� ���� ������ ������ Ʈ��.
// time: O(n^2) space: O(n)
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if(s.size() == 0) return 1;
		int a_cnt=1, b_cnt=1, j, n = s.size();
		vector<int> a(n), b(n);
		for(int i=0; i<n; i++) {
			if(i==0) { a[i] = 0; b[i] = 0; }
			else {
				for(j=0; j<i; j++)
					if(s[i]==s[j]) { a[i] = a[j]; break; }
				if(j==i) a[i] = a_cnt++;
				for(j=0; j<i; j++)
					if(t[i]==t[j]) { b[i] = b[j]; break; }
				if(j==i) b[i] = b_cnt++;
				if(a[i] != b[i]) return 0;
			}
		}
		return 1;
	}
};