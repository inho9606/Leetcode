// https://leetcode.com/problems/confusing-number/
// I. If the given number has 2, 3, 4, 5 or 7, then it should be an invalid number.
// II. Construct a new number which is reverse of the given number, and 6 and 9 should be opposite.
// III. If the constructed number and given number are same, then return false because the rotated number is same as the original number is. Otherwise, return true.
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Confusing Number.
// Memory Usage: 6 MB, less than 70.06% of C++ online submissions for Confusing Number.
class Solution {
public:
	bool confusingNumber(int N) {
		int d=0;
		for(int t=N; t>0; t/=10) {
			if(t%10 == 2 || t%10 == 3 || t%10 == 4 || t%10 == 5 || t%10== 7) return 0;
			d*=10;
			if(t%10 == 6) d+=9;
			else if(t%10 == 9) d += 6;
			else d += t%10;
		}
		if(d==N) return 0;
		return 1;
	}
};