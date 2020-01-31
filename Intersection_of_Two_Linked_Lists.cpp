// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
// time: O(n) more exactly: 2n space: O(1)
// tail���� ���ϴٰ� �ּҰ��� �޶����� �κ� ������ �����ζ�� �� �� ������, �־��� �ڷᱸ������ prev�� ���� �����Ͱ� ����. ���� ���ο� ����Ʈ�� ����ų� �� ����Ʈ�� ��� ���� ���� �� �� ���� ��ŭ�� ���Ѵ�.
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