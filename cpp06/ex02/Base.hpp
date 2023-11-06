#pragma once

#include "iostream"
#include "cstdlib"
#include "ctime"

class Base
{
	public:
	Base();
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
	virtual ~Base();
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};