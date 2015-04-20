/*
 * =====================================================================================
 *
 *       Filename:  ArrayList.h
 *
 *    Description:  Array implementation of a linked list
 *
 *        Version:  1.0
 *        Created:  12/25/2014 06:50:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "List.h"
#ifndef defaultSize
#define defaultSize 100
#endif 
#ifndef ARRAYLIST_H
#define ARRAYLIST_H 
template <typename E>
class ArrayList: public List<E> {
	private:
		int maxSize;   // Maximum size of list
		int listSize;  // Number of list items now 
		int current;   // Position of currrent element
		E* listArray;  // Array holding list of elements

	public:
		ArrayList(int size=defaultSize) { // Constructor
			maxSize = size;
			listSize = current = 0;
			listArray = new E[maxSize];
		}

		~ArrayList() { 
			delete [] listArray; 
		}  // Destructor

		void clear() {
			delete [] listArray;
			listSize = current = 0;
			listArray = new E[maxSize];
		}

		// Insert "it" at current position
		void insert(const E& it) {
			if (listSize >= maxSize) 
				throw "List capacity exceeded";

			for (int i=listSize; i > current; i -= 1) {
				listArray[i] = listArray[i - 1];
			}

			listArray[current] = it;
			listSize++;
		}

		void append(const E& it) {
			if (listSize >= maxSize)
				throw "List capacity exceeded";
			listArray[listSize++] = it;
		}

		E remove() {
			if ( (current == 0) && (current == listSize) )
				throw "No element";

			E it = listArray[current];

			for(int i = current; i < listSize - 1; i += 1) {
				listArray[i] = listArray[i + 1];
			}

			listSize--;

			return it;
		}

		void moveToStart() { 
			current = 0; 
		}

		void moveToEnd() { 
			current = listSize; 
		}

		void prev() { 
			if (current != 0)  current--; 
		}

		void next() { 
			if (current < listSize) current++; 
		}

		int length() const { 
			return listSize; 
		}

		int currentPosition() const { 
			return current; 
		}

		void moveToPosition(int pos) {
			// Assert ((pos >= 0) && ( pos <= listSize), "Pos out of range");
			if ( (pos >= 0) && ( pos <= listSize) ) 
				throw "Position out of range";
			current = pos;
		}

		const E& getValue() const {
			// Assert( (current >= 0) && (current < listSize), "No current element");
			if ( (current == 0) && (current == listSize) ) 
				throw "No current element";

			return listArray[current];
		}
};
#endif
