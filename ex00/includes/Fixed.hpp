// • Membres publics :  
// ◦ Un constructeur par défaut qui initialise la valeur du nombre à virgule fixe à 0.  
// ◦ Un constructeur de recopie.  
// ◦ Une surcharge de l’opérateur d’affectation par copie.  
// ◦ Un destructeur.  
// ◦ Une fonction membre int getRawBits(void) const; qui renvoie la valeur brute du nombre à virgule fixe.  
// ◦ Une fonction membre void setRawBits(int const raw); qui définit la valeur brute du nombre à virgule fixe.

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:

		Fixed();
	
		Fixed(const Fixed& anotherClass);
		Fixed &operator=(const Fixed& anotherClass);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		~Fixed();
	
	private:

		int					_fixedPoint;
		static const int	_fractionalBit = 8;


};

#endif /* FIXED_HPP */