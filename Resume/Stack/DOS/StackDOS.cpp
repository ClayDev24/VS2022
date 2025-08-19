// Linked list with nesting
#include "StackDOS.h"
#include "StackDOS2.h"
//#include "../../include/require.h"
//#include "_require.h"

namespace dos {

	//Stack::Link::Link(void *dt, Link *nxt):data(dt), next(nxt) {}
/*
	void Stack::push(void *dt) {
		Link *newLink = new Link(dt, head);
		head = newLink;
	}

	void* Stack::peek() const { 
		//require(head != 0, "Stack empty");
		return head->data; 
	}

	void* Stack::pop() {
		if(head == 0) return 0;
		void *result  = head->data;
		Link *oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}

	Stack::~Stack() {
		//require(head == 0, "Stack not empty");
	}
*/
} // dos