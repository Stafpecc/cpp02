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