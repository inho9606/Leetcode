// https://leetcode.com/problems/odd-even-jump/submissions/
// I. From the end of the array, record index where the current index can jump the farthest position.
// II. If the odd number jump can reach out the end of array, then it can be counted because the second jump must be next to the first jump.
// III. Record the value and index into map. And use lower_bound and upper_bound to find the next available jump index to speed up.
// time: O(nlogn) space: O(n)
// Runtime: 204 ms, faster than 62.54% of C++ online submissions for Odd Even Jump.
// Memory Usage: 34.1 MB, less than 33.72% of C++ online submissions for Odd Even Jump.
class Solution {
public:
	int oddEvenJumps(vector<int>& A) {
		int answer=0;
		vector<vector<int>> dp(A.size(), vector<int>(2, 0));
		map<int,int> m;
		dp[A.size()-1][0] = A.size()-1;
		dp[A.size()-1][1] = A.size()-1;
		m[A[A.size()-1]] = A.size()-1;
		for(int i=A.size()-2; i>=0; i--) {
			auto ptr = m.lower_bound(A[i]);
			if(ptr != m.end())
				dp[i][0] = dp[ptr->second][1];
			ptr = m.upper_bound(A[i]);
			if(ptr != m.begin())
				dp[i][1] = dp[(--ptr)->second][0];
			m[A[i]] = i;
			if(dp[i][0] == A.size()-1) answer+=1;
		}
		return answer+1;
	}
};
/*
* O(n^2) solution
class Solution {
public:
	int oddEvenJumps(vector<int>& A) {
		int answer=0, k;
		vector<vector<int>> dp(A.size(), vector<int>(2, 0));
		dp[A.size()-1][0] = A.size()-1;
		dp[A.size()-1][1] = A.size()-1;
		for(int i=A.size()-2; i>=0; i--) {
			k = i;
			for(int j=i+1; j<A.size(); j++) {
				if(k==i && A[k] <= A[j]) k=j;
				else if(k!=i && A[i] <= A[j] && A[j] < A[k]) k = j;
			}
			if(k!=i) dp[i][0] = dp[k][1];
			k = i;
			for(int j=i+1; j<A.size(); j++) {
				if(k==i && A[k] >= A[j]) k = j;
				else if(k!=i && A[i] >= A[j] && A[j] > A[k]) k = j;
			}
			if(k!=i) dp[i][1] = dp[k][0];
			if(dp[i][0] == A.size()-1) answer+=1;
//			if(dp[i][1] == A.size()-1) answer+=1;
		}
		return answer+1;
	}
};
*/