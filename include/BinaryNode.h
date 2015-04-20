/*
 * =====================================================================================
 *
 *       Filename:  BinaryNode.h
 *
 *    Description:  Implement a binary tree ADT
 *
 *        Version:  1.0
 *        Created:  04/10/2015 01:10:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H
template <typename E> class BinaryNode {
	public:
		virtual ~BinaryNode() {} // Base destructor

		// return the node's value
		virtual E& element() = 0;

		// set the node's value
		virtual void setElement(const E&) = 0;

		// return the node's left child
		virtual BinaryNode* left() const = 0;

		// set the node's left child
		virtual void setLeft(BinaryNode *) = 0;

		// return the node's right child
		virtual BinaryNode* right() const = 0;

		// set the node's right child
		virtual void setRight(BinaryNode*) = 0;

		virtual bool isLeaf() = 0;
};
#endif
