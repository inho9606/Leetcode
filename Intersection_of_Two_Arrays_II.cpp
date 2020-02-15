// https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/
// use two multisets.
// followup question: I can say this solution is O(nlogn) as everage time by using sets. STD::sort  takes O(n^2) if the given arrays are already sorted  because STD::sort is based on quick sort.
// time: O(nlogn) space: O(n)
// Runtime: 8 ms, faster than 76.34% of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage: 10.1 MB, less than 7.14% of C++ online submissions for Intersection of Two Arrays II.
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer;
		multiset<int> a, b;
		multiset<int>::iterator t;
		for(int i=0; i<nums1.size(); i++)
			a.insert(nums1[i]);
		for(int i=0; i<nums2.size(); i++)
			b.insert(nums2[i]);
		if(a.size() < b.size()) {
			for(multiset<int>::iterator it=a.begin(); it != a.end(); it++) {
				t = b.find(*it);
				if(t != b.end()) {
					answer.push_back(*it);
					b.erase(t);
				}
			}
		}
		else {
			for(multiset<int>::iterator it=b.begin(); it != b.end(); it++) {
				t = a.find(*it);
				if(t != a.end()) {
					answer.push_back(*it);
					a.erase(t);
				}
			}
		}
		return answer;
	}
};