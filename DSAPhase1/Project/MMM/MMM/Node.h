#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
template < typename T>
class Node
{
private:
	T item; // A data item
	Node<T>* next; // Pointer to next node
public:
	Node()
	{
		next = nullptr;
	}
	Node(const T& data)
	{
		item = data;
		next = nullptr;
	}
	T getItem() const
	{
		return item;
	}
	Node<T>* getNext() const
	{
		return next;
	}
	void setItem(const T& data)
	{
		item = data;
	}
	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

}; 

#endif
