// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/submissions/
// I. Record each numbers in set to get the smallest number and largest number.
// II. If the distance between largest and smallest number is less than or equal to limit, update the length of the range as answer. If not, then erase the starting index element from set and move the starting index to the next different number.
// time: O(nlogn) space: O(n)
// Runtime: 340 ms, faster than 66.49% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
// Memory Usage: 62.8 MB, less than 42.70% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		int answer=0, large, small, i=0, j=0;
		set<int> s;
		while(i<nums.size() && j<nums.size()) {
			s.insert(nums[j]);
			large = *s.rbegin();
			small = *s.begin();
			if(large-small <= limit) {
				answer = max(answer, (j-i)+1);
				j++;
			}
			else {
				s.erase(nums[i]);
				for(int t=nums[i]; nums[i] == t; i++) ;
			}
		}
		return answer;
	}
};

/* Brute Force Solution
* time: O(n^2) space: O(n)
class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		int answer=0, large=INT_MIN, small=INT_MAX;
		for(int i=0; i<nums.size(); i++) {
			large = INT_MIN; small = INT_MAX;
			for(int j=i; j<nums.size(); j++) {
				if(nums[j] > large) large = nums[j];
				if(nums[j] < small) small = nums[j];
				if(large-small > limit) {
					if(j-i > answer) answer = j-i;
					break;
				}
				if(j==nums.size()-1 && j+1-i > answer) answer = j+1-i;
			}
		}
		return answer;
	}
};
*/