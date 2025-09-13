/*
 *      Author: MaksiKutrolli
 */

#include "NodeMapG.h"

#include "IteratorG.h"

template <typename K, typename V>
NodeMapG<K,V>::NodeMapG() {
	n = 0; // initially empty
	header = new DNodeG<K,V>; // create sentinels
	trailer = new DNodeG<K,V>;
	header->next = trailer; // have them point to each other
	trailer->prev = header;

}


template <typename K, typename V>
NodeMapG<K,V>::~NodeMapG() {
}

template <typename K, typename V>
int NodeMapG<K,V>::size() const {
	return n;
}

template <typename K, typename V>
bool NodeMapG<K,V>::empty() const {
	return n==0;
}

template <typename K, typename V>
IteratorG<K, V> NodeMapG<K,V>::begin() const {
	return IteratorG<K, V>(header->next);
}

template <typename K, typename V>
IteratorG<K, V> NodeMapG<K,V>::end() const {
	return IteratorG<K, V>(trailer);
}

template<typename K, typename V>
IteratorG<K, V> NodeMapG<K, V>::find(const K &k) const {
	IteratorG<K,V> p(begin());
	for (; p != end(); ++p)
		if(p.v->elm.keyy() == k)
			return p;
	return end();
}

template<typename K, typename V>
IteratorG<K, V> NodeMapG<K, V>::put(const K &k, const V &v) {
	IteratorG<K,V> p = find(k);
	DNodeG<K,V> *w;
	DNodeG<K,V> *u;
	if(p == end()){
		w = p.v; // p’s node
		u = w->prev; // p’s predecessor
	}
	else
	{
		while (p.v->elm.keyy() != k)
			++p;
	}
	DNodeG<K,V>* new_node = new DNodeG<K,V>; // new node to insert
	new_node->elm.setKey(k);
	new_node->elm.setValue(v);
	new_node->next = w; w->prev = new_node; // link in v before w
	new_node->prev = u; u->next = new_node; // link in v after u
	n++;
	return p;
}


template<typename K, typename V>
void NodeMapG<K, V>::erase(const K &k) {
	IteratorG<K,V> p(begin());
	for (; p != end(); ++p)
		if(p.v->elm.keyy() == k)
			erase(p);
}

template<typename K, typename V>
void NodeMapG<K, V>::erase(const IteratorG<K, V> &p) {
	DNodeG<K,V>* v = p.v; // node to remove
	DNodeG<K,V>* w = v->next; // successor
	DNodeG<K,V>* u = v->prev; // predecessor
	u->next = w; w->prev = u; // unlink p
	delete v; // delete this node
	n--; // one fewer element
}

template<typename K, typename V>
void NodeMapG<K, V>::print(){
	IteratorG<K,V> p(begin());
	for (; p != end(); ++p)
		cout<< p.v->elm<< " <=> ";
	cout<<endl;
}




template class NodeMapG<int,int>;
//template class NodeMapG<int, string>;
