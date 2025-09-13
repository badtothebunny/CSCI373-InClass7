/*
 *      Author: MaksiKutrolli
 */

#ifndef DOUBLYLLG_NODEMAPG_H_
#define DOUBLYLLG_NODEMAPG_H_


#include "MapG.h"
#include "DNodeG.h"

#include "Entry.h"

template <typename K, typename V>
class IteratorG;


template <typename K, typename V>

class NodeMapG: public MapG<IteratorG<K,V>, K, V> {
public:
	NodeMapG();
	virtual ~NodeMapG();

	int size() const; // list size
	bool empty() const; // is the list empty?

	IteratorG<K,V> begin() const; // beginning position
	IteratorG<K,V> end() const; // (just beyond) last position
	IteratorG<K,V> find(const K& k)  const; // find entry with key k
	IteratorG<K,V> put(const K& k, const V& v); // insert/replace pair (k,v)
	void erase(const K& k); // remove entry with key k
	void erase(const IteratorG<K,V>& p); // erase entry at p

	void print();

private: // data members
	int n; // number of items
	DNodeG<K,V>* header; // head-of-list sentinel
	DNodeG<K,V>* trailer; // tail-of-list sentinel

};

#endif /* DOUBLYLLG_NODEMAPG_H_ */
