// Linked list with nesting structure
#include "stack.h"
//#include "..\..\Utilidades\Utilidades\_require.h"
//#include "_require.h"

namespace resume {

	void Stack::Link::initialize(void* dat, Link* nxt) {
		data = dat;
		next = nxt;
	}

	void Stack::initialize() { head = 0; } // An empty list yet...

	void Stack::push(void* dat) {
		Link* node = new Link;
		node->initialize(dat, head);
		head = node;
	}

	void* Stack::peek() { 
		//utils::require(head != 0, "Stack empty");
		return head->data; 
	}

	void* Stack::pop() {
		if(head == 0) return 0;
		void*  result  = head->data;
		Link*  oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}

	void Stack::cleanup() {
		//utils::require(head == 0, "Stack not empty");
	}

} // resume