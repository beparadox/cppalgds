/*
 * =====================================================================================
 *
 *       Filename:  dictionaryPractice.h
 *
 *    Description:  practice 
 *
 *        Version:  1.0
 *        Created:  04/03/2015 12:15:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "UALDictionary.h"
#define MAXSIZE 40

typedef struct person_s {
	char name[MAXSIZE];
	int age;
	int id;
} Person_t;

void keyPairPlay() {
	char str[] = "Bam";
	char str2[] = "Amy";
	char str3[] = "Megan";
	KVPair<int, char*> bam(36, str);
	KVPair<int, char*> amy(47, str2);
	KVPair<int, char*> meg(33, str3);
	UALDictionary<int, char*> list(10);
	list.insert(36, str);
	list.insert(47, str2);
	list.insert(33, str3);
	cout << list.removeAny() << endl;
	cout << list.find(36) << endl;
	Person_t bamie;
	char b[] = "Bamie";
	strcpy(bamie.name, b);
	bamie.age = 36;
        bamie.id = 1001;
	UALDictionary<int, Person_t*> newlist(10);
	// newlist.insert(bamie.id, bamie);

	
}




