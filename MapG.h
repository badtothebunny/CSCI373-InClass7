/*
 *      Author: MaksiKutrolli
 */

#ifndef MAPG_H_
#define MAPG_H_

template <typename I, typename K, typename V>
class MapG { // map interface
	public:
		virtual ~ MapG() = default;

		virtual int size() const = 0; // number of entries in the map
		virtual bool empty()  const = 0; // is the map empty?
		virtual I find(const K& k)  const = 0;; // find entry with key k
		virtual I put(const K& k, const V& v) = 0; // insert/replace pair (k,v)
		virtual void erase(const K& k) = 0; // remove entry with key k
		virtual void erase(const I& p) = 0; // erase entry at p
		virtual I begin() const = 0; // iterator to first entry
		virtual I end() const = 0; // iterator to end entry
};




#endif /* MAPG_H_ */
