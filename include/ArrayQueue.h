/*
 * =====================================================================================
 *
 *       Filename:  ArrayQueue.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2015 11:29:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Queue.h"
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
template <typename E> class ArrayQueue: public Queue<E> {
	private:
		int maxSize;
		int front;
		int rear;
		bool isFull;
		E *queueArray;

	public:
		ArrayQueue(int size = defaultSize) {
			maxSize = size;
			isFull = false;
			rear = 0;
			front = 1;
			queueArray = new E[maxSize];
		}

		~ArrayQueue() {
			delete [] queueArray;
		}

		void clear() {
			rear = 0; 
			front = 1;
		}

		void enqueue(const E& it) {
			if (isFull)
				throw "Queue is full, cannot add item";
			rear = (rear + 1) % maxSize;
			queueArray[rear] = it;
			if ( ((rear + 1) % maxSize) == front)
				isFull = true;
		}

		E dequeue() {
			if (length() == 0) 
				throw "Queue is empty";
			E it = queueArray[front];
			front = (front + 1) % maxSize;
			return it;
		}

		const E& frontValue() const {
			if (length() == 0)
				throw "Queue is empty";
			return queueArray[front];
		}


		virtual int length() const {
			if (isFull) return maxSize;
			else return ((rear + maxSize) - front + 1) % maxSize;
			
		}
};
#endif
