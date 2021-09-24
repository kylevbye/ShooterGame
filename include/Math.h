#pragma once
#include <cmath>
#include <string>
#include <cstdio>
#define PI 3.14159265358979f
#define RadToDegreeConst (180.f/PI)
#define DegreesToRadConst (PI/180.f)


namespace Math {

	enum AngleType { Degrees, Radians };

	float clamp(const float &value, const float &low, const float &high);
	float crossProduct(float x1, float x2, float y1, float y2);
	float dotProduct(float x1, float x2, float y1, float y2);

	struct Vector2D {

		float x, y;

		///
		///	String Representations
		///

		const char *toCStr();
		std::string to_string() { return std::string(toCStr()); }

		///
		///	Operations
		///

		float angle(AngleType angleType = AngleType::Degrees) const;
		float angle(const Vector2D& otherRef, AngleType angleType = 	AngleType::Degrees) const;
		float crossProduct(float x, float y) const;
		float crossProduct(const Vector2D &other) const;
		float dotProduct(float x, float y) const;
		float dotProduct(const Vector2D &other) const;
		float magnitude() const;
		Vector2D setMagnitude(float value);
		Vector2D operator +(const Vector2D& other);
		Vector2D operator -(const Vector2D& other);
		Vector2D rotate(float amount, AngleType angleType = AngleType::Degrees) const;

		///
		///	Constructors
		///

		Vector2D();
		Vector2D(const Vector2D &other);
		Vector2D(float x, float y);

		virtual ~Vector2D() {}

	};

}