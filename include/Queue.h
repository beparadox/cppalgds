/*
 * =====================================================================================
 *
 *       Filename:  Queue.h
 *
 *    Description:  Header file for Queue ADT 
 *
 *        Version:  1.0
 *        Created:  01/07/2015 10:14:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef QUEUE_H
#define QUEUE_H
template <typename E> class Queue {
	private:
		void operator = (const Queue&) {}
		Queue (const Queue&) {}
	public:
		Queue() {}
		virtual ~Queue() {}

		virtual void clear() = 0;

		virtual void enqueue(const E&) = 0;

		virtual E dequeue() = 0;

		virtual const E& frontValue() const = 0;

		virtual int length() const = 0;
};
#endif
