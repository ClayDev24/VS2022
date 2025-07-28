#pragma once
#include <cmath>
#include <matplot/matplot.h>

void _text1() {
    using namespace matplot;

    std::vector<double> x = iota(0, pi / 20, 2 * pi);
    std::vector<double> y = transform(x, [](auto x) { return sin(x); });
    plot(x, y);
    text(pi, 0, "← sin(π)");

    show();
}

void _text2() {
    using namespace matplot;

    std::vector<double> x = linspace(-5, +5);
    std::vector<double> y =
        transform(x, [](auto x) { return pow(x, 3) - 12 * x; });
    plot(x, y);

    std::vector<double> xt = { -2, +2 };
    std::vector<double> yt = { 16, -16 };
    std::string str = "dy/dx = 0";
    text(xt, yt, str);

    show();
}

#include <cmath>
#include <matplot/matplot.h>

void _text3() {
    using namespace matplot;

    std::vector<double> x = linspace(-5, +5);
    std::vector<double> y =
        transform(x, [](auto x) { return pow(x, 3) - 12 * x; });
    plot(x, y);

    std::vector<double> xt = { -2, +2 };
    std::vector<double> yt = { 16, -16 };
    std::vector<std::string> str = { "local max", "local min" };
    text(xt, yt, str);

    show();
}

void _text4() {
    using namespace matplot;

    plot(iota(1, 10));
    text(2, 7, "A simple plot\\nfrom 1 to 10");

    show();
}

void _text5() {
    using namespace matplot;

    plot(iota(1, 10));
    text({ 2, 8 }, { 7, 7 },
        std::vector<std::string>({ "A simple plot\\nfrom 1 to 10", "y=x" }));

    show();
}

void _text6() {
    using namespace matplot;

    plot(iota(1, 10));
    auto t = text(2, 8, "A simple plot")->color("red").font_size(14);

    show();
}

void _text7() {
    using namespace matplot;

    auto x = linspace(-5, +5);
    auto y = transform(x, [](double x) { return pow(x, 3) - 12 * x; });
    plot(x, y);
    auto t = text({ -2, 2 }, { 16, -16 }, "dy/dx=0");
    t->colors({ .0, 1. });
    t->sizes({ 14, 10 });
    gca()->colormap({ {1, 0, 0}, {0, 0, 0} });

    show();
}

void _text8() {
    using namespace matplot;

    auto y = transform(iota(1, 10), [](double x) { return pow(x, 2); });
    plot(y);

    text(3, 90, "λ_{12}^{3/2}/π - πΔ^{2/3}");
    text(4, 60, "lambda12^{3/2}/pi - pi delta^{2/3}");

    show();
}