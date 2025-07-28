#pragma once
#include <iostream>
#include <matplot/matplot.h>
#include <set>
#include <thread>
#include <vector>

void _axis1() {
	using namespace matplot;

	fplot("sin(x)", "-o");
	axis({ 0, 2 * pi, -1.15, 1.5 });

	show();
}

void _axis2() {
	using namespace matplot;

	fplot("sin(4*x)/exp(0.1*x)");
	axis({ -10, +10, 0, inf });

	show();
}

void _axis3() {
	using namespace matplot;

	tiledlayout(2, 1);

	auto ax1 = nexttile();
	fplot(ax1, "sin(x)");

	auto ax2 = nexttile();
	fplot(ax2, "x < 5 ? sin(x) : -1");

	axis({ ax1, ax2 }, { 0, 10, -1, 1 });

	show();
}

void _axis4() {
	using namespace matplot;

	auto [X, Y, Z] = peaks();
	surf(X, Y, Z);
	axis(off);

	show();
}

void _axis5() {
	using namespace matplot;

	auto [X, Y, Z] = peaks();
	surf(X, Y, Z);
	axis(tight);

	show();
}

void _axis6() {
	using namespace matplot;

	auto c = eye(10);
	pcolor(c);
	colormap(palette::summer());
	axis(ij);

	show();
}

void _axis7() {
	using namespace matplot;

	auto x = linspace(0, 10);
	auto y = transform(x, [](double x) { return sin(x); });
	plot(x, y);

	auto y2 = transform(x, [](double x) { return 2 * sin(x); });
	hold(on);
	axis(manual);
	axis({ 0, 10, -1, +1 });
	plot(x, y2);
	hold(off);

	show();
}

void _axis8() {
	using namespace matplot;

	auto x = linspace(0, 10);
	auto y = transform(x, [](double x) { return sin(x); });
	plot(x, y);

	auto y2 = transform(x, [](double x) { return 2 * sin(x); });
	hold(on);
	axis(manual);
	axis({ 0, 10, -1, +1 });
	plot(x, y2);
	hold(off);

	axis(automatic);

	show();
}

void _box1() {
	using namespace matplot;

	auto [X, Y, Z] = peaks();
	surf(X, Y, Z);
	box(on);

	auto ax = gca();
	ax->box_full(true);

	show();
}