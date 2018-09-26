/*
 * Arvore.h
 *
 *  Created on: 22 de set de 2018
 *      Author: Alexandre
 */

#ifndef SRC_ARVORE_H_
#define SRC_ARVORE_H_

#include <iostream>
#include <vector>
#include "No.h"

class Arvore {
private:
	int altura;
	std::vector<No*> elementos;

public:
	Arvore();
	virtual ~Arvore();

	int getAltura() const;
	void setAltura(int altura);

	std::vector<No*> getElementos();

	void adicionar(No* novo, char _val);
	void remover();

	No* buscar(No* raiz, char val);
	No* busca_largura(No* raiz, char val);
	No* itera_raiz(No* atual);

	void imprime_arvore();
};

#endif /* SRC_ARVORE_H_ */
