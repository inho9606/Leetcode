// https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/
// I. Find the target with binary search.
// II. If the target is found,  return the next one of the target. Otherwise, return the first element in the list.
// time: O(logn) space: O(1)
// Runtime: 28 ms, faster than 85.98% of C++ online submissions for Find Smallest Letter Greater Than Target.
// Memory Usage: 16.1 MB, less than 40.63% of C++ online submissions for Find Smallest Letter Greater Than Target.
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int s=0, e=letters.size()-1, m;
		while(s<=e) {
			m = (s+e)/2;
			if(m < letters.size()-1 && letters[m] <= target && letters[m+1] > target) return letters[m+1];
			else if(m == letters.size()-1 && target >= letters[m]) break;
			else if(letters[m] == target) {
				for(; m<letters.size() && letters[m] == target; m++) ;
				if(m==letters.size()) break;
				return letters[m];
			}
			else if(letters[m] < target) s = m+1;
			else if(letters[m] > target) e = m-1;
		}
		return letters[0];
	}
};

/**
* O(n) solution
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		for(int i=0; i<letters.size(); i++) {
			if(letters[i] > target) return letters[i];
		}
		return letters[0];
	}
};
*/