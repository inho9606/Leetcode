// https://leetcode.com/problems/self-dividing-numbers/submissions/
// Just with Brute Force Technique
// time: O(n) space: O(1) n is right-left.
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
// Memory Usage: 6.5 MB, less than 65.00% of C++ online submissions for Self Dividing Numbers.
class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		int t;
		vector<int> answer;
		for(int i=left; i<=right; i++) {
			for(t=i; t>0; t/=10) {
				if(t%10==0 || i%(t%10) != 0) break;
			}
			if(t==0) answer.push_back(i);
		}
		return answer;
	}
};