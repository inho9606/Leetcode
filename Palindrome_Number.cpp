// https://leetcode.com/problems/palindrome-number/submissions/
// Level: Easy, time: O(x/10+x/100)
class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0) return 0;
		int n=0;
		for(n=1; x / n >= 10; n*=10) ;
		for(int i=x; i>0; ) {
			if(i/n != i%10) return 0;
			i = (i%n) - (i%10);
			if(i >= 10) i/=10;
			n /= 10;
			if(n>=10) n/=10;
		}
	return 1;
	}
};