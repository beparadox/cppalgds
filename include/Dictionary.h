/*
 * =====================================================================================
 *
 *       Filename:  Dictionary.h
 *
 *    Description:  header file for a dictionary class
 *
 *        Version:  1.0
 *        Created:  01/09/2015 06:00:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bambridge E. Peterson (bep), bambridge.peterson@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

template <typename Key, typename E>
class Dictionary {
	private:
		void operator = (const Dictionary&) {}
		Dictionary(const Dictionary&) {}

	public:
		Dictionary() {}
		virtual ~Dictionary() {}

		virtual void clear() = 0;

		virtual void insert(const Key& k, const E& e) = 0;

		virtual E remove(const Key& k) = 0;

		virtual E removeAny() = 0;

		virtual E find(const Key& k) const = 0;

		virtual int size() = 0;
};
