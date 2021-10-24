#include<iostream>
using namespace std;

/*

	push X: 정수 X를 스택에 넣는 연산이다.
	pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 스택에 들어있는 정수의 개수를 출력한다.
	empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
	top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

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
	return head == NULL; // 비워져있으면 1, 아니면 0
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

