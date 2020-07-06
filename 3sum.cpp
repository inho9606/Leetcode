// https://leetcode.com/problems/3sum/submissions/
// I. Sort nums and pick the most left element. If the element was already selected, then go to the next one.
// II. Get two elements among the rest of elements. Compare the most left value and the most right value for search except for the picked element.
// time: O(n^2) space: O(1)
// Runtime: 140 ms, faster than 42.33% of C++ online submissions for 3Sum.
// Memory Usage: 19.8 MB, less than 62.77% of C++ online submissions for 3Sum.
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;
		int i,j,k;
		sort(nums.begin(), nums.end());
		for(i=0; i<nums.size(); i++) {
			if(i>0 && nums[i] == nums[i-1]) continue;
			j=i+1;
			k=nums.size()-1;
			while(j<k) {
				if(nums[i]+nums[j]+nums[k] == 0) {
					answer.push_back({nums[i], nums[j], nums[k]});
					for(j=j+1; j<nums.size() && nums[j] == nums[j-1]; j++) ;
					for(k=k-1; k>i && nums[k] == nums[k+1]; k--) ;
				}
				else if(nums[i]+nums[j]+nums[k] < 0) j++;
				else k--;
			}
		}
		return answer;
	}
};