// https://leetcode.com/problems/next-greater-element-iii/submissions/
// I. Convert given integer into string to modify the number.
// II. Find the last position increasing value, which should be sorted from that point to the end. It's to make it the next grater number.
// III. After sorting, find the minimum value in sorted range.
// IV. Swap the previous element before sorted range and the minimum value in sorted range.
// time: O(nlogn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
// Memory Usage: 5.9 MB, less than 92.00% of C++ online submissions for Next Greater Element III.
class Solution {
public:
	int nextGreaterElement(int n) {
		int answer=-1, t=-1;
		string s = to_string(n);
		for(int i=0; i<s.size(); i++) {
		if(i==s.size()-1 && t==-1) return -1;
			if(s[i] < s[i+1]) {
				t = i+1;
			}
		}
		sort(s.begin()+t, s.end());
		for(int i=t; i<s.size(); i++) {
			if(s[i] > s[t-1]) {
				swap(s[t-1], s[i]);
				break;
			}
		}
		if(stoll(s) <= INT_MAX) answer = stoi(s);
		return answer;
	}
};