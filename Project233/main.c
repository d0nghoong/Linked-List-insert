#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "linkedlist.h";

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