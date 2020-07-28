// https://leetcode.com/problems/complex-number-multiplication/submissions/
// I. (a+b)(c+d) = ac+ad+bc+bd
// II. Since i^2 is -1, we can say the final equation is (ac-bd) + (ad+bc)*i.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complex Number Multiplication.
// Memory Usage: 5.9 MB, less than 93.33% of C++ online submissions for Complex Number Multiplication.
class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		string answer = "";
		int t1=0, t2=0, minus=0, c=0, d=0, e=0, f=0, i=0, j=0;
		while(i<a.size() && j<b.size()) {
			if(a[i] == '-' && b[j] == '-') {minus = 2; i++; j++; }
			else if(a[i] == '-') {minus = 1; i++; }
			else if(b[j] == '-') {minus = -1; j++; }
			if(a[i] >= '0' && a[i] <='9') t1 = (t1*10)+a[i++]-48;
			if(b[j] >= '0' && b[j] <= '9') t2 = (t2*10) + b[j++]-48;
			if(a[i] == '+' && b[j] == '+') {
				if(minus == 2) { t1*=-1; t2*=-1; }
				else if(minus == 1) t1 *= -1;
				else if(minus == -1) t2 *= -1;
				c=t1; e=t2;
				t1=0; t2=0;
				i+=1; j+=1;
				minus = 0;
			}
			else if(a[i] == 'i' && b[j] == 'i') {
				if(minus == 2) { t1*=-1; t2*=-1; }
				else if(minus == 1) t1 *= -1;
				else if(minus == -1) t2 *= -1;
				d=t1; f=t2;
				break;
			}
		}
		t1 = (c*e) + (d*f*-1);
		answer += to_string(t1) + "+";
		t2 = (c*f) + (d*e);
		answer += to_string(t2) + "i";
		return answer;
	}
};