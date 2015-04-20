/*
 * =====================================================================================
 *
 *       Filename:  queuePractice.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/08/2015 04:17:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
using namespace std;

void testLinkedQueue() {
  	LinkedQueue<int> lq;
        lq.enqueue(1);
	cout << lq.dequeue() << endl;
	cout << "length1 = " << lq.length() << endl;
	cout << lq.dequeue() << endl;
	cout << lq.dequeue() << endl;
	cout << "length = " << lq.length() << endl;
 	lq.clear();
	cout << "length = " << lq.length() << endl;
	lq.enqueue(7);
	lq.enqueue(2);
	lq.enqueue(5);
}

void linkQTestToo() {
        LinkedQueue<int> lq;
	cout << "length = " << lq.length() << endl;

}
void testArrayQueueOne() {
        cout << "Welcome to testQueueMain" << endl;
        ArrayQueue<int> aqueue(6);
	aqueue.enqueue(1);
	cout << aqueue.length() << endl;
	aqueue.enqueue(2);
	cout << aqueue.length() << endl;
	aqueue.enqueue(3);
	aqueue.enqueue(4);
	aqueue.enqueue(5);
	cout << aqueue.length() << endl;
	cout << aqueue.frontValue() << endl;
	aqueue.enqueue(6);
	cout << aqueue.length() << endl;
	aqueue.enqueue(7);


}
void testQueueMain() {
	// linkQTestToo();
 	testLinkedQueue();
}
