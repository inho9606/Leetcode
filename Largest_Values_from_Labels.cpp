// https://leetcode.com/problems/largest-values-from-labels/submissions/
// I. Make pairs values[i] and labels[i], and we  should be able to access from the largest value by decreasing order. So, use map datastructure.
// II. From the largest value, add the value into the answer. But, if a label that the added value has is already used use_limit times, then we can't add the value.
// III. Repeat II until values are used num_wanted times.
// time: O(nlogn) space: O(n)
// Runtime: 112 ms, faster than 32.66% of C++ online submissions for Largest Values From Labels.
// Memory Usage: 22.9 MB, less than 22.62% of C++ online submissions for Largest Values From Labels.
class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		int answer=0, cnt=0;
		multimap<int,int> m;
		unordered_map<int,int> s;
		for(int i=0; i<values.size(); i++)
			m.insert({values[i], labels[i]});
		for(auto ptr = m.rbegin(); ptr!=m.rend(); ptr++) {
			s[ptr->second] += 1;
			if(s[ptr->second] <= use_limit) { answer += ptr->first; cnt+=1; }
			else s[ptr->second] -= 1;
			if(cnt == num_wanted) break;
		}
		return answer;
	}
};