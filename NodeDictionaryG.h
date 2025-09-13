#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "NodeMapG.h"
#include "Range.h"

template <typename K, typename V>

class NodeDictionaryG: public MapG<IteratorG<K,V>, K, V> 
{
	private: // data members
		int n; // number of items
		DNodeG<K,V>* header; // head-of-list sentinel
		DNodeG<K,V>* trailer; // tail-of-list sentinel 
	public:
		int size() const; // list size
		bool empty() const; // is the list empty?
		IteratorG<K,V> begin() const; // beginning position
		IteratorG<K,V> end() const; // (just beyond) last position
		IteratorG<K,V> find(const K& k) const; // find entry with key k
		IteratorG<K,V> put(const K& k, const V& v); // insert/replace pair (k,v)
		void erase(const K& k); // remove entry with key k
		void erase(const IteratorG<K,V>& p); // erase entry at p
		Range<K,V> findAll(const K& k);
		void print();
		void print(Range<K,V>& r);
};
#endif
