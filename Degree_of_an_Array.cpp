// https://leetcode.com/problems/degree-of-an-array/submissions/
// I. Find the meximum number of how many appears in the given array
// II. Get the distance between the first element and the last element of the meximum frequency number
// time: O(50000n+50000) space: O(50000)
// Runtime: 472 ms, faster than 5.07% of C++ online submissions for Degree of an Array.
// Memory Usage: 44.8 MB, less than 9.09% of C++ online submissions for Degree of an Array.
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
	int answer=INT_MAX, n=0, s, e;
	vector<int> freq(50000, 0);
	for(int i=0; i<nums.size(); i++) {
		freq[nums[i]] += 1;
		if(freq[nums[i]] > n) n= freq[nums[i]];
	}
	for(int k = 0; k < 50000; k++) {
		if(freq[k] == n) {
			s = -1; e=-1;
			for(int i=0; i<nums.size(); i++) {
				if(nums[i] == k && s==-1) s = i;
				if(nums[i] == k && s != -1 && i > e) e = i;
			}
			if(e-s+1 < answer) answer = e-s+1;
		}
	}
	return answer;
	}
};

/*
* Another solution with Map
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
	int answer=INT_MAX, n=0, s, e;
	unordered_map<int,int> freq;
	for(int i=0; i<nums.size(); i++) {
		freq[nums[i]] += 1;
		if(freq[nums[i]] > n) n= freq[nums[i]];
	}
	for(auto ptr = freq.begin(); ptr != freq.end(); ptr++) {
		if(ptr->second == n) {
			s = -1; e=-1;
			for(int i=0; i<nums.size(); i++) {
				if(nums[i] == ptr->first && s==-1) s = i;
				if(nums[i] == ptr->first && s != -1 && i > e) e = i;
			}
			if(e-s+1 < answer) answer = e-s+1;
		}
	}
	return answer;
	}
};
*/