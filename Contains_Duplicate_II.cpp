// https://leetcode.com/problems/contains-duplicate-ii/submissions/
// �������� �ε��� ���� �ּ� ������ ã����� �����Ƿ�, �־��� �迭�� ���� �ε����� ������ ���� map�� ����. ���� �迭����  �����ִ� ���� map�� ������ �ش� ���� Ű���� ���� value�� ���� �ε����� ���̸� ���ؼ� k���� ���� Ʈ�� ��ȯ, �ƴϸ� map�� value�� ���� �ε����� ������Ʈ.
// time: O(n)�� ����� O(nlogn?) map���� find ���� �ӵ��� �Ϲ������� O(logN)���� �˷��� �ֱ� ����, ������ unordered_map�� ��������Ƿ� logN���ٴ� ������.. space: O(n)
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int,int> indexes;
		unordered_map<int,int>::iterator ptr;
		for(int i=0; i<nums.size(); i++) {
			ptr = indexes.find(nums[i]);
			if(ptr != indexes.end()) {
				if(i - (*ptr).second <= k) return 1;
			}
			indexes[nums[i]] = i;
		}
		return 0;
	}
};