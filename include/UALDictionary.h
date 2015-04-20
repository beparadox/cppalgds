/*
 * =====================================================================================
 *
 *       Filename:  UALDictionary.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/15/2015 07:52:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "ArrayList.h"
#include "Dictionary.h"
#include "KVPair.h"

#ifndef UALDICTIONARY_H
#define UALDICTIONARY_H
template <typename Key, typename E>
class UALDictionary: public Dictionary<Key, E> {
	private:
		ArrayList< KVPair<Key, E> >* list;
	public:
		UALDictionary(int size=defaultSize) {
			list = new ArrayList< KVPair<Key,E> >(size);
		}

		~UALDictionary() {
			delete list; 
		}

		void clear() {
			list->clear();
		}

		void insert(const Key& k, const E& e) {
			KVPair<Key,E> temp(k, e);
			list->append(temp);
		}

		E remove(const Key& k) {
			E temp = find(k);
			if (temp != NULL) 
				list->remove();
			return temp;
		}

		E removeAny() {
			if (size() == 0)
				throw "Dictionary is empty";
			list->moveToEnd();
			list->prev();
			KVPair<Key,E> e = list->remove();
			return e.value();
		}

		E find(const Key& k) const {
			for (list->moveToStart();
					list->currentPosition() < list->length(); list->next())
			{
				KVPair<Key, E> temp = list->getValue();
				if (k == temp.key())
					return temp.value();
			}
			return NULL;
		}

		int size() {
			return list->length();
		}
};
#endif
