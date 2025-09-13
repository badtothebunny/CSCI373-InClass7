/*
 *      Author: MaksiKutrolli
 */

#include "IteratorG.h"

template <typename K, typename V>
IteratorG<K, V>::IteratorG(DNodeG<K,V> *u) {
	v = u;
}

template <typename K, typename V>
const V& IteratorG<K, V>::operator *() {
	return v->elm.valuee();
}

template <typename K, typename V>
bool IteratorG<K, V>::operator ==(const IteratorG &p) const {
	return v == p.v;
}

template <typename K, typename V>
bool IteratorG<K, V>::operator !=(const IteratorG &p) const {
	return v != p.v;
}

template <typename K, typename V>
IteratorG<K, V>& IteratorG<K, V>::operator ++() {
	 v = v->next;
	 return *this;
}

template <typename K, typename V>
IteratorG<K, V>& IteratorG<K, V>::operator --() {
	v = v->prev;
	return *this;
}


template class IteratorG<int, int>;
//template class IteratorG<int, string>;

