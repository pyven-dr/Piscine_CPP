#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		const Fixed operator++(int);
		Fixed& operator--();
		const Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed&	min(Fixed& nb1, Fixed& nb2);
		static const Fixed&	min(const Fixed& nb1, const Fixed& nb2);
		static Fixed&	max(Fixed& nb1, Fixed& nb2);
		static const Fixed&	max(const Fixed& nb1, const Fixed& nb2);

	private:
		int	number;
		static const int fixed_point = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif