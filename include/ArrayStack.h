/*
 * =====================================================================================
 *
 *       Filename:  ArrayStack.h
 *
 *    Description:  header file for the array-based implementation of a Stack data
 *    structure
 *
 *        Version:  1.0
 *        Created:  01/06/2015 03:04:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Stack.h"

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#ifndef defaultSize
#define defaultSize 100
#endif
template <typename E> 
class ArrayStack: public Stack<E> {
	private:
		int maxSize;
		int top;
		E* stackArray;

	public:
		ArrayStack(int size=defaultSize) {
			maxSize = size;
			top = 0; 
			stackArray = new E[size];
		}

		~ArrayStack() {
			delete [] stackArray;
		}

		void clear() {
			top = 0;
		}

		void push(const E& it) {
			if (top == maxSize)
				throw "Stack is full";
			stackArray[top++] = it;
		}

		E pop() {
			if (top == 0)
				throw "Stack is empty";
			return stackArray[--top];
		}

		const E& topValue() {
			if (top == 0) 
				throw "Stack is empty";
			return stackArray[top - 1];
		}

		int length() const {
			return top;
		}
};
#endif
