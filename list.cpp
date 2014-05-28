#include "list.h"
#include "tree.h"
#include "unit.h"
#include <iostream>


list::list(int a, unit* dad)
{
	this->head = new unit(a, dad);
}

list::~list()
{
}

void list::add(int a)
{
	unit* p = this->head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = new unit(a, this->head->father);
}

unit* list::getHead()
{
	return this->head;
}