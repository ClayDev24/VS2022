#pragma once
#include <iostream>

namespace resume {

	class Widget {
		void a(int i) const { std::cout << "Widget::a()..." << i << "\n"; }
		void b(int i) const { std::cout << "Widget::b()..." << i << "\n"; }
		void c(int i) const { std::cout << "Widget::c()..." << i << "\n"; }
		void d(int i) const { std::cout << "Widget::d()..." << i << "\n"; }
		enum { cnt = 4 };
		void (Widget::* fptr[cnt])(int) const;
	public:
		Widget() {
			fptr[0] = &Widget::a; // Full spec required
			fptr[1] = &Widget::b;
			fptr[2] = &Widget::c;
			fptr[3] = &Widget::d;
		}
		void select(int i, int j) {
			if (i < 0 || i >= cnt) return;
			(this->*fptr[i])(j);
		}
		int count() { return cnt; }
	};

	static void PointerToMemberFunction() {
		Widget w;
		for (int i = 0; i < w.count(); i++)
			w.select(i, i);
	}

} // resume