#pragma once
#include <cmath>
#include <matplot/matplot.h>

void _line() {
    using namespace matplot;

    plot(iota(1, 10));

    line(3, 3, 3, 4);
    arrow(3, 4, 4, 4);

    show();
}