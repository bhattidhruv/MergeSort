
#include <iostream>
#include<thread>
using namespace std;


class node {
public:
	int value;
	node* next;
	node* previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class doubly_linked_list {
public:
	int num_nodes;
	node* head;
	node* tail;
	doubly_linked_list() { num_nodes = 0; head = tail = nullptr; }
	void make_random_list(int m, int n);
	void print_forward();
	void print_backward();
	void merge_sort(node*& p, int i);
	void merge(node*& p1, int i1, node* p2, int i2);
};

void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node* p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail = p1;
		if (head == nullptr) head = p1;
		num_nodes++;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	node* p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

void doubly_linked_list::print_backward() {
	cout << endl;
	node* p1 = tail;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
}


void doubly_linked_list::merge(node*& p1, int i1, node* p2, int i2)
{
	if (p1 == nullptr || p2 == nullptr)
		return;
	int sum = i1 + i2;
	node* new_head, * temp, * first, * second, * start, * end;
	new_head = temp = start = end = nullptr;
	first = p1;
	second = p2;
	start = p1->previous;
	temp = p2;
	int copy = i2;
	node* last_before_sorting = nullptr;
	// loop for setting up the end pointer
	while (copy > 0)
	{
		if (copy == 1)
			last_before_sorting = temp;
		temp = temp->next;
		copy--;
	}
	end = temp;
	temp = nullptr;
	//setting up a new head value here
	if (first->value < second->value)
	{
		new_head = first;
		temp = first;
		first = first->next;
		i1--;
		new_head->next = new_head->previous = nullptr;
	}
	else
	{
		new_head = second;
		temp = second;
		second = second->next;
		i2--;
		new_head->next = new_head->previous = nullptr;
	}
	// Now we'll be adding the remaining linked list
	while (i1 > 0 && i2 > 0)
	{
		if (first->value < second->value)
		{
			temp->next = first;
			first->previous = temp;
			temp = temp->next;
			first = first->next;
			temp->next = nullptr;
			i1--;
		}
		else
		{
			temp->next = second;
			second->previous = temp;
			temp = temp->next;
			second = second->next;
			temp->next = nullptr;
			i2--;
		}
	}

	if (i1 > 0)
	{
		temp->next = first;
		first->previous = temp;
	}
	else if (i2 > 0)
	{
		temp->next = second;
		second->previous = temp;
	}
	//Till here in the code we have a newly created sorted list
	node* last = nullptr;
	last = new_head;
	while (sum > 1)
	{
		last = last->next;
		sum--;
	}
	// Now we will connect newly sorted list to start and end elements
	if (start)
		start->next = new_head;
	new_head->previous = start;
	if (end)
		end->previous = last;
	last->next = end;
	// If p1 was head then head will be changed
	//Also p1 will be given correct node address, that is new_head;
	if (last_before_sorting == tail)
		tail = last;
	if (p1 == head)
		head = new_head;
	p1 = new_head;
}


void doubly_linked_list::merge_sort(node*& p, int i)
{

	if ((p == nullptr) || (p->next == nullptr)) {
		return;
	}
	if (i == 1)
		return;

	node* p2;
	p2 = p;
	int mid = i / 2;
	int k = i - mid;
	for (int j = 1; j <= mid; j++)
		p2 = p2->next;
	merge_sort(p, mid);
	merge_sort(p2, k);

	merge(p, mid, p2, k);

}




int main() {

	doubly_linked_list d1, d2;
	d1.make_random_list(10, 10);

	std::cout << "printing unsorted Linked List from front";
	d1.print_forward();
	cout << endl;

	std::cout << "printing unsorted Linked List from back";
	d1.print_backward();
	cout << endl;

	d1.merge_sort(d1.head, d1.num_nodes);
	std::cout << "printing sorted Linked List from front";
	d1.print_forward();
	cout << endl;

	std::cout << "printing sorted Linked List from back";
	d1.print_backward();
	cout << endl;


	d2.make_random_list(5, 10);
	std::cout << "printing unsorted Linked List from front";
	d2.print_forward();
	cout << endl;
	std::cout << "printing unsorted Linked List from back";
	d2.print_backward();
	cout << endl;

	/*
	Created two additional threads to speed up the merge sort.
	I have still used the same merge_sort and merge functions as implemented above.
	I have just done some extra work within main funciton.
	*/

	int n1 = 0; int n2 = 0;
	if (d2.num_nodes % 2 == 0)
	{
		n1 = n2 = d2.num_nodes / 2;
	}
	else
	{
		n1 = d2.num_nodes / 2;
		n2 = d2.num_nodes - n1;
	}
	node* temp;
	temp = d2.head;
	int i = 1;
	while (i <= n1)
	{
		temp = temp->next;
		i++;
	}
	thread t1(&doubly_linked_list::merge_sort, ref(d2), ref(d2.head), ref(n1));
	thread t2(&doubly_linked_list::merge_sort, ref(d2), ref(temp), ref(n2));
	t1.join();
	t2.join();
	d2.merge(d2.head, n1, temp, n2);
	std::cout << "printing sorted Linked List from front Using Mutithreading";
	d2.print_forward();
	cout << endl;
	std::cout << "printing sorted Linked List from back Using Mutithreading";
	d2.print_backward();
	return 0;

}