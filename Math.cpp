#include "Math.h"

using namespace Math;

float Math::clamp(const float &value, const float &low, const float &high) {
	if (value < low) return low;
	if (value > high) return high;
	return value;
}

float Math::crossProduct(float x1, float x2, float y1, float y2) {
	return (x1*y2)-(y1*x2);
}

float Math::dotProduct(float x1, float x2, float y1, float y2) {
	return (x1*x2)+(y1*y2);
}

///
///	Struct Vector 2D
///

const char *Vector2D::toCStr() {

	int maxSize = 87;
	char *buffer = new char[maxSize];

	const char *format = "[X:%f, Y:%f]";
	//sprintf(buffer, format, x, y);

	return buffer;

}

float Vector2D::angle(AngleType angleType) const {
	
	float angle = (float)atan2(y,x);

	if (angle < 0.f) angle += 2.f*(float)PI;

	if (angleType == AngleType::Degrees) {
		angle *= (180.f/(float)PI);
	}

	return angle;

}

float Vector2D::angle(const Vector2D& otherRef, AngleType angleType) const {

	float angle = (float)atan2(otherRef.crossProduct(*this), otherRef.dotProduct(*this));

	if (angle < 0.f) angle += 2.f*(float)PI;

	if (angleType == AngleType::Degrees) {
		angle *= (180.f/(float)PI);
	}

	return angle;
	
}

float Vector2D::crossProduct(float x, float y) const {
	return Math::crossProduct(this->x, x, this->y, y);
}

float Vector2D::crossProduct(const Vector2D &other) const {
	return Math::crossProduct(this->x, other.x, this->y, other.y);
}

float Vector2D::dotProduct(float x, float y) const {
	return Math::dotProduct(this->x, x, this->y, y);
}

float Vector2D::dotProduct(const Vector2D &other) const {
	return Math::dotProduct(this->x, other.x, this->y, other.y);
}

float Vector2D::magnitude() const { 
	return sqrt((this->x*this->x)+(this->y*this->y)); 
}

Vector2D Vector2D::setMagnitude(float value) {

	float rawLength = (x*x)+(y*y);

	if (rawLength == 0 || value*value == rawLength) {
		return *this;
	}

	Vector2D returnValue;
	returnValue.x = x*sqrt((value*value)/rawLength);
	returnValue.y = y*sqrt((value*value)/rawLength);

	return returnValue;

}

Vector2D Vector2D::operator +(const Vector2D& other) {

	Vector2D returnValue;

	returnValue.x = x + other.x;
	returnValue.y = y + other.y;

	return returnValue;

}

Vector2D Vector2D::operator -(const Vector2D& other) {

	Vector2D returnValue;

	returnValue.x = other.x - x;
	returnValue.y = other.y - y;

	return returnValue;

}

Vector2D Vector2D::rotate(float amount, AngleType angleType) const {

	Vector2D returnValue;

	//	Convert to Radians if amount isn't already to radians.
	float angle = amount;
	if (angleType == AngleType::Degrees) angle *= DegreesToRadConst;

	float cosine = cos(angle);
	float sine = sin(angle);

	returnValue.x = (this->x*cosine)-(this->y*sine);
	returnValue.y = (this->x*sine)+(this->y*cosine);

	return returnValue;

}

Vector2D::Vector2D() : x(0.f), y(0.f) {}

Vector2D::Vector2D(const Vector2D &other) 
	: x(other.x), y(other.y) {}

Vector2D::Vector2D(float x, float y) 
	: x(x), y(y) {}