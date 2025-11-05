#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		Fixed();
	
		Fixed(const Fixed& anotherClass);
		Fixed(const float constf);
		Fixed(const int intf);
		Fixed& operator=(const Fixed& anotherClass);

		bool operator>(const Fixed& anotherClass) const;
		bool operator<(const Fixed& anotherClass) const;
		bool operator<=(const Fixed& anotherClass) const;
		bool operator>=(const Fixed& anotherClass) const;
		bool operator==(const Fixed& anotherClass) const;
		bool operator!=(const Fixed& anotherClass) const;

		Fixed operator+(const Fixed& anotherClass) const;
		Fixed operator-(const Fixed& anotherClass) const;
		Fixed operator*(const Fixed& anotherClass) const;
		Fixed operator/(const Fixed& anotherClass) const;

		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();

		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

		int 	toInt(void) const;
		float 	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		~Fixed();
	
	private:

		int					_fixedPoint;
		static const int	_fractionalBit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& anotherClass);


#endif /* FIXED_HPP */