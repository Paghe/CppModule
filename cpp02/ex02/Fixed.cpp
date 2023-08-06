#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = src.getRawBits();
}

Fixed::Fixed(const int intValue) : _value(intValue << _fractionalBit)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : _value(roundf(floatValue * (1 << _fractionalBit)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return *this;
}

void   Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int  Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

float Fixed::toFloat(void) const
{
    float floatValue;
    floatValue = static_cast<float>(this->_value) / (1 << _fractionalBit);
    return (floatValue);
}

int Fixed::toInt(void) const
{
    return(this->_value >> _fractionalBit);
}

bool Fixed::operator>(Fixed const &value) const
{
    return (this->_value > value._value);
}

bool Fixed::operator<(Fixed const &value) const
{
    return (this->_value < value._value);
}

bool Fixed::operator>=(Fixed const &value) const
{
    return (this->_value >= value._value);
}

bool Fixed::operator<=(Fixed const &value) const
{
return (this->_value <= value._value);
}

bool Fixed::operator==(Fixed const &value) const
{
    return (this->_value == value._value);
}

bool Fixed::operator!=(Fixed const &value) const
{
return (this->_value != value._value);
}

Fixed Fixed::operator+(Fixed const &value) const
{
   return Fixed(this->toFloat() + value.toFloat());
}

Fixed Fixed::operator*(Fixed const &value) const
{
    return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator-(Fixed const &value) const
{
    return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator/(Fixed const &value) const
{
    return Fixed(this->toFloat() / value.toFloat());
}

Fixed& Fixed::operator++()
{
    (this->_value)++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed keep(this->_value);
    (this->_value)++;
    return (keep);
}

Fixed& Fixed::operator--()
{
    (this->_value)--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed keep(this->_value);
    (this->_value)--;
    return (keep);
}

Fixed& Fixed::max(Fixed &valueOne, Fixed &valueTwo)
{
    if (valueOne > valueTwo)
        return (valueOne);
    else
        return (valueTwo);
}

Fixed& Fixed::min(Fixed &valueOne, Fixed &valueTwo)
{
    if (valueOne < valueTwo)
        return (valueOne);
    else
        return (valueTwo);
}

const Fixed& Fixed::max(Fixed const &valueOne, Fixed const &valueTwo)
{
    if (valueOne > valueTwo)
        return (valueOne);
    else
        return (valueTwo);
}

const Fixed&  Fixed::min(Fixed const &valueOne, Fixed const &valueTwo)
{
    if (valueOne < valueTwo)
        return (valueOne);
    else
        return (valueTwo);
}
std::ostream & operator<<(std::ostream &o, const Fixed &i)
{
    o << i.toFloat();
    return (o);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
