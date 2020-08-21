// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/
// I. Find the most frequent number in each array.
// II. For each element which is not the most frequent number, check if another array has the most frequent number on the same index. If so, then it means those can be swapped.
// III. If the total number of swapped elements and the most frequent numbers is the original arrya's size, then the number of swapping can be answer. But we have to choose the less one between two compares.
// time: O(n) space: O(1)
// Runtime: 516 ms, faster than 13.97% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// Memory Usage: 111.8 MB, less than 46.32% of C++ online submissions for Minimum Domino Rotations For Equal Row.
class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int answer = -1, cnt=0, domino, n;
		vector<int> d(7, 0);
		for(int i=0; i<A.size(); i++)
			d[A[i]] += 1;
		cnt=0;
		for(int i=1; i<=6; i++) {
			if(d[i] > cnt) { cnt = d[i]; domino = i; }
		}
		n = 0;
		for(int i=0; i<A.size(); i++) {
			if(A[i] != domino && B[i] == domino) n+=1;
		}
		if(d[domino] + n == A.size()) answer = n;
		for(int i=1; i<=6; i++)
			d[i] = 0;
		for(int i=0; i<B.size(); i++)
			d[B[i]] += 1;
		cnt=0;
		for(int i=1; i<=6; i++) {
			if(d[i] > cnt) { cnt = d[i]; domino = i; }
		}
		n = 0;
		for(int i=0; i<B.size(); i++) {
			if(B[i] != domino && A[i] == domino) n+=1;
		}
		if(d[domino] + n == B.size() && (answer == -1 || n < answer)) answer = n;
		return answer;
	}
};