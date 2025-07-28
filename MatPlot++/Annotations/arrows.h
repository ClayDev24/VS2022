#pragma once
#include <cmath>
#include <matplot/matplot.h>

void _arrow1() {
    using namespace matplot;

    plot(iota(1, 10));
    auto a = arrow(2.5, 6.5, 5, 5);

    show();
}

void _arrow2() {
    using namespace matplot;

    plot(iota(1, 10));
    auto a = arrow(2.5, 6.5, 5, 5);
    a->color("blue");
    a->line_width(4);

    show();
}