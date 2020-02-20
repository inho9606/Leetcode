// https://leetcode.com/problems/add-strings/submissions/
// Compute sum of two numbers from the most right of two strings num1 and num2. If the sum is grater than or equal to 10, find the first non-nine number from current number to left, and plus 1. All nine numbers between the current number and the first non-nine number should be zero.
// time: O(n) space: O(1) n is longer length between num1 and num2. 
// Runtime: 4 ms, faster than 92.58% of C++ online submissions for Add Strings.
// Memory Usage: 9.2 MB, less than 39.13% of C++ online submissions for Add Strings.
class Solution {
public:
	string addStrings(string num1, string num2) {
		int i=num1.size()-1, j=num2.size()-1, ii, jj;
		while(i>=0 && j>=0) {
			if(num1[i]+num2[j]-96 >= 10) {
				for(ii=i-1; ii>=0 && num1[ii] == '9'; ii--)
					num1[ii] = 48;
				if(ii == -1) { num1.insert(0, "1"); i++; }
				else num1[ii] += 1;
			}
			num1[i] = (num1[i]+num2[j]-96)%10+48;
			i--;
			j--;
		}
		while(j>=0)
			num1.insert(0, to_string(num2[j--]-48));
		return num1;
	}
};