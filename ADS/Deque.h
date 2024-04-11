/*
         ----- The implementation of class Deque was done from scratch -----
This is a program that implements the double-ended queue (Deque) using Array implementation.
The Deque is implemented such that you can add and remove from both ends of it,
where Front of deque is at index [0] & Rear of deque is at index [MAX_SIZE].
*/

#pragma once
#include "QueueADT.h"
#include <iostream>
#define MAX_SIZE 100;
using namespace std;

template <typename T>
class Deque :public QueueADT<T>
{
	private:
		T items[MAX_SIZE];   //array which holds items
		int frontInd;        //holds index of first element (in array) from front of queue
		int rearInd;         //holds index of first element (in array) from rear  of queue

	public:

		Deque() { frontInd = -1; rearInd = MAX_SIZE;} //default constructor
		/* In constructor, I intialized frontInd with -1 which is one less than 0 which is index of first element in array so that
		 when adding a first element to queue frontInd will be zero which is index if first element, same with rearInd.
		 Usinf this as a condition when enqueuing or dequeuing from both rear or end ensures that frontInd & rearInd will always
		 hold a valid index within array*/

		bool isEmpty() const { return (frontInd == -1 && rearInd == MAX_SIZE); }

		/* This function enqueues an item to the first
		 free space from front of the queue in array */
		bool enqueue(const T& newEntry)
		{
			if (frontInd==rearInd-1) return false;
			else
			{
				items[frontInd+1] = newEntry;
				frontInd++;
				return true;
			}
		}

		/* This function dequeues the item at the 
		 front of queue - which is at index [0] */
		bool dequeue(T& EntryZero)
		{
			if (frontInd==-1) return false;
			else
			{
				EntryZero = items[0];
				items[0] = items[frontInd];
				frontInd--;
				return true;
			}
		}

		/* This function enqueues an item to the first
		 free space from rear of the queue in array */
		bool enqueueRear(const T& newEntry)
		{
			if (rearInd==frontInd+1) return false;
			else
			{
				items[rearInd-1] = newEntry;
				rearInd--;
				return true;
			}
		}

		/* This function dequeues the item at the
		 front of queue - which is at index [MAX_SIZE] */
		bool dequeueRear(T& EntryLast)
		{
			if (rearInd==MAX_SIZE) return false;
			else
			{
				EntryLast = items[MAX_SIZE-1];
				items[MAX_SIZE-1] = item[rearInd];
				rearInd++;
				return true;
			}
		}
		
		/* This function returns element at
		 front of queue which is at index [0] */
		bool peek(T& EntryZero) const
		{
			if (frontInd==-1) return false;
			else
			{
				EntryZero = items[0];
			}
		}

		/* This function returns element at
		 front of queue which is at index [0] */
		bool peekRear(T& EntryLast) const
		{
			if (rearInd==-1) return false;
			else
			{
				EntryLast = items[0];
			}
		}

		~Deque() {}
}; //end of Deque