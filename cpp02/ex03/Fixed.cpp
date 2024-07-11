#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->number = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	this->number = copy.getRawBits();
}

Fixed::Fixed(const int number)
{
	this->number = number << fixed_point;
}

Fixed::Fixed(const float number)
{
	this->number = roundf(number * (1 << fixed_point));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return (*this);
	this->number = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
	os << number.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->number > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->number < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->number >= other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->number != other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->number == other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	this->number += 1;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	this->operator++();
	return (copy);
}

Fixed &Fixed::operator--()
{
	this->number -= 1;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	this->operator--();
	return (copy);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return (this->number);
}

void Fixed::setRawBits(const int raw)
{
	this->number = raw;
}

int Fixed::toInt() const
{
	return (this->number >> fixed_point);
}

float Fixed::toFloat() const
{
	return((float)this->number / (float)(1 << fixed_point));
}

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}