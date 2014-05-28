#include "list.h"
#include "tree.h"
#include "unit.h"
#include <iostream>

tree::tree(int a)
{
	this->base = new unit(a, nullptr);
}

tree::~tree()
{
}

void tree::add(size_t k, int a)
{
	size_t max;
	unit* p = this->search(k, this->base, &max);
	if (k == max)
	{
		p->add(a);
	}
	else
	{
		std::cout << "ERROR!!!!!";
		system("pause");
	}
}

unit* tree::search(size_t k, unit* start, size_t* max)
{
	size_t it = 0;
	unit* p = start;
	while (p != nullptr)
	{
		it++;
		if (it == k)
		{
			*max = it;
			return p;
		}
		else
		{
			if (p->sun != nullptr)
			{
				size_t m = 0;
				unit* res = search(k - it, p->sun->getHead(), &m);
				if (res != nullptr)
				{
					*max = it + m;
					return res;
				}
				else
				{
					it += m;
				}
			}
			p = p->next;
		}
	}
	*max = it;
	return nullptr;
}

void tree::print(size_t type, size_t N)
{
	size_t max;
	switch (type)
	{
	case 1:
		max = 0;
		for (size_t i = 1; i <= N; i++)
		{
			unit* p = this->search(i, this->base, &max);
			std::cout << p->get() << " ";
		}
		break;
	case 2:
		max = 0;
		tree::printReverse(this->base, &max);
		if (max != N)
		{
			std::cout << "ERROR!!!!";
			system("pause");
		}
		break;
	case 3:
		max = 0;
		if (this->base->sun != nullptr)
		{
			tree::printLeft(this->base, &max);
			max++;
			std::cout << this->base->get() << " ";
			tree::printRight(this->base, &max);
		}
		else
		{
			max++;
			std::cout << this->base->get();
		}
		if (max != N)
		{
			std::cout << "ERROR!!!!";
			system("pause");
		}
		break;

	default:
		break;
	}
	std::cout << std::endl;
}

int tree::get(size_t k)
{
	size_t max;
	unit* p = this->search(k, this->base, &max);
	if (k == max)
	{
		return p->get();
	}
	else
	{
		std::cout << "ERROR!!!!!";
		system("pause");
		return -1;
	}
}

void tree::printLeft(unit* start, size_t* max)
{
	unit* p = start->sun->getHead();
	if (p->sun != nullptr)
	{
		tree::printLeft(p, max);
		(*max) += 1;
		std::cout << p->get() << " ";
		tree::printRight(p, max);
	}
	else
	{
		(*max) += 1;
		std::cout << p->get() << " ";
	}
}

void tree::printRight(unit* start, size_t* max)
{
	unit* p = start->sun->getHead();
	p = p->next;
	while (p != nullptr)
	{
		if (p->sun != nullptr)
		{
			tree::printLeft(p, max);
			(*max) += 1;
			std::cout << p->get() << " ";
			tree::printRight(p, max);
		}
		else
		{
			(*max) += 1;
			std::cout << p->get() << " ";
		}
		p = p->next;
	}
}

void tree::printReverse(unit* start, size_t* max)
{
	unit* p = start;
	while (p != nullptr)
	{
		if (p->sun != nullptr)
		{
			tree::printReverse(p->sun->getHead(), max);
		}
		(*max)+=1;
		std::cout << p->get() << " ";
		p = p->next;
	}
}