#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fBit = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);

		Fixed&		operator=(const Fixed& other);

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

#endif
