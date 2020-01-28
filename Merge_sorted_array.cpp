// https://leetcode.com/problems/merge-sorted-array/submissions/
// needs optimization
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i=0,j=0,k=0;
		while(i<m+n && j<n) {
		if(i >= m+k && nums1[i] == 0) { nums1[i] = nums2[j]; i++; j++; }
			else if(nums1[i] <= nums2[j]) i++;
			else if(nums1[i] > nums2[j]) { nums1.insert(nums1.begin()+i, nums2[j]); nums1.pop_back(); i++; j++; k++; }
		}
	}
};