#include <iostream>

using namespace std;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

void addToTail(ListNode** pHead, int value){
	ListNode* new_node = new ListNode;
	new_node->m_nValue = value;
	new_node->m_pNext = NULL;

	if (NULL == *pHead){
		*pHead = new_node;
	}
	else{
		ListNode* dummy = *pHead;
		while (dummy->m_pNext != NULL){
			dummy = dummy->m_pNext;
		}
		dummy->m_pNext = new_node;
	}
}

void removeNode(ListNode** pHead, int value){
	if (NULL == *pHead)
		return;
	
	ListNode* dummy = *pHead;

	if ((*pHead)->m_nValue == value){
		ListNode* tmp = *pHead;
		*pHead = (*pHead)->m_pNext;
		delete tmp;
		return;
	}

	while (dummy->m_pNext != NULL && dummy->m_pNext->m_nValue != value){
		dummy = dummy->m_pNext;
	}

	if (dummy->m_pNext != NULL){
		ListNode* tmp = dummy->m_pNext;
		dummy->m_pNext = dummy->m_pNext->m_pNext;
		delete tmp;
	}
}
int main(){
	ListNode* pHead = NULL;
	cout << &pHead << endl;
	addToTail(&pHead, 2);
	addToTail(&pHead, 3);
	addToTail(&pHead, 4);
    removeNode(&pHead, 2);
	system("pause");
    return 0;
}
