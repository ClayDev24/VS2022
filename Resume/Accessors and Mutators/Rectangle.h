#pragma once

namespace resume {

	// Accessors & mutators with "get" and "set"
	class Rectangle {
		int width, height;
	public:
		Rectangle(const int& _w = 0, const int& _h = 0) :width(_w), height(_h) {}
		inline int  getWidth() const { return width; } //accessor
		inline void setWidth(const int& _w) { width = _w; } //mutator
		inline int  getHeight() const { return height; } //accessor
		inline void setHeight(const int& _h) { height = _h; } //mutator
	};

} // resume