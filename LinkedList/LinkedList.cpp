#include "LinkedList.h"


Status InitList(LinkList& L)
{
	L = new Node;
	if (L == nullptr)
	{
		return ERROR;
	}

	L->next = nullptr;
	return OK;
}

Status DestroyList(LinkList& L)
{
	Node* p = L;
	Node* next_Node;

	while (p != nullptr)
	{
		next_Node = p->next;
		delete p;
		p = next_Node;
	}

	L = nullptr;

	return OK;
}

Status ClearList(LinkList L)
{
	Node* p = L->next;
	Node* next_Node;


	while (p != nullptr)
	{
		next_Node = p->next;
		delete p;
		p = next_Node;
	}

	return OK;
}

bool ListEmpty(const LinkList L)
{
	return L->next == nullptr;
}

int ListLength(const LinkList L)
{
	int length = 0;
	
	Node* p = L->next; // 应该从第一个开始

	while (p != nullptr)
	{
		length++;
		p = p->next;
	}

	return length;
}

Status GetElem(const LinkList L, int i, ElemType& e)
{
	if (i < 1 || i > ListLength(L))
	{
		return ERROR;
	}

	Node* p = L;

	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}

	e = p->data;

	return OK;
}

int LocateElem(const LinkList L, ElemType e)
{
	int i = 1;
	Node* p = L->next;

	while (p != nullptr) // 假如链表是空的 根本不会执行这行！
	{
		if (e == p->data)
		{
			return i;
		}
		p = p->next;
		i++;
	}

	return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType& pre_e)
{
	Node* p = L->next;

	while (p != nullptr)
	{
		if (p->next != nullptr && p->next->data == cur_e)
		{
			pre_e = p->data;
			return OK;
		}

		p = p->next;
	}

	return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType& next_e)
{
	Node* p = L->next;

	while (p != nullptr)
	{
		if (p->data == cur_e && p->next != nullptr)
		{
			next_e = p->next->data;
			return OK;
		}

		p = p->next;
	}

	return ERROR;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
	if (i < 1 || i > ListLength(L) + 1)
	{
		return ERROR;
	}

	Node* p = L;

	Node* new_Node = new Node;
	if (new_Node == nullptr)
	{
		return ERROR;
	}

	new_Node->data = e;

	for (int j = 0; j < i - 1; j++)
	{
		p = p->next;
	}

	new_Node->next = p->next;
	p->next = new_Node;

	return OK;
}

Status ListDelete(LinkList L, int i, ElemType& e)
{
	if (i < 1 || i > ListLength(L))
	{
		return ERROR;
	}

	Node* p = L;
	Node* delete_Node = nullptr;

	for (int j = 0; j < i - 1; j++)
	{
		p = p->next;
	}

	delete_Node = p->next;

	e = delete_Node->data;

	p->next = delete_Node->next;

	delete delete_Node;

	return OK;

}

void ListTraverse(const LinkList L)
{
	Node* p = L->next;

	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;
}

Status CreateList(LinkList& L, int n)
{
	L = new Node;
	if (L == nullptr)
	{
		return ERROR;
	}

	L->next = nullptr;

	Node* p = L;

	for (int i = 0; i < n; i++)
	{
		Node* new_Node = new Node;
		new_Node->next = nullptr;
		cout << "Please enter the value of Node " << i + 1 << " :" << endl;
		cin >> new_Node->data;
		
		p->next = new_Node;
		p = p->next;
	}

	return OK;
}

