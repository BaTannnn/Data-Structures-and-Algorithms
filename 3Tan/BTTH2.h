#include <iostream>
#include <string>
using namespace std;
struct SinhVien {
	string name;
	string mssv;
	double dtb;
	SinhVien *next;
	SinhVien(string hoten="",string ms ="",double diem=0.0,SinhVien*ptr = nullptr) {
		name = hoten;
		mssv = ms;
		dtb = diem;
		next = ptr;
	}
};
struct List_SV {
	SinhVien *head;
	List_SV() {
		head = nullptr;
	}
	void Add_to_head(string hoten, string ms, double diem);
	string Delete_head();
	void Add_to_tail(string hoten, string ms, double diem);
	string Delete_Tail();
	void Add(string hoten, string ms, double diem, string x);
	bool isEmpty() {
		return (head == nullptr);
	}
	void Xuat() {
		SinhVien* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->name << " " << tmp->mssv << " " << tmp->dtb;
			cout << endl;
			tmp = tmp->next;
		}
	}
};
void List_SV::Add_to_head(string hoten, string ms, double diem){
	head = new SinhVien(hoten, ms,diem, head);
}
string List_SV::Delete_head() {
	SinhVien*tmp = head;
	string ms = tmp->mssv;
	head = head->next;
	delete tmp;
	return ms;
}
void List_SV::Add_to_tail(string hoten , string ms, double diem){
	SinhVien *tmp = head;
	if(tmp->next == nullptr){
		head = new SinhVien(hoten, ms, diem);
	}
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = new SinhVien(hoten, ms, diem);
}
string List_SV::Delete_Tail(){
	SinhVien *tmp = head;
	SinhVien *pre = nullptr;
	while (tmp->next != nullptr) {
		pre = tmp;
		tmp = tmp->next;
	}
	string ms = tmp->mssv;
	if (tmp == head) {
		head = nullptr;
	}
	else {
		pre->next = nullptr;
	}
	delete tmp;
	return ms;
}
void List_SV::Add(string hoten, string ms, double diem, string x) {
	SinhVien *tmp=head;
	if (!isEmpty()) {
		while (tmp != nullptr && tmp->mssv != x) {
			tmp = tmp->next;
		}
		if (tmp == nullptr) {
			cout << "Khong co sinh vien nen da them vao cuoi";
			Add_to_tail(hoten, ms, diem);
		}
		else {
			tmp->next = new SinhVien(hoten, ms, diem, tmp->next);
		}
	}
}
struct ArrStack {
	int *s;
	int top = -1;
	int capacity;
	ArrStack(int cap = 100) {
		capacity = cap;
		s = new int[cap];
	}
	bool isFull() {
		return (top + 1 == capacity);
	}
	bool isEmpty() {
		return (top < 0);
	}
	void push(int x) {
		if (!isFull()) {
			s[++top] = x;
		}
		else {
			cout << "stack da day";
		}
	}
	int pop() {
		if (!isEmpty()) {
			return s[top--];
		}
		else
		{
			cout << "Stack Rong";
		}
	}
	void changeBinary(int n) {
		while (n != 0) {
			push(n%2);
			n /= 2;
		}
	}
	void xuatStack() {
		while (top != -1) {
			cout << pop() << " ";
		}
	}
};
struct ArrQueue {
	int *q;
	int capacity;
	int front,rear;
	ArrQueue(int cap = 100) {
		q = new int[cap];
		front = rear = -1;
		capacity = cap;
	}
	bool isFull() {
		return (rear - front == -1) || (rear - front == capacity - 1);
	}
	bool isEmpty() {
		return (rear == front == -1);
	}
	void AddQueue(int x) {
		if (!isFull) {
			if (isEmpty()) {
				front = 0;
			}
			if (rear == capacity - 1) {
				rear = -1;
			}
			q[++rear] = x;
		}
		else {
			cout << "Stack is full!";
		}
	}
	void DeQueue() {
		if (!isEmpty) {
			int num = q[front];
			if (rear == front) {
				rear = front = -1;
			}
			front++;
			if (front >= capacity) {
				front = 0;
			}
		}
		else {
			cout << "There is nothing to delelte";
		}
	}
};
struct Node {
	int num;
	Node *next;
	Node(int x, Node*ptr = nullptr) {
		num = x;
		next = ptr;
	}
};
struct LinkedQueue {
	Node*front;
	Node*rear;
	LinkedQueue(){
		front = rear = nullptr;
	}
	void enqueue(int x) {
		Node*tmp = new Node(x);
		if (front == nullptr)
			front = tmp;
		else {
			rear->next=tmp;
		}
		rear = tmp;
	}
	void dequeue(){
		Node *tmp = front;
		int x = tmp->num;
		if (front == rear)
			front = rear = nullptr;
		delete tmp;
	}
};




