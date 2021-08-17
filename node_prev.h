#ifndef _node_h_
#define _node_h_

template <class T>
class node {
    public:
	    T info;
	    node <T> *next;
		node<T> *prev;

    node(T info) {
		this->info = info;
		next = NULL;
		prev = NULL;
	}
};

#endif
