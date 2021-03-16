#include "LinkedQueue.h"
#include "ArrayStack.h"	
#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.
#define n 100 //Only here because of how Pearson implemented "Reverse"
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

// This caod has 1 checkpoint [CheckPoint 1]
//Follow the provided instructions at each check point

//A function that takes a ArrayStack<T> S and returns its reverse (without affecting the orignal stack) (Shafei note: Using you folks' code here)
template <typename T>
ArrayStack<T> Reverse(ArrayStack<T> S)
{
	ArrayStack<T> Rev(n);	//First creat a stack 
	T Item;
	while(S.pop(Item))	//pop from S
		Rev.push(Item); //push into Rev

	return Rev;
}
//This reverse function seems to work indeed without affecting the original stack. But I'm highly unsure how it could possibly do that!
//We are passing the stack by value.. but there's an "items" array inside that's living in heap memory and they both should share that same array..
//Oh, wait.. pop doesn't actually modify the "items" array it seems. Lol.
//Just moves the top index, which is reasonably copied over by value. That's okay. That's cool.

template <typename T>
bool SameOrder(ArrayStack<T> mainStack, LinkedQueue<T>& mainQueue)
{
  //Trivial case, they're both empty.
  if( mainStack.isEmpty() && mainQueue.isEmpty() )
    {
      //Then I guess they're the same order!
      return true;
    }
  //Now non-trivial.
  ArrayStack<T> revStack = Reverse(mainStack);
  LinkedQueue<T> auxQueue;
  //But wait!! Why are we creating an auxiliary queue?
  //Because we're doing some really destructive things to our main queue.
  //And unless we manage to undo those changes before this function returns, it'll have side effects.
  //And no one likes a function with side effects!
  bool areSame = true;
  T x;
  T y;
  bool poppedX = true; //for now.
  bool dequeuedY = true; //for now.

  while(poppedX && dequeuedY)
    {
      poppedX = revStack.pop(x);
      dequeuedY = mainQueue.dequeue(y);

      //Let's now not lose the original queue state. Remember, no side effects.
      if(dequeuedY)
	{
	  auxQueue.enqueue(y);
	}

      //Now the core logic.
      if((poppedX && !dequeuedY) || (!poppedX && dequeuedY))
	{
	  //Then they're not the same number of elements!
	  areSame = false;
	  break;
	}
      if( x != y )
	{
	  //Then they at some point had different elements entered!
	  areSame = false;
	  break;
	}
      //If those two fail conditions are never met, then we can rest easy.
    }

  //But before we return, let's finish our "no side effects" business with our main queue!
  while(mainQueue.dequeue(y))
    {
      auxQueue.enqueue(y);
    }
  //Now auxQueue is a perfect copy of the queue we started with. Buuuuuut it's gonna get destructed! So let's pour those back into mainQueue..
  while(auxQueue.dequeue(y))
    {
      mainQueue.enqueue(y);
    }
  //I tired a few fancier tricks with putting auxQueue in heap memory then just copying the data members of auxQueue into mainQueue.
  //Or making a copy queue *before* the core logic and destructively editing that. Leaving main queue unchanged.
  //Hooooowever, they all confused me pretty hard and I believe some if not all of them are not actually possible solutions.
  //If you have the time maybe tell me if you think one of those solutions or some other solution might work :)
  //For now, I'm gonna go with the trusty "pour everything out, then pour everything back in" method.

  //We can *finally* return a thing!
  return areSame;
}

template <typename T>
bool isPalindrome(LinkedQueue<T>& mainQueue)
{
  ArrayStack<T> cleanedStack(n);
  LinkedQueue<T> auxQueue; //Avoiding side effects!
  T x;
  while(mainQueue.dequeue(x))
    {
      auxQueue.enqueue(x);
      if(("a" < x && x > "z") || ("A" < x && x > "Z"))
	{
	  cleanedStack.push(x);
	}
    }
  //Let's undo the damage to mainQueue before we forget!
  while(auxQueue.dequeue(x))
    {
      mainQueue.enqueue(x);
    }

  //Now the core logic.
  ArrayStack<T> reversedStack = Reverse(cleanedStack);
  //That's it really. We just need to check the two stacks are equal. We even know before hand that they have the same number of elements.
  T y;
  while(cleanedStack.pop(x))
    {
      reversedStack.pop(y);
      if(x != y)
	{
	  return false;
	}
    }
  return true;
}

//This is the program starting point.
int main()
{
	//Declare a Stack of integers named "S" and with max size = 10 elements
	ArrayStack<int> S(10);
	LinkedQueue<int> Q;

	int i,x,num;

	cout<<"\nTesting SameOrder!";
	cout<<"\nEnter no. of values to push/enqueue:";
	cin>>num;

	//Test the 1st stack by pushing n values then popping
	cout << "Pushing/enqueuing "<<num<<" values into both:" << endl;

	cout<<"Please Enter the "<<num<<" values to push in S :";
	for(i = 0; i < num; i++)
	{	 
		cin>>x;
		S.push(x); //pushing x to S
		Q.enqueue(x);
	}

	cout << endl<<"Popping: ";

	while(S.pop(x))		//As long as pop returns true, x contains a valid value		
		cout << x << " ";

	cout<<"\nDequeuing: ";
	
	while(Q.dequeue(x))
	  {
	    cout << x << " ";
	  }

	
	cout<<endl;

	cout<<"is the order the same?? ==>"<<boolalpha<<SameOrder(S, Q);
	cout<<endl;
	return 0;
}
  
