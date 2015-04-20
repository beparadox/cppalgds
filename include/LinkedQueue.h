/*
 * =====================================================================================
 *
 *       Filename:  LinkedQueue.h
 *
 *    Description:  Linked implementation of a queue
 *
 *        Version:  1.0
 *        Created:  01/08/2015 02:23:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
using namespace std;
#include "Queue.h"
#include "LinkNode.h"
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
template <typename E> class LinkedQueue: Queue<E> {
	private:
		LinkNode<E>* front;
		LinkNode<E>* rear;
		int size;
	public:
		LinkedQueue() {
			front = rear = new LinkNode<E>();
			// cout << "inLInked Queue constr and size = " << size << endl;
			size = 0;
		}

		~LinkedQueue() {
			clear();
			delete front;
		}

		void clear() {
			while(front->next != NULL) {
				rear = front;
			 	front = front->next;
				delete rear;
			}
			rear = front;
			size = 0;
		}

		void enqueue(const E& it) {
			rear->next = new LinkNode<E>(it, NULL);
			rear = rear->next;
			size++;
		}	

		E dequeue() {
			if (size == 0)
				throw "Queue is empty";
			E it = front->next->element;
			LinkNode<E>* ltemp = front->next;
			front->next = ltemp->next;
			if (rear = ltemp)
				rear = front;
			delete ltemp;
			size--;
			return it;

		}

		const E& frontValue() const {
			if (size == 0)
				throw "Queue is empty";
			return front->next->element;

		}

		virtual int length() const {
			return size;
		}
};
#endif
