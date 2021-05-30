// https://leetcode.com/problems/partition-labels/submissions/
// I. Get the beginning and last position of each letter in the given list.
// II. Sort the list by the beginning positions
// III. If the last position of one letter is less than the next one's beginning letter, then update the partition.
// Time: O(n) space: O(1)
// Runtime: 4 ms, faster than 80.86% of C++ online submissions for Partition Labels.
// Memory Usage: 6.7 MB, less than 48.28% of C++ online submissions for Partition Labels.

class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<int> answer;
		int b = 0, p = 0;
		vector<pair<int,int>> partition(26, {-1, -1});
		for(int i=0; i<s.size(); i++) {
			if (partition[s[i]-'a'].first == -1) partition[s[i]-'a'].first = i;
			partition[s[i]-'a'].second = i;
		}
		sort(partition.begin(), partition.end());
		for(int i=0; i<26; i++) {
			if(partition[i].first == -1) continue;
			if(partition[i].first > p) {
				answer.push_back(p-b+1);
				b = partition[i].first;
			}
			if (partition[i].second > p) p = partition[i].second;
		}
		answer.push_back(p-b+1);
		return answer;
	}
};