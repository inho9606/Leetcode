// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
// time: O(n) more exactly: 2n space: O(1)
// tail부터 비교하다가 주소값이 달라지는 부분 이전이 교차로라고 할 수 있지만, 주어진 자료구조에서 prev로 가는 포인터가 없다. 따라서 새로운 리스트를 만들거나 각 리스트의 노드 수를 구한 후 그 차이 만큼만 비교한다.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptr1, *ptr2;
		int a=0, b=0;
		for(ptr1=headA; ptr1!=NULL; ptr1=ptr1->next) a+=1;
		for(ptr2=headB; ptr2!=NULL; ptr2=ptr2->next) b+=1;
		ptr1= headA;
		ptr2 = headB;
		if(a>b) {
			for(int i=0; i<a-b; i++) ptr1=ptr1->next;
		}
		else {
			for(int i=0; i<b-a; i++) ptr2=ptr2->next;
		}
		while(ptr1 != NULL || ptr2==NULL) {
			if(ptr1 == ptr2) return ptr1;
			ptr1 = ptr1->next;
			ptr2=ptr2->next;
		}
		return NULL;
	}
};