// https://leetcode.com/problems/add-binary/submissions/
class Solution {
public:
	string addBinary(string a, string b) {
		int i=0,j=0, k=0;
		string r = "";
		if(a.size() > b.size()) {
			for(i=0; i<a.size()-b.size(); i++)
				r += a[i];
		}
		if(b.size() > a.size()) {
			for(j=0; j<b.size()-a.size(); j++)
				r += b[j];
		}
		while(i<a.size() && j < b.size()) {
			if(a[i] != b[j]) r += '1';
			else if(a[i] == '0' && b[j] == '0') r += '0';
			else if(a[i] == '1' && b[j] == '1') {
				for(k=r.size()-1; k>=0 && r[k] == '1'; k--) ;
				if(k<0) { k = 0; r.insert(0, "1"); }
				else r[k] = '1';
				for(k = k+1; k<r.size(); k++) r[k] = '0';
				r += '0';
			}
		i++; j++;
		}
		return r;
	}
};