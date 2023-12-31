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

Fixed& Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
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

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}