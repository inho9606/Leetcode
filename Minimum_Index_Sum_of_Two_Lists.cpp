// https://leetcode.com/problems/minimum-index-sum-of-two-lists/submissions/
// I. Convert list1 and list2 into map datastructure
// II. If there exists mutual data in m1 and m2, then keep it in a new map with sum of its index.
// III. Find the minimum ㅍ미ㅕㄷㄴ ㅑㅜ 솓 new map.
// time: O(n+mlogn+l) m is the length of list1, n is the length of list2, l is the length of items included in  both lists.
// Runtime: 124 ms, faster than 46.29% of C++ online submissions for Minimum Index Sum of Two Lists.
// Memory Usage: 27.9 MB, less than 100.00% of C++ online submissions for Minimum Index Sum of Two 
class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string,int> m1, m3;
		int least=INT_MAX, index;
		vector<string> answer;
		for(int i=0; i<list1.size(); i++)
			m1[list1[i]] = i;
		for(int i=0; i<list2.size(); i++) {
			if(m1.count(list2[i]) == 1) {
				index = m1[list2[i]] + i;
				m3[list2[i]] = index;
				if(index < least) least = index;
			}
		}
		for(auto ptr = m3.begin(); ptr != m3.end(); ptr++) {
			if(ptr->second == least) answer.push_back(ptr->first);
		}
		return answer;
	}
};