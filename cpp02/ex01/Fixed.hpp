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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int	number;
		static const int fixed_point = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif