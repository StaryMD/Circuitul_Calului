#pragma once

template <typename T>
struct Vector2 {
	T x, y;

	Vector2() { }
	Vector2(const T &x_, const T &y_) {
		x = x_;
		y = y_;
	}

	inline Vector2 operator +(const Vector2 &oth) {
		return Vector2(x + oth.x, y + oth.y);
	}

	inline Vector2 operator =(const Vector2 &oth) {
		x = oth.x;
		y = oth.y;
		return *this;
	}

};
