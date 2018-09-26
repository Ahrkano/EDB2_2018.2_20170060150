/*
 * Arvore.cpp
 *
 *  Created on: 22 de set de 2018
 *      Author: Alexandre
 */

#include "Arvore.h"

Arvore::Arvore() {
	this->altura = 0;
}

int Arvore::getAltura() const {
	return altura;
}

void Arvore::setAltura(int altura) {
	this->altura = altura;
}

std::vector<No*> Arvore::getElementos(){
	return elementos;
}





//adiciona um no 'novo' como raiz ou como filho do no de chave '_val'
void Arvore::adicionar(No* novo, char _val){
	if(elementos.size() == 0)
	{
		elementos.push_back(novo);
		setAltura(getAltura()+1);
	}
	else
	{
		No* aux = buscar(elementos.front(), _val);
		if(aux!= NULL)
		{
			novo->setProfundidade(aux->getProfundidade()+1);
			novo->setPai(aux);

			if(aux->getFilhoEsq() == NULL)
			{
				aux->setFilhoEsq(novo);
			}
			else
			{
				aux = aux->getFilhoEsq();
				while(aux->getIrmaoDir() != NULL)
					aux = aux->getIrmaoDir();
				aux->setIrmaoDir(novo);
			}

			elementos.push_back(novo);
			setAltura(getAltura()+1);
		}
		else
			std::cout<<"Erro: no pai inexistente"<<std::endl;
	}
	return;
}

//atualmente funcao que apaga todos os nos da arvore
//TODO
void Arvore::remover(){

	for (std::vector<No* >::iterator it = elementos.begin() ; it != elementos.end(); ++it)
	{
		delete (*it);
	}
	elementos.clear();

	return;
}

//busca em profundidade
No* Arvore::buscar(No* raiz, char val){

	if (raiz->getDado() == val || raiz == NULL)
        return raiz;

	if(raiz != NULL)
	{
		buscar(raiz->getFilhoEsq(), val);
		buscar(raiz->getIrmaoDir(), val);
	}

	return NULL;
}


No* Arvore::busca_largura(No* raiz, char val){

	if (raiz->getDado() == val || raiz == NULL)
	        return raiz;

	if(raiz != NULL)
	{
		buscar(raiz->getIrmaoDir(), val);
		buscar(raiz->getFilhoEsq(), val);
	}

	return NULL;
}


//funcao que itea ate a raiz
No* Arvore::itera_raiz(No* atual){

	if(elementos.size() != 0)
	{
		No* aux = atual;
		while(aux != elementos.front())
		{
			aux = aux->getPai();
		}
		return aux;
	}

	return NULL;
}

//funcao imprime para verificar os nos inseridos
void Arvore::imprime_arvore(){

	if(elementos.size() != 0)
	{
		for (unsigned int i = 0 ; i < elementos.size(); i++)
		{
			std::cout<<elementos.at(i)->getDado()<<" "<<std::endl;
		}
	}
	else
	{
		std::cout<<" Arvore vazia "<<std::endl;
	}

}

Arvore::~Arvore() {
	// TODO Auto-generated destructor stub
}

