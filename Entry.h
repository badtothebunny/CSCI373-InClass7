/*
 *      Author: MaksiKutrolli
 */


#ifndef ENTRY_H_
#define ENTRY_H_

using namespace std;
template <typename K, typename V>
class Entry {
public: // public functions
	Entry(const K& k = K(), const V& v = V());// constructor
	const K& keyy() const; // get key
	const  V& valuee() const; // get value
	void setKey(const K& k);  // set key
	void setValue(const V& v); // set value


	friend ostream& operator<<(ostream& os, Entry& p){
		os<<endl<<"{"<<p._key<<" ; "<<p._value<<"}";
		return os;
	}

private: // private data
	K _key; // key
	V _value; // value
};

#endif /* ENTRY_H_ */
