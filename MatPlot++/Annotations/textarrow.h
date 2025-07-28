#include <cmath>
#include <matplot/matplot.h>

void _textarrow1() {
    using namespace matplot;

    plot(iota(1, 10));
    textarrow(2.5, 6.5, 5, 5, "y=x");

    show();
}


void _textarrow2() {
    using namespace matplot;

    plot(iota(1, 10));
    auto [t, a] = textarrow(2.5, 6.5, 5, 5, "y=x");
    t->color("red").font_size(14);
    a->color("blue");

    show();
}