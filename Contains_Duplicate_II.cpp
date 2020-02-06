// https://leetcode.com/problems/contains-duplicate-ii/submissions/
// 문제에서 인덱스 간의 최소 조건을 찾으라고 했으므로, 주어진 배열의 값과 인덱스를 쌍으로 갖는 map을 생성. 현재 배열에서  보고있는 값이 map에 있으면 해당 값의 키값에 딸린 value가 현재 인덱스의 차이를 비교해서 k보다 작은 트루 반환, 아니면 map의 value를 현재 인덱스로 업데이트.
// time: O(n)에 가까운 O(nlogn?) map에서 find 연산 속도가 일반적으로 O(logN)으로 알려져 있기 때문, 하지만 unordered_map을 사용했으므로 logN보다는 빠를것.. space: O(n)
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