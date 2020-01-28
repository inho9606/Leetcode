// https://leetcode.com/problems/plus-one/submissions/
// time: O(n)
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i, n= digits.size()-1;
		if(digits[n] != 9) digits[n] += 1;
		else {
			for(i=n; i>=0 && digits[i] == 9; i--) ;
			if(i<0) { i = 0; digits.insert(digits.begin(), 1); }
			else digits[i] += 1;
			for(i = i+1; i<digits.size(); i++)
				digits[i] = 0;
		}
		return digits;
	}
};