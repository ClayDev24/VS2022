#pragma once
#include <cmath>
#include <matplot/matplot.h>

void _rectangle1() {
	using namespace matplot;

	vector_1d data = { 2, 4, 6, 7, 8, 7, 5, 2 };
	stem(data);

	auto r1 = rectangle(2.5, 5.5, 2, 2);
	r1->color("red");
	//r1->fill(true);

	auto r2 = rectangle(6.5, 4.5, 1, 1);
	r2->fill(true);
	r2->color({ 0.8f, 0.f, 0.f, 1.f });

	show();
}

void _rectangle2() {
	using namespace matplot;

	rectangle(0, 0, 2, 4, 0);
	rectangle(3, 0, 2, 4, 1);
	rectangle(6, 0, 2, 4, 0.5);

	show();
}

void _rectangle3() {
	using namespace matplot;

	rectangle(2, 4, 2, 2, 1.);
	auto r2 = rectangle(2, 4, 2, 2, 0.);
	r2->color("red");
	axis(equal);

	show();
}

void _rectangle4() {
	using namespace matplot;

	auto r = rectangle(1, 2, 5, 10);
	r->fill(true);
	r->color({ 0, .5, .5 });
	r->line_width(3);

	auto r2 = rectangle(1, 2, 5, 10);
	r2->color("blue");
	r2->line_width(3);

	show();
}

void _rectangle5() {
	using namespace matplot;
	using namespace std;

	vector<double> x = { 0, 8, 8, 0 };
	vector<double> y = { 0, 0, 4, 4 };
	polygon(x, y, "g");
	rectangle(0, 0, 2, 4, 0)->fill(true).color("red");
	rectangle(3, 0, 2, 4, 1)->fill(true).color("magenta");
	rectangle(6, 0, 2, 4, 0.5)->fill(true).color("yellow");
	text(2, 2, "Curvature 0")->alignment(labels::alignment::right);
	text(4, 2, "Curvature 1")->alignment(labels::alignment::center);
	text(6, 2, "Curvature 0.5")->alignment(labels::alignment::left);
	arrow(4, 2.2, 3, 3);
	textarrow(6, 1, 8, 0, "Last corner");

	show();
}

void _pie() {
	using namespace matplot;

	std::vector<double> x = { 1, 3, 0.5, 2.5, 2 };
	pie(x);

	show();
}