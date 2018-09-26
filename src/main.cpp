/*
 * main.cpp
 *
 *  Created on: 25 de set de 2018
 *      Author: Alexandre
 */


#include <iostream>
#include "No.h"
#include "Arvore.h"

int main()
{
	Arvore Bank;
	No* teste = new No('@');

	Bank.adicionar(teste, 'X');
	Bank.imprime_arvore();
	Bank.remover();
	Bank.imprime_arvore();

	delete teste;
	return 0;
}

