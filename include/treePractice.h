/*
 * =====================================================================================
 *
 *       Filename:  treePractice.h
 *
 *    Description:  Practice with binary trees
 *
 *        Version:  1.0
 *        Created:  04/20/2015 02:16:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "BinaryNode.h"

template <typename E>
void visit(BinaryNode<E>* node) {
	if (node == NULL) return;
	cout << node.element() << endl;
}

template <typename E>
void preorder(BinaryNode<E>* root) {
	if (root == NULL) return;
	visit(root);
	preorder(root->left());
	preorder(root->right());
}

void createTree() {
}
