#include "list.h"
#include "tree.h"
#include "unit.h"
#include <iostream>

unit::unit(int a, unit* dad)
{
	this->value = a;
	this->next = nullptr;
	this->sun = nullptr;
	this->father = dad;
}

unit::~unit()
{

}

int unit::get()
{
	return this->value;
}

void unit::add(int a)
{
	if (this->sun == nullptr)
	{
		this->sun = new list(a, this);
	}
	else
	{
		this->sun->add(a);
	}
}