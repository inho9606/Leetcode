// Runtime: 260 ms, faster than 9.45% of C++ online submissions for Check If Array Pairs Are Divisible by k.
// Memory Usage: 81.5 MB, less than 7.80% of C++ online submissions for Check If Array Pairs Are Divisible by k.
// I. Keep the remander of each elements.
// II. Find cases that the each  elements need to be divisible by k.
// time: O(n^2logn) space: O(n)
class Solution {
public:
	bool canArrange(vector<int>& arr, int k) {
		unordered_map<int,int> m;
		int t;
		for(int i=0; i<arr.size(); i++) {
			t = arr[i] % k;
			if(m[-t]) m[-t] -= 1;
			else if(arr[i] < 0 && m[-k-t]) m[-k-t] -= 1;
			else if(m[k-t]) m[k-t] -= 1;
			else m[t] += 1;
		}
		for(auto i : m) {
			if(i.second) return 0;
		}
		return 1;
	}
};