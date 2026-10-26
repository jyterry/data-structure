#pragma once

#include <iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR -1

typedef struct Node
{
	ElemType data;
	struct Node* next;
} Node, *LinkList;

Status InitList(LinkList& L);

Status DestroyList(LinkList& L);

Status ClearList(LinkList L);

bool ListEmpty(const LinkList L);

int ListLength(const LinkList L);

Status GetElem(const LinkList L, int i, ElemType& e);

int LocateElem(const LinkList L, ElemType e);

Status PriorElem(LinkList L, ElemType cur_e, ElemType& pre_e);

Status NextElem(LinkList L, ElemType cur_e, ElemType& next_e);

Status ListInsert(LinkList L, int i, ElemType e);

Status ListDelete(LinkList L, int i, ElemType& e);

void ListTraverse(const LinkList L);

Status CreateList(LinkList& L, int n);

