/*
 *      Author: MaksiKutrolli
 */

#include <iostream>
#include "Entry.h"

using namespace std;

template<typename K, typename V>
Entry<K, V>::Entry(const K &k, const V &v): _key(k), _value(v)  {
}

template<typename K, typename V>
const K& Entry<K, V>::keyy() const {// @suppress("Ambiguous problem")
	return _key;
}

template<typename K, typename V>
const V& Entry<K, V>::valuee() const {// @suppress("Ambiguous problem")
	return _value;
}

template<typename K, typename V>
void Entry<K, V>::setKey(const K &k) {
	 _key = k;
}

template<typename K, typename V>
void Entry<K, V>::setValue(const V &v) {
	_value = v;
}

template class Entry<int, int>;
template class Entry<int, string>;
