# MergeSort

MergeSort is a very renowned, efficient, general-purpose and comparison-based sorting algorithm. This was my academic assignment to implement MergeSort with singly-LinkedList, doubly-LinkedList and with multithreading.

## MergeSort project: -
It is implemented with singly linked list. Requirement were as follow,
1.	Recursively in-place merge sort i numbers starting at node pointed by p 
void mergeSort(Node*& p, int i);

2.	Merge i1 numbers starting at node pointed by p1 with i2 numbers starting at node pointed by p2
void merge(Node*& p1, int i1, Node* p2, int i2);

3.	No external data structures could not be used, such as, array, linked list, etc.
4.	Not allowed to create any new functions.

## MergeSort_Doubly-Linked-List :- 
It is implemented with doubly linked list. Requirement were as follow,
1.	Recursively in-place merge sort i numbers starting at node pointed by p 
void mergeSort(Node*& p, int i);

2.	Merge i1 numbers starting at node pointed by p1 with i2 numbers starting at node pointed by p2
void merge(Node*& p1, int i1, Node* p2, int i2);
3.	In implementing both functions, you are only allowed to modify "next" and "previous" of nodes, but not "values" of nodes.
4.	You are not allowed to use any external structures such as array, linked list, etc.
5.	You are not allowed to create any new node.
6.	You are not allowed to create any new function.

## MergeSort_Multithreading :-
It is implemented with 2 threads to speed up the process. 
Requirements were as follow,
1.	Create a parallel version, by using two additional threads to speed up the merge sort.
2.	In threaded implementation, you can introduce an extra node and a global pointer to the node.
3.	For multithreading use the same merge_sort and merge functions which is implemented for sequential merge_sort, (do not create new functions).
4.	Recursively in-place merge sort i numbers starting at node pointed by p 
void mergeSort(Node*& p, int i);
5.	Merge i1 numbers starting at node pointed by p1 with i2 numbers starting at node pointed by p2
void merge(Node*& p1, int i1, Node* p2, int i2);
6.	In implementing both functions, you are only allowed to modify "next" and "previous" of nodes, but not "values" of nodes.
7.	You are not allowed to use any external structures such as array, linked list, etc.
8.	You are not allowed to create any new node.
9.	You are not allowed to create any new function



*University: Syracuse University*

*Course: CSE 674 Advanced Data Structure, CSE 691 Parallel Programing & Multi-Threading C++.* 

*Professor: Roger Chen*

