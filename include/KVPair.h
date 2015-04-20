/*
 * =====================================================================================
 *
 *       Filename:  KVPair.h
 *
 *    Description:  Implement a key-value pair
 *
 *        Version:  1.0
 *        Created:  01/15/2015 07:42:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef KVPAIR_H
#define KVPAIR_H
template <typename Key, typename E>
class KVPair {
	private:
		Key k;
		E e;
	public:
		KVPair() {}

		KVPair(Key kval, E eval) {
			k = kval;
			e = eval;
		}

		KVPair(const KVPair& o) {
			k = o.k;
			e = o.e;
		}

		void operator = (const KVPair& o) {
			k = o.k;
			e = o.e;
		}

		Key key() { return k; }

		void setKey(Key ink) {
			k = ink;
		}

		E value() {
			return e;
		}
};
#endif
