#include <iostream>

using namespace std;


class Node {
public:
	int value;
	Node* next;
	Node(int i) { value = i; next = nullptr; }
	Node() { next = nullptr; }
};

class LinkedList {
public:
	int numNodes;
	Node* head;
	LinkedList() { numNodes = 0; head = nullptr; }
	void makeRandomList(int m, int n);
	void printList();



	//Recursively merge sort i numbers starting at node pointed by p
	void mergeSort(Node*& p, int i);//in-place recursive merge sort


	//Merge i1 numbers starting at node pointed by p1 with i2 numbers
	//starting at node pointed by p2
	void merge(Node*& p1, int i1, Node* p2, int i2);
};

// Function to generate linklist
void LinkedList::makeRandomList(int m, int n) {

	for (int i = 0; i < m; i++) {
		Node* p1 = new Node(rand() % n);
		p1->next = head;
		head = p1;
		numNodes++;
	}
}

// Function to print linklist 
void LinkedList::printList() {
	cout << endl;
	Node* p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}


void LinkedList::mergeSort(Node*& p, int i)
{

	if ((p == NULL) || (p->next == NULL)) {
		return;
	}
	if (i == 1)
		return;

	Node* p2;
	p2 = p;
	int mid = i / 2;
	int k = i - mid;
	for (int j = 1; j <= mid; j++)
		p2 = p2->next;
	mergeSort(p, mid);
	mergeSort(p2, k);

	merge(p, mid, p2, k);

}

void LinkedList::merge(Node*& p1, int i1, Node* p2, int i2)
{
	Node* third, * last, * first, * second, * p3, * temp;;
	p3 = p2;
	first = p1;
	second = p2;
	third = last = nullptr;

	for (int i = 1; i <= i2; i++)
		p3 = p3->next;
	int k = i1 + i2;
	if (first->value <= second->value)
	{
		third = first;
		last = first;
		first = first->next;
		i1--;
		last->next = nullptr;
	}
	else
	{
		third = second;
		last = second;
		second = second->next;
		last->next = nullptr;
		i2--;
	}

	while (i1 > 0 && i2 > 0)
	{
		if (first->value < second->value)
		{
			last->next = first;
			first = first->next;
			i1--;
			last = last->next;
			last->next = nullptr;

		}
		else
		{
			last->next = second;
			second = second->next;
			i2--;
			last = last->next;
			last->next = nullptr;
		}
	}
	if (i1 == 0 && i2 == 0)
		last->next = p3;
	if (i1 > 0)
	{
		last->next = first;

	}
	if (i2 > 0)
	{
		last->next = second;
	}

	temp = third;
	for (int j = 1; j < k; j++)
	{
		temp = temp->next;
	}
	temp->next = p3;

	p1 = third;
}

int main()
{
	LinkedList d1;
	d1.makeRandomList(5, 10);
	d1.printList();
	d1.mergeSort(d1.head, d1.numNodes);
	d1.printList();
	getchar();
	getchar();
	return 0;
}