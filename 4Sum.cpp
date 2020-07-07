// https://leetcode.com/problems/4sum/submissions/
// My solution is like the solution of 3sum
// time: O(n^3) space: O(1)
// Runtime: 164 ms, faster than 23.11% of C++ online submissions for 4Sum.
// Memory Usage: 13.1 MB, less than 74.51% of C++ online submissions for 4Sum.
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> answer;
		int i,j, k, l;
		sort(nums.begin(), nums.end());
		for(i=0; i<nums.size(); i++) {
			if(i>0 && nums[i] == nums[i-1]) continue;
			for(j=i+1; j<nums.size(); j++) {
				if(j>i+1 && nums[j] == nums[j-1]) continue;
				k=j+1;
				l=nums.size()-1;
				while(k<l) {
					if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
						answer.push_back({nums[i],nums[j],nums[k],nums[l]});
						for(k=k+1; k<l && nums[k-1] == nums[k]; k++) ;
						for(l=l-1; k<l && nums[l] == nums[l+1]; l--) ;
					}
					else if(nums[i]+nums[j]+nums[k]+nums[l] > target) l--;
					else k++;
				}
			}
		}
		return answer;
	}
};