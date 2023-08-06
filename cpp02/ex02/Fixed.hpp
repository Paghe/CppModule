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
    bool operator>(Fixed const &value)const;
    bool operator<(Fixed const &value) const;
    bool operator>=(Fixed const &value) const;
    bool operator<=(Fixed const &value) const;
    bool operator==(Fixed const &value) const;
    bool operator!=(Fixed const &value) const;
    Fixed operator+(Fixed const &value) const;
    Fixed operator*(Fixed const &value) const;
    Fixed operator-(Fixed const &value) const;
    Fixed operator/(Fixed const &value) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static Fixed& max(Fixed &valueOne, Fixed &valueTwo);
    static Fixed& min(Fixed &valueOne, Fixed &valueTwo);
    static const Fixed& max(Fixed const &valueOne, Fixed const &valueTwo);
    static const Fixed& min(Fixed const &valueOne, Fixed const &valueTwo);
    ~Fixed(void);
    int    toInt(void)const;
    float  toFloat(void)const;
    int  getRawBits(void) const;
    void    setRawBits(int const raw);

};

std::ostream & operator<<(std::ostream &o, const Fixed &i);
#endif