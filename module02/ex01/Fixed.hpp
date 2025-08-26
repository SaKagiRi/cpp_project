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

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fix);

#endif
