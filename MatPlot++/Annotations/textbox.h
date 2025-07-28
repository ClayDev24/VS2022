#pragma once
#include <cmath>
#include <matplot/matplot.h>

void _textbox() {
    using namespace matplot;

    plot(iota(1, 10));
    textbox(2, 8, 4, 0.5, "String line from 1 to 10");

    show();
}