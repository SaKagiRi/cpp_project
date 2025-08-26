#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fBit = 8;
	public:
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed& other);
		~Fixed(void);

		Fixed&		operator=(const Fixed& other);

		bool		operator<(const Fixed& source);
		bool		operator<=(const Fixed& source);
		bool		operator>(const Fixed& source);
		bool		operator>=(const Fixed& source);
		bool		operator==(const Fixed& source);
		bool		operator!=(const Fixed& source);

		float		operator+(const Fixed& source);
		float		operator-(const Fixed& source);
		float		operator*(const Fixed& source);
		float		operator/(const Fixed& source);

		Fixed		operator--();
		Fixed		operator--(int);
		Fixed		operator++();
		Fixed		operator++(int);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

		static	const	Fixed&	min(const Fixed& a, const Fixed& b);
		static	Fixed&	min(Fixed& a, Fixed& b);
		static	const	Fixed&	max(const Fixed& a, const Fixed& b);
		static	Fixed&	max(Fixed& a, Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fix);

#endif
