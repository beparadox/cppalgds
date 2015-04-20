/*
 * =====================================================================================
 *
 *       Filename:  ListPractice.cc
 *
 *    Description:  Practice with ArrayList and LinkedList implementations
 *
 *        Version:  1.0
 *        Created:  12/25/2014 08:59:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstring>
#include <iostream>
#include <cstdlib>
#include "listPractice.h"
#include "stackPractice.h"
#include "queuePractice.h"
#include "dictionaryPractice.h"
#include "treePractice.h"
using namespace std;
// function prototype

template <typename E>
LinkNode<E> * LinkNode<E>::freelist = NULL;

void randNums() {
    srand(time(NULL));
    int num, den;
    int i;

    for (i = 0; i < 10; i++) {
	    num = rand();
	    den = rand();
	    if (num > den ) {
		    num = num + den;
		    den = num - den;
		    num = num - den;
	    }
	    cout << (double) num / den << endl; 
    }
}
int main() {
	// implement integer list
	cout << "Welcome to the main for ALGOS C++" << endl;
        
	try {
		// testQueueMain();
		// randNums();
		// listPracticeMain();
		keyPairPlay();


	
	} catch (const char* msg) {
		cout << msg << endl;
	}

        return 0;
}


