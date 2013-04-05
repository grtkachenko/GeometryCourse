#pragma once

#include <vector>

#include <boost/random.hpp>

namespace Skiplist {
	
	namespace Util {
		const double prob = 0.5;
		boost::random::mt19937 generator((unsigned) std::time(0));
		boost::random::geometric_distribution<size_t, double> random(prob);
		size_t gen_level(size_t maxLevel) {
			return std::min(random(generator), maxLevel + 1);
		}
	}

}

template <class T>
class SkipList {
	
	struct Node {
		T val;
		std::vector<Node *> next, prev;
		Node(const T& val, size_t level);
		~Node();
        void insertImpl(Node * node, size_t level);
	};

	Node head;

	Node * findImpl(const T& val, std::function <bool(const T&, const T&)> f);
    
public:
	class iterator {
        friend SkipList;
		Node * curNode;
		iterator(Node * node);
	public:
		operator bool();
		iterator& erase();
		iterator(const iterator& it);
		iterator& operator++();
		iterator& operator--();
		iterator operator++(int);
		iterator operator--(int);
		T& operator*();
		iterator& operator=(const iterator&);

//		iterator& operator+=(size_t n);
//		iterator& operator-=(size_t n);
//		bool operator==(const iterator&);
//		bool operator!=(const iterator& rhs);

	};

	SkipList();
    template <class InputIterator> SkipList(InputIterator first, InputIterator last);
	~SkipList();
	size_t size();
	iterator begin();
	iterator end();
	bool empty();
	iterator insert(const T& val);
	iterator erase(iterator pos);
	iterator erase(iterator first, iterator last);
	iterator find(const T& val);
	iterator lower_bound(const T& val);
	iterator upper_bound(const T& val);
	void clear();
};

template <class T>
SkipList<T>::Node::Node(const T& val, size_t level) : val(val), next(level, NULL), prev(level, NULL) {}

template <class T>
SkipList<T>::Node::~Node() {
	for(size_t i = 0, sz = next.size(); i < sz; ++i) {
		Node * save = prev[i];
		if(prev[i])
			prev[i]->next[i] = next[i];
		if(next[i])
			next[i]->prev[i] = save;
	}
}

template <class T>
SkipList<T>::iterator::iterator(SkipList::Node * node) : curNode(node) {}

template <class T>
SkipList<T>::iterator::iterator(const iterator& it) : curNode(it.curNode) {}

template <class T>
SkipList<T>::iterator::operator bool() {
	return curNode;
}

template <class T>
typename SkipList<T>::iterator& SkipList<T>::iterator::erase() {
	if(!curNode)
		throw "Erasing by bad iterator";
	Node * nextNode = curNode->next[0];
	delete curNode;
	curNode = nextNode;
	return *this;
}

template <class T>
typename SkipList<T>::iterator& SkipList<T>::iterator::operator ++ () {
	if(curNode)
		curNode = curNode->next[0];
	return *this;
}

template <class T>
typename SkipList<T>::iterator& SkipList<T>::iterator::operator -- () {
	if(curNode)
		curNode = curNode->prev[0];
	return *this;
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::iterator::operator ++ (int) {
	iterator old(*this);
	if(curNode)
		curNode = curNode->next[0];
	return old;
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::iterator::operator -- (int) {
	iterator old(*this);
	if(curNode)
		curNode = curNode->prev[0];
	return old;
}

template <class T>
typename SkipList<T>::iterator& SkipList<T>::iterator::operator = (const iterator& r) {
	curNode = r->curNode;
	return *this;
}

template <class T>
bool operator == (const typename SkipList<T>::iterator& l, const typename SkipList<T>::iterator& r) {
	return l->curNode == r->curNode;
}

template <class T>
bool operator != (const typename SkipList<T>::iterator& l, const typename SkipList<T>::iterator& r) {
	return !(l == r);
}

template <class T>
T& SkipList<T>::iterator::operator * () {
	if(!curNode)
		throw "Dereferencing bad iterator";
	return curNode->val;
}

template <class T>
SkipList<T>::SkipList() : head(T(), 1) {}

template <class T> template <class InputIterator>
SkipList<T>::SkipList(InputIterator first, InputIterator last) : SkipList() {
	while(first != last)
		insert(*first++);
}

template <class T>
SkipList<T>::~SkipList() {
	while(head.next[0])
		delete head.next[0];
}

template <class T>
size_t SkipList<T>::size() {
	Node * cur(&head);
	size_t ret = 0;
	while(cur->next[0])
		cur = cur->next[0], ++ret;
	return ret;
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::begin() {
	return iterator(&head);
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::end() {
	return iterator(NULL);
}

template <class T>
bool SkipList<T>::empty() {
	return !head->next[0];
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::insert(const T& val) {
    size_t maxLevel = head.next.size() - 1;
	size_t level = Skiplist::Util::gen_level(maxLevel);
	if(level > maxLevel) {
        maxLevel = level;
		head.next.resize(maxLevel + 1, NULL);
        head.prev.resize(maxLevel + 1, NULL);
	}
	Node * newNode = new Node(val, level + 1);
	Node * cur = &head;
	for(int i = (int)maxLevel; i >= 0; --i) {
		while(cur->next[i] && val < cur->next[i]->val)
			cur = cur->next[i];
		if(i <= (int)maxLevel)
			cur->insertImpl(newNode, i);
	}
	return iterator(newNode);
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::erase(iterator it) {
	it.erase();
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::erase(iterator first, iterator last) {
	if(!first)
		throw "Erasing by bad iterator";
	while(first != last)
		first.erase();
	return first;
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::find(const T& val) {
	Node * ret = findImpl(val, [] (const T& lhs, const T& rhs) { return lhs < rhs; } );
	if(ret && ret->val == val)
		return iterator(ret);
	else
		return iterator(NULL);
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::lower_bound(const T& val) {
	return iterator(findImpl(val, [] (const T& lhs, const T& rhs) { return lhs < rhs; } ));
}

template <class T>
typename SkipList<T>::iterator SkipList<T>::upper_bound(const T& val) {
	return iterator(findImpl(val, [] (const T& lhs, const T& rhs) { return lhs <= rhs; } ));
}

template <class T>
void SkipList<T>::clear() {
	while(head->next[0])
		erase(iterator(head->next[0]));
}

template <class T>
typename SkipList<T>::Node * SkipList<T>::findImpl(const T& val, std::function <bool(const T&, const T&)> cmp) {
	if(!head.next[0])
		return NULL;
	Node * cur = &head;
	for(int level = (int)head.next.size() - 1; level >= 0; --level) {
		while(cur->next[level] && cmp(val, cur->next[level]->val))
			cur = cur->next[level];
	}
	return cur->next[0] ? cur->next[0] : NULL;
}

template <class T>
void SkipList<T>::Node::insertImpl(Node * node, size_t level) {
	node->next[level] = next[level];
    node->prev[level] = this;
    if(next[level]) {
        next[level]->prev[level] = node;
    }
	next[level] = node;
}