#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
public:

	LinkedList()
	{
		count = 0;
		Head = nullptr;
	}

	////////////////////////////////////////////////////////////////////////
  int getCount(){
    return count;
  }
  Node<T>* getHead(){
    return Head;
  }
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout<<"\nList has "<<count<<" nodes";
		cout<<"\nPrinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		count++;
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
	}
	////////////////////////////////////////////////////////////////////////
	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}

	////////////////////////////////////////////////////////////////////////
	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data) {

		if (Head == nullptr) {
			InsertBeg(data);
			return;
		}
		else {
			Node<T>* p = Head;
			while (p->getNext()) {
				p = p->getNext();
			}
			Node<T>* R = new Node<T>(data);
			p->setNext(R);
			count++;
			return;
		}
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(T Key) {
		Node<T>* p = Head;
		while (p) {
			if (p->getItem() == Key) {
				cout << "Found the element " << Key << endl;
				return true;
			}
			p = p->getNext();
		}
		cout << "\nElement " << Key << " not found" << endl;
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
  int CountOccurance(const T &value){
    int NumOccurs = 0;
    Node<T>* p = Head;
    while(p){
      if(p->getItem() == value){
	count++;
      }
      p = p->getNext();
    }
    return NumOccurs;
  }

	//[4] DeleteFirst
	//Deletes the first node in the list
  void DeleteFirst(){
    if(Head == nullptr){
      return;
    }
    Node<T>* P = Head->getNext();
    Delete Head;
    Head = P;
    count--;
  }

	//[5] DeleteLast
	//Deletes the last node in the list
  void DeleteLast(){
    if(Head == nullptr){ //Essentially if count is zero
      return;
    }
    if(Head->getNext() == nullptr){ //Essentially if count is one
      Delete Head;
      Head = nullptr;
      return;
    }
    //if count is two or more
    Node<T>* P = Head;
    while(P->getNext()->getNext()){ //This stops us at the element before last.
      P = P->getNext();
    }
    Delete P->getNext();
    P->setNext(nullptr);
    count--;
  }

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
  bool DeleteNode(const T &value){
    if(Head == nullptr){
      return false;
    }
    if(Head->getItem() == value){
      DeleteFirst();
      return true;
    }
    Node<T>* P = Head;
    while(P->getNext()){ //Meaning as long as we're not on the last element.
      if(P->getNext()->getItem() != value){
	P = P->getNext();
	continue;
      }
      Node<T>* Q = P->getNext()->getNext();
      Delete P->getNext();
      P->setNext(Q);
      count--;
      return true;
    }
    return false;
  }

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
  bool DeleteNodes(const T &value){
    if(Head == nullptr){
      return false;
    }
    if(Head->getNext() == nullptr){
      if(Head->getItem() == value){
	DeleteFirst;
	return true;
      }
      return false;
    }
    Node<T>* P = Head;
    bool everFound = false;
    while(P->getNext()){ //Meaning as long as we're not on the last element.
      if(P->getNext()->getItem() != value){
	P = P->getNext();
	continue;
      }
      Node<T>* Q = P->getNext()->getNext();
      Delete P->getNext();
      P->setNext(Q);
      count--;
      everFound = true;
      //Notice us not incrementing P forward. We just go through the loop again with the same P because its "Next" has changed; and the logic really checks "Next".
    }
    return everFound;
  }   

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
  void Merge(const LinkedList& L){
    Node<T>* CurrentLast = Head;
    while(CurrentLast->getNext()){
      CurrentLast = currentLast->getNext();
    }
    //Now CurrentLast is actually the last element of the current list
    CurrentLast->setNext(L->getHead());
    count = count + L->getCount;
    //We can even delete L now. But we might as well leave it.
  }

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
  void Reverse(){
    if(Head == nullptr || Head->getNext() == nullptr){ //if zero elements or one element.
      return;
    }
    Node<T>* p = Head;
    Node<T>* q = p->getNext();
    Node<T>* t = Head;
    Head->setNext(nullptr);
    while(t){
      t = q->getNext();
      q->setNext(p);
      p = q;
      q = t;
    }
    Head = p;
    return;
  }
  void PrintKth(int k)	const
  {
    if(k<1)
      {
	cout<<"Nice try\n";
      }
    cout<<"\nPrinting list item at index"<<k<<":\n\n";
    Node<T> *p = Head;
    for(int i = 1; i<k; i++)
      {
	if(p==nullptr)
	  {
	    cout<<"Beyond List Lenght\n";
	  }
	p = p->getNext();
      }
    cout << "[ " << p->getItem() << " ]";
    cout << "\n";
  }
  bool InsertSorted(const T &data)
  {
    //I'm gonna assume you mean sorted ascending here
    if(Head==nullptr)
      {
	InsertBeg(data);
	return true;
      }
    if(Head->getNext()==nullptr)
      {
	if(Head->getItem() == data)
	  {
	    return false;
	  }
	if(Head->getItem() > data){
	  InsertBeg(data);
	  return true;
	}
	if(Head->getItem() < data){
	  InsertEnd(data);
	  return true;
	}
      }
    Node<T>* p = Head;
    Node<T>* peakAhead = Head->getNext();
    while(p){
      if(peakAhead == nullptr){
	InsertEnd(data);
	return true;
      }
      if(peakAhead->getItem() == data){
	return false;
      }
      if(peakAhead->getItem() > data){
	Node<T>* R = new Node<T>(data);
	p->setNext(R);
	R->setNext(peakAhead);
	count++;
	return true;
      }
    }
  }
  Node<T>* RemoveMin(){
    if(Head == nullptr){
      return nullptr;
    }
    Node<T>* p=Head;
    Node<T>* currentMin=Head;
    int indexMin = 1;
    int j = 1; //I hate iterators out and about like this; but I need it.
    while(p){
      if(p->getItem() < currentMin->getItem()){
	currentMin=p;
	indexMin = j;
      }
      p=p->getNext();
      i++;
    }
    if(currentMin==Head){
      Head=currentMin->getNext();
      return currentMin;
    }
    Node<T>* itemBeforeMin=Head;
    for(int i=1; i<indexMin-1; i++){
      itemBeforeMin=itemBeforeMin->getNext();
    }
    itemBeforeMin->setNext(currentMin->getNext());
    return currentMin;
  }
  LinkedList<T> CloneList(){
    //I refuse to give this an arguemnt. Just call the clone method of the instance you want to clone.
    //On the topic of thing I refuse. I'm gonna avoid the sub-optimal solution of calling InsertEnd over and over. Because goodness god does that not scale well!
    LinkedList<T> clone;
    clone.Head = new Node<T>(Head->getItem());
    clone.count++;
    Node<T>* cloneEnd = clone.Head;
    Node<T>* p = Head->getNext();
    Node<T>* R;
    while(p){
      R = new Node<T>(p->getItem());
      cloneEnd->setNext(R);
      clone.count++;
      cloneEnd=R;
      p=p->getNext();
    }
    return clone;
  }
  void SignSplit(LinkedList& Lneg, LinkedList& Lpos){
    //for contrast, and for time saving (yikes, it's 10:23!), here's a similar cloning process that just calls InsertEnd over and over again.
    Node<T>* p = Head;
    T data;
    while(p){
      data = p->getItem();
      if(data < 0){
	Lneg.InsertEnd(data);
      }
      if(data > 0){
	Lpos.InsertEnd(data);
      }
      p=p->getNext();
    }
  }
  LinkedList<T> MergeSorted(LinkedList& RHS){
     //while the object instance this is running in is the LHS, you know what I mean.
    LinkedList<T> merged = RHS.CloneList();
    Node<T>* p = Head;
    while(p){
      merged.InsertSorted(p->getItem());
      p=p->getNext();
    }
    RHS.DeleteAll();
    DeleteAll();
  }
  LinkedList<T> SumLists(LinkedList& RHS){
    //while the object instance this is running in is the LHS, you know what I mean.
    if(count != RHS.count){
      return NULL;
    }
    LinkedList<T> summed;
    Node<T>* p = Head;
    Node<T>* q = RHS.Head;
    while(p){
      summed.InsertEnd(p->getItem()+q->getItem());
      p=p->getNext();
      q=q->getNext();
    }
    return summed;
  }
  void Reorder_X(T x){
    if(Head == nullptr || Head->getNext() == nullptr){
      return;
    }
    Node<T>* p = Head;
    Node<T>* r;
    T temp;
    while(p){
      if(p->getItem > x){
	r = p->getNext();
	while(p){ //intentional
	  if(r == nullptr){
	    return;
	  }
	  if(r->getItem() <= x){
	    temp = p->getItem();
	    p->setItem(r->getItem());
	    r->setItem(temp);
	    break;
	  }
	  r=r->getNext();
	}
      }
      p=p->getNext();
    }
    return;
  }
  void ShiftLargest(){
    if(Head == nullptr || Head->getNext() == nullptr){
      return;
    }
    Node<T>* p = Head;
    Node<T>* r = p->getNext();
    T pItem;
    T rItem;
    while(q){
      pItem = p->getItem();
      rItem = r->getItem();
      if(pItem > rItem){
	r->setItem(pItem); //Larger successfully shifted
	p->setItem(rItem);
      }
      p=p->getNext();
      r=p->getNext();
    }
  }
  void RemoveDuplicates(){
    Node<T>* p = Head;
    Node<T>* q;
    Node<T>* t;
    while(p){
      q=p;
      t=q->getNext();
      while(t){
	if(t->getItem() == p->getItem()){
	  q->setNext(t->getNext());
	  delete t;
	  count--;
	}
	q=q->getNext();
	t=q->getNext();
      }
      p=p->getNext();
    }
  }
  

  

};

#endif	
