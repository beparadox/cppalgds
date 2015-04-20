/*
 * =====================================================================================
 *
 *       Filename:  listPractice.cpp
 *
 *    Description:  Practice with lists, both Array based and linked lists
 *
 *        Version:  1.0
 *        Created:  01/06/2015 10:55:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <assert.h>
#include "ArrayList.h"
#include "LinkedList.h"
using namespace std;

typedef struct {
	char name[50];
	char number[14];
} Contact;

template<typename E>
int appendToList(ArrayList<E>* AList, int num) {

	int i; 
	// create an array list of length 10;

	for (i = 0; i < num; ++i) {
		AList->append(i);
	}

	return 0;
}

template <typename E>
void printCpal(ArrayList<E>* alist) {
	cout << "Printing currenPosition and length of list" << endl;
	cout << alist->currentPosition() << endl;
	cout << alist->length() << endl;
}

template<typename E>
void printList(ArrayList<E> *alist) {
	int i;
        alist->moveToStart();
	cout << alist->getValue() << endl;;
	for (i = 1; i < alist->length(); i += 1) {
		alist->next();
		cout << alist->getValue()<< endl;
	}
}

template<typename E>
ArrayList<E>* createList(E, int size) {
	ArrayList<E> alist = new ArrayList<E>(size);
	return &alist;

}

void listPracticeMain() {
	// ArrayList<int>* mylist = createList( template<typename int>, 10);
	ArrayList<int> myList(10);// = new ArrayList<int>(10);
	myList.insert(71);
	myList.insert(73);
	myList.insert(79);
	myList.append(83);
	myList.append(89);
	printList(&myList);
 	int current = myList.currentPosition();
	cout << current << endl;
	myList.remove();
	printList(&myList);

//	LinkedList<int> alist(5);
}
