#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

typedef struct {
	listNode* head;
}linkList_h;

linkList_h* createdLinkedList(void);
void freeLinkedList_h(linkList_h* L);
void printList(linkList_h* L);
void insertMiddleNode(linkList_h* L, listNode* pre, char* x);
void insertLastNode(linkList_h* L, char* x);

linkList_h* createdLinkedList(void) {
	linkList_h* L;
	L = (linkList_h*)malloc(sizeof(linkList_h));
	L->head = NULL;
	return L;
}
void freeLinkedList_h(linkList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkList_h* L) {
	listNode* p;
	p = L->head;
	printf("L=(");
	while (p != NULL) {
		printf("% s", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}
	printf(")");
	printf("\n");
}

void insertFirstNode(linkList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (L->head = NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre = NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

}

void insertLastNode(linkList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;
		if (temp->link != NULL)temp = temp->link;
		temp->link = newNode;
	}



}

void main() {
	linkList_h* L;
	L = createdLinkedList();

	printf("\n1.���� ����Ʈ �����ϱ�!\n");
	printList(L);

	printf("\n2.����Ʈ�� [��]��� �Է��ϱ�\n");
	insertFirstNode(L, "��");
	printList(L);

	printf("\n3.����Ʈ �������� [��]��� �Է��ϱ�\n");
	insertLastNode(L, "��");
	printList(L);

	printf("\n4.����Ʈ ù��°�� [��]��� �����ϱ�\n");
	insertFirstNode(L, "��");
	printList(L);

	printf("\n5.����Ʈ ������ �����Ͽ� ���� ����Ʈ �����\n");
	freeLinkedList_h(L);
	printList(L);

}