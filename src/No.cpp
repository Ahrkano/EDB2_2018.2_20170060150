/*
 * No.cpp
 *
 *  Created on: 22 de set de 2018
 *      Author: Alexandre
 */

#include "No.h"

No::No() {
	this->dado = '@';
	this->filho_esq = NULL;
	this->irmao_dir = NULL;
	this->pai = NULL;
	this->profundidade = -1;
}

No::No(char _dado){
	this->dado = _dado;
	this->filho_esq = NULL;
	this->irmao_dir = NULL;
	this->pai = NULL;
	this->profundidade = 1;
}

No::No(char _dado, No* f_esq, No* i_dir, No* _pai){
	this->dado = _dado;
	this->filho_esq = f_esq;
	this->irmao_dir = i_dir;
	this->pai = _pai;
	this->profundidade = _pai->getProfundidade()+1;
}

char No::getDado(){
	return dado;
}

void No::setDado(char dado) {
	this->dado = dado;
}

No*& No::getFilhoEsq(){
	return filho_esq;
}

void No::setFilhoEsq(No*& filhoEsq) {
	this->filho_esq = filhoEsq;
}

No*& No::getIrmaoDir(){
	return irmao_dir;
}

void No::setIrmaoDir(No*& irmaoDir) {
	this->irmao_dir = irmaoDir;
}

No*& No::getPai(){
	return pai;
}

void No::setPai(No*& _pai){
	this->pai = _pai;
}

int No::getProfundidade() const {
	return profundidade;
}

void No::setProfundidade(int profundidade) {
	this->profundidade = profundidade;
}


No::~No() {
	// TODO Auto-generated destructor stub
}

