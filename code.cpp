#include "list.h"
#include "tree.h"
#include "unit.h"
#include <iostream>

void main() {
	int N, k, ak;
	std::cin >> N;
	std::cin >> k >> ak;
	tree Tree = tree(ak);
	for (int i = 1; i < N; i++)
	{
		std::cin >> k >> ak;
		Tree.add(k, ak);
	}
	Tree.print(1, N);
	Tree.print(2, N);
	Tree.print(3, N);
}