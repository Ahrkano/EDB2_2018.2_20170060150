/*
 * No.h
 *
 *  Created on: 22 de set de 2018
 *      Author: Alexandre
 */

#ifndef SRC_NO_H_
#define SRC_NO_H_

#include <iostream>

class No {
private:
	char dado;
	No* filho_esq;
	No* irmao_dir;
	No* pai;
	int profundidade;

public:
	No();
	No(char _dado);
	No(char _dado, No* f_esq, No* i_dir, No* _pai);
	virtual ~No();

	char getDado();
	void setDado(char dado);

	No*& getFilhoEsq();
	void setFilhoEsq(No*& filhoEsq);

	No*& getIrmaoDir();
	void setIrmaoDir(No*& irmaoDir);

	No*& getPai();
	void setPai(No*& _pai);

	int getProfundidade() const;
	void setProfundidade(int profundidade);
};

#endif /* SRC_NO_H_ */
