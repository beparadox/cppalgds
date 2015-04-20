/*
 * =====================================================================================
 *
 *       Filename:  LinkedList.h
 *
 *    Description:  implementation of a linked list
 *
 *        Version:  1.0
 *        Created:  01/02/2015 10:41:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "List.h"
#include "LinkNode.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <typename E> class LinkedList: public List<E> {
	private:
		LinkNode<E>* head;
		LinkNode<E>* tail;
		LinkNode<E>* current;
		int count;

		void init() {
			current = tail = head = new LinkNode<E>;
			count = 0;
		}

		void removeAll() {
			while (head != NULL) {
				current = head;
				head = head->next;
				delete current;
			}
		}

	public:
		LinkedList(int size=defaultSize) { 
			init(); 
		}

		~LinkedList() { 
			removeAll();
		}

		void print() const;

		void clear() {
			removeAll(); 
			init(); 
		}

		void insert(const E& it) {
			current->next = new LinkNode<E>(it, current->next);
			if (tail == current) 
				tail = current->next;
			count++;
		}

		void append(const E& it) {
			tail = tail->next = new LinkNode<E>(it, NULL);
			count++;
		}

		E remove() {
			if (current->next == NULL)
				throw "No element in list";
			E it = current->next->element;
			LinkNode<E>* ltemp = current->next;
			if (tail == current->next) 
				tail = current;
			current->next = current->next->next;
			delete ltemp;
			count--;
			return it;
		}

		void moveToStart() {
			current = head;
		}

		void moveToEnd() {
			current = tail;
		}

		void prev() {
			if (current == head) return;
			LinkNode<E>* temp = head;
			while (temp->next != current) {
				temp = temp->next;
			}
			current = temp;
		}

		void next() {
			if (current != tail) 
				current = current->next;
		}

		int length() const {
			return count;
		}

		int currentPosition() const {
			LinkNode<E>* temp = head;
			int i;
			for (i = 0; current != temp; i += 1) {
				temp = temp->next;
			}
			return i;
		}

		void moveToPosition(int pos) {
			// Assert ((pos >= 0) && pos <= count), "Position out of range");
			if ( (pos < 0) && pos > count )
				throw "Position out of range";
			current = head;
			for (int i = 0; i < pos; i += 1) 
				current = current->next;
		}

		const E& getValue() const {
			if (current->next == NULL)
				throw "No value in list";
			return current->next->element;
		}
};
#endif
