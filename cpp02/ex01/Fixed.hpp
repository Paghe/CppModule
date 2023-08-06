#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBit = 8;
public:
    Fixed(void);
    Fixed(Fixed const & src);
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed& operator=(Fixed const &rhs);
    ~Fixed(void);
    int    toInt(void)const;
    float  toFloat(void)const;
    int  getRawBits(void) const;
    void    setRawBits(int const raw);

};

std::ostream & operator<<(std::ostream &o, const Fixed &i);
#endif