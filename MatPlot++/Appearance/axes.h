#pragma once
#include <iostream>
#include <matplot/matplot.h>
#include <set>
#include <thread>
#include <vector>

void _axes1() {
	using namespace matplot;
	auto ax1 = gca();
	axis({ -100, +100, -30, +30 });
	fplot(ax1, "3*cos(3*x) + tan(x)");

	show();
}

void _axes2() {
	using namespace matplot;
	auto ax1 = axes({ 0.1f, 0.1f, 0.7f, 0.7f });
	auto ax2 = axes({ 0.65f, 0.65f, 0.28f, 0.28f });

	auto [X, Y, Z] = peaks(20);
	contour(ax1, X, Y, Z);
	colorbar(ax1, off);
	surf(ax2, X, Y, Z);

	show();
}

void _axes3() {
	using namespace matplot;
	auto ax1 = axes({ 0.1f, 0.1f, 0.6f, 0.6f });
	auto ax2 = axes({ 0.35f, 0.35f, 0.6f, 0.6f });

	ax1->box(true);
	ax2->box(true);

	axes(ax1);
	auto x = linspace(0, 10);
	auto y = transform(x, [](double x) { return sin(x); });
	plot(x, y);

	show();
}

void _axes4() {
	using namespace matplot;

	gca();

	show();

}