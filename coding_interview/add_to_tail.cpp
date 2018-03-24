#include <iostream>

using namespace std;

/*Linked List
 */
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

int main(){
	ListNode* pHead = NULL;
	cout << &pHead << endl;
	addToTail(&pHead, 2);
	system("pause");
    return 0;
}
