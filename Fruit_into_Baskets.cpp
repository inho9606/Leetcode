// https://leetcode.com/problems/fruit-into-baskets/submissions/
// I. Need to record each fruits' starting point.
// II. If the third fruit found, update the length and fruits information. First fruit should be the one before new one, and should find it's starting point.
// time: O(n) space: O(1)
// Runtime: 220 ms, faster than 95.29% of C++ online submissions for Fruit Into Baskets.
// Memory Usage: 56.6 MB, less than 79.06% of C++ online submissions for Fruit Into Baskets.
class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int answer=0;
		int a=0, b=0, f1=-1, f2=-1;
		for(int i=0; i<tree.size(); i++) {
			if(i==0) f1=tree[i];
			else if(tree[i] != f1 && f2 == -1) { f2 = tree[i]; b = i; }
			else if(tree[i] != f1 && tree[i] != f2) {
				if(i-a > answer) answer = i-a;
				for(int j=i-1; j>=0 && tree[j] == tree[i-1]; j--) a = j;
				f1 = tree[i-1];
				f2 = tree[i];
				b=i;
			}
			if(i==tree.size()-1 && i+1-a > answer) answer = i+1-a;
		}
		return answer;
	}
};

/*
* Solution using map from discussboard. It's more effective on scale up system.
class Solution {
public:
int totalFruit(vector<int> &tree) {
unordered_map<int, int> count;
int i, j;
for (i = 0, j = 0; j < tree.size(); ++j) {
count[tree[j]]++;
if (count.size() > 2) {
if (--count[tree[i]] == 0)count.erase(tree[i]);
i++;
}
}
return j - i;
}
};
*/