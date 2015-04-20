/*
 * =====================================================================================
 *
 *       Filename:  ListStack.h
 *
 *    Description:  implement the Stack ADT using a list
 *
 *        Version:  1.0
 *        Created:  01/07/2015 08:28:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Stack.h"
#include "LinkNode.h"
#ifndef LISTSTACK_H
#define LISTSTACK_H
#ifndef defaultSize
#define defaultSize 100
#endif

template <typename E> class ListStack: public Stack<E> {
	private:
		LinkNode<E>* top;
		int size;
	public:
		ListStack(int size = defaultSize) {
			top = NULL;
			size = 0;
		}

		~ListStack() {
			clear(); 
		}

		void clear() {
			while (top != NULL) {
				LinkNode<E>* temp = top;
				top = top->next;
				delete temp;
			}
			size = 0;
		}

		void push(const E& it) {
			top = new LinkNode<E>(it, top);
			size++;
		}

	        E pop() {
			if (top == NULL) 
				throw "No elements on the stack";
			E it = top->element;
			LinkNode<E>* ltemp = top->next;
			delete top;
			top = ltemp;
			size--;
			return it;
		}	

		const E& topValue() const {
			if (top == 0) throw "No elements on the stack";
			return top->element;
		}

		int length() const {
			return size;
		}
};
#endif
