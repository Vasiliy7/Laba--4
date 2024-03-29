﻿/** @class tree
@brief Класс, реализующий дерево элементов

Содержит методы добавления правого сына к любому узлу и методы печати всех элементов дерева в прямом, обратном и симметричном порядке. Вершина дерева представляется как узел, не имеющий отца
*/
#pragma once
#include "list.h"
#include "unit.h"

class tree
{
private:
	/**
	* @brief Статический метод поиска узла
	*
	* Производит поиск узла с заданным номеров во всём поддереве узла start. Номер в прямом порядке обхода
	* @param k номер узла
	* @param start указатель на вершину поддерева, в котором производится поиск
	* @param max вспомогательное число, помогающее производить поиск и проверять корректность результатов
	*/
	static unit* search(size_t k, unit* start, size_t* max);
	/**
	* @brief указатель на вершину дерева
	*/
	unit* base;
	/**
	* @brief Вспомогательный метод для рекурсивной печати
	*
	* Печатает левое поддерево определённого узла
	* @param start указатель на вершину поддерева
	* @param max вспомогательное число, помогающее проверить корректность результатов
	*/
	void printLeft(unit* start, size_t* max);
	/**
	* @brief Вспомогательный метод для рекурсивной печати
	*
	* Печатает правое поддерево определённого узла
	* @param start указатель на вершину поддерева
	* @param max вспомогательное число, помогающее проверить корректность результатов
	*/
	void printRight(unit* start, size_t* max);
	/**
	* @brief Вспомогательный метод для рекурсивной печати
	*
	* Печатает всё поддерево определённого узла в обратном порядке
	* @param start указатель на вершину поддерева
	* @param max вспомогательное число, помогающее проверить корректность результатов
	*/
	void printReverse(unit* start, size_t* max);
public:
	/**
	* @brief Создание дерева и инициализация вершины
	*/
	tree(int a);
	~tree();
	/**
	* @brief Добавление правого сына для определённого узла дерева
	* 
	* @param k номер узла
	* @param a значение добавляемого узла
	*/
	void add(size_t k, int a);
	/**
	* @brief Получение значения определённого узла дерева
	*
	* @param k номер узла
	*/
	int get(size_t k);
	/**
	* @brief Метод для печати всего дерева согласно определённому принципу обхода
	*
	* @param type способ обхода; 1 - для прямого, 2 - для обратного и 3 - для симметричного порядка обхода дерева
	* @param N число узлов дерева
	*/
	void print(size_t type, size_t N);
};

