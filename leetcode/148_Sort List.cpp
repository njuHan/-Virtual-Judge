#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// �ݹ�鲢���򣬿ռ临�ӶȲ���O(1)
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast && fast->next) //�ҵ������м�
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* head2 = slow->next; //�ڶ��������ͷ���
		slow->next = NULL;
		ListNode* ans = merge(sortList(head), sortList(head2));
		return ans;
		
	}
	// ���� �ϲ��� �ռ临�Ӷ�O(1)
	ListNode* sortList2(ListNode* head) 
	{
		int cmpSize = 1, sortedSize = 0;
		ListNode tempHead(0);
		ListNode* last = &tempHead;
		last->next = head;
		int len = getLen(head);
		//�ϲ���ʼ���±꣬ ����A�� ����B
		int start = 0, lenA, lenB; 
		ListNode* pos, *headA, *headB;
		while (cmpSize<len)
		{
			last = &tempHead; //����ϲ�����ĵط�
			start = 0;  //��ʼ�±꣬�����жϽ���
			pos = tempHead.next; //��¼headA��ʼ�ĵ�ַ
			while (start<len)
			{
				lenA = min(cmpSize, len - start);
				lenB = min(cmpSize, len - start - lenA);
				headA = pos;
				//�����������ó���, ��βNULL
				//����posΪ��һ�αȽϵĵط�
				for (int i = 0; i < lenA-1; i++) pos = pos->next;
				headB = pos->next;
				pos->next = NULL;
				pos = headB;
				if (lenB > 0) //���lenB==0��pos = NULL;
				{
					for (int i = 0; i < lenB - 1; i++) pos = pos->next;
					ListNode* temp = pos->next;
					pos->next = NULL;
					pos = temp;
				}
				//�ϲ���������
				while (headA || headB)
				{
					if (headA && (!headB || headB->val >= headA->val))
					{
						last = last->next = headA;
						headA = headA->next;
					}
					if (headB && (!headA || headA->val >= headB->val))
					{
						last = last->next = headB;
						headB = headB->next;
					}
				}
				last->next = NULL;
				start += (lenA + lenB);
			}
			cmpSize = cmpSize << 1;
		}
		return tempHead.next;

	}
private:
	ListNode* merge(ListNode* head1, ListNode* head2)
	{
		ListNode temp(0);
		ListNode* tail = &temp;
		tail->next = NULL;
		while (head1 || head2)
		{
			if (head1 && (!head2 || head2->val >= head1->val))
			{
				tail = tail->next = head1;
				head1 = head1->next;
			}
			if (head2 && (!head1 || head1->val >= head2->val))
			{
				tail = tail->next = head2;
				head2 = head2->next;
			}
		}
		tail->next = NULL;
		return temp.next;
	}

	int getLen(ListNode* node)
	{
		int n = 0;
		while (node)
		{
			n++;
			node = node->next;
		}
		return n;
	}
};

int main()
{

	vector<int> vec = { 100, 4, 200, 1, 3, 2 };

	system("pause");
	return 0;
}