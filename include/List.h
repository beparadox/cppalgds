/*
 * =====================================================================================
 *
 *       Filename:  List.h
 *
 *    Description:  Abstract implemenation of the List data structure
 *
 *        Version:  1.0
 *        Created:  12/25/2014 04:17:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef LIST_H
#define LIST_H
template <typename E> class List {
	private:
		void operator = (const List&) {}
		List(const List&) {} // protect copy constructor
	public:
		List() {}  // default constructor
		virtual ~List() {} // Base destructor

		// clear contents from the list
		virtual void clear() = 0;

		// insert an element at the current location
		// item: The element to be inserted
	        virtual void insert(const E& item) = 0;	

		// Append an element to the end of the list
		// item: element to be appended
	        virtual void append(const E& item) = 0;

                // remove and return the current element
		// Return: the element that was removed
	        virtual E remove() = 0;

		// move current position to start
	        virtual void moveToStart() = 0;

		// set current position to end of the list
	        virtual void moveToEnd() = 0;

		// move the current position one step to the left
		// no change if already at the beginning
	        virtual void prev() = 0;

		// move the current position one step right. No
		// change if already at the end.
	        virtual void next() = 0;

		// return the number of elements in the list
	        virtual int length() const = 0;

		// the position of the current element
	        virtual int currentPosition() const = 0;

		// set the current position
	        virtual void moveToPosition(int pos) = 0;

		// reutnr the current element
	        virtual const E& getValue() const = 0;
};
#endif 
