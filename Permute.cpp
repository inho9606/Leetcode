// Using Recursion. Check if all elements are used or not. 
// time: O(n^2) space: O(n)
// Runtime: 8 ms, faster than 98.74% of C++ online submissions for Permutations.
// Memory Usage: 9.7 MB, less than 35.82% of C++ online submissions for Permutations.
class Solution {
public:
	void solution(vector<int>& nums, vector<vector<int> >& answer, vector<int> v, vector<int> t, int cur) {
		bool done = 1;
		t.push_back(nums[cur]);
		v[cur] = 1;
		for(int i=0; i<v.size(); i++) {
			if(v[i] == 0) {
				done = 0;
				solution(nums, answer, v, t, i);
			}
		}
		if(done == 1) answer.push_back(t);
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > answer;
		vector<int> visited(nums.size(),0);
		vector<int> t;
		for(int i=0; i<nums.size(); i++)
			solution(nums, answer, visited, t, i);
		return answer;
	}
};