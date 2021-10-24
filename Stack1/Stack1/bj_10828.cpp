#include<iostream>
using namespace std;

/*

	push X: ���� X�� ���ÿ� �ִ� �����̴�.
	pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
	empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

*/

class Stack {
	private :
		int n;
		Stack* next;
	public : 
		Stack() { n = 0; next = NULL; };
		~Stack() { delete next; };
		void push(int num, Stack *head);
		int pop(Stack *head);
		int size(Stack *head);
		bool empty(Stack *head);
		int top(Stack *head);
		void display(Stack* head);
};

void Stack::push(int num, Stack* head) {
	Stack* p = head;
	Stack* newNode;
	newNode->n = num;
	newNode->next = NULL;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
	delete p;
}

int Stack::pop(Stack* head) {
	Stack* p = head;
	while (p->next->next != NULL) {
		p = p->next;
	}
	int r = p->next->n;
	p->next = NULL;
	delete p;
	return r;
}

int Stack::size(Stack* head) {
	int cnt = 0;
	Stack* p = head;
	while (p->next != NULL) {
		cnt++;
	}
	delete p;
	return cnt;
}

bool Stack::empty(Stack* head) {
	return head == NULL; // ����������� 1, �ƴϸ� 0
}

int Stack::top(Stack* head) {
	if (empty(head)) return -1;
	else return head->next->n;
}

void Stack::display(Stack* head) {
	Stack* p = head;
	while (p->next != NULL) {
		cout << p->n;
	}
	delete p;
}

int main() {
	Stack* head;
	head = NULL;
	int c;
	switch (c) {
		case 0:
			head->display(head);
			break;
		case 1:
			head->empty(head);
			break;
		case 2:
	}
}

