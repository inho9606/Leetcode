// I. Sort the given array
// II. Check the difference between two elements
//  time: O(n^2) space: O(1)
// Runtime: 36 ms, faster than 66.17% of C++ online submissions for K-diff Pairs in an Array.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for K-diff Pairs in an Array.
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if(nums.size()==0) return 0;
		int answer=0;
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size()-1; i++) {
			if(i>0 && nums[i] == nums[i-1]) continue;
			for(int j=i+1; j<nums.size(); j++) {
				if(j>i+1 && nums[j] == nums[j-1]) continue;
				if(nums[j] - nums[i] == k) answer++;
				if(nums[j] - nums[i] > k) break;
			}
		}
		return answer;
	}
};