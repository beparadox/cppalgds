/*
 * =====================================================================================
 *
 *       Filename:  LinkNode.h
 *
 *    Description:  Nodes used to form a linked list
 *
 *        Version:  1.0
 *        Created:  12/25/2014 11:21:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
using namespace std;
#ifndef LINKNODE_H
#define LINKNODE_H
template <typename E> class LinkNode {
	private:
	 	static LinkNode<E>* freelist; // reference the free list
	public:
		E element;
		LinkNode<E>* next;
		// Constructors
	        LinkNode(const E& elemval, LinkNode<E>* nextnode = NULL) {
			element = elemval;
			next = nextnode;
		}

		LinkNode(LinkNode<E>* nextnode = NULL) {
			next = nextnode;
		}


		// operator overloading
		// redefine new and delete using a freelist
		void* operator new(size_t) {
			if (freelist == NULL) {
				// cout << "returning new node"<<endl;
                                return ::new LinkNode;
			}
		        LinkNode<E>* temp = freelist;
			freelist = freelist->next;
			return temp;
		}

		void operator delete(void* ptr) {
			// cout << "deleting node " << ((LinkNode<E>*)ptr)->element << endl;
			((LinkNode<E>*)ptr)->next = freelist;
			freelist = (LinkNode<E>*)ptr;
		}
};
#endif
