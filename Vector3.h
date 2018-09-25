#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <math.h>

template<class TYPE>
class Vector3
{
public:
	TYPE x, y, z;

	Vector3() {}
	Vector3(const TYPE &x, const TYPE &y, const TYPE &z) : x(x), y(y), z(z) {}

	Vector3(const TYPE &value) : x(value), y(value), z(value) {}

	Vector3(const Vector3 &vector) : x(vector.x), y(vector.y), z(vector.z) {}


	Vector3 operator+(const Vector3 &vector) const {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	}
	Vector3 operator-(const Vector3 &vector) const {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	}
	Vector3& operator+=(const Vector3 &vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;

		return *this;
	}
	Vector3& operator-=(const Vector3 &vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;

		return *this;
	}
	Vector3& operator=(const Vector3 &vector) {
		x = vector.x;
		y = vector.y;
		z = vector.z;

		return *this;
	}
	bool operator==(const Vector3 &vector) {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	void normalize() {
		TYPE magnitude = sqrtf((x*x) + (y*y) + (z*z));
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}
	void zero() {
		x = y = z = 0.0f;
	}
	bool is_zero() const {
		return (x == 0.0f && y == 0.0f && z == 0.0f);
	}
	TYPE distance_to(const Vector3 &vector) const {
		return sqrtf(((x - vector.x) * (x - vector.x)) + ((y - vector.y) * (y - vector.y)) + ((z - vector.z) * (z - vector.z)));
	}
	TYPE distance_to_nosqrt(const Vector3 &vector) const {
		return ((x-vector.x) * (x - vector.x)) + ((y - vector.y) * (y - vector.y)) + ((z - vector.z) * (z - vector.z));
	}
};

#endif

