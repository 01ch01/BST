/*
 * File:   Tree.h
 * Author: ch
 *
 * Created on 6 de Novembro de 2018, 13:24
 */
#include "Nodo.h"
#include "Pessoa.h"
#ifndef TREE_H
#define TREE_H

class Tree {
 public:
  Tree();
  Tree(const Tree& orig);
  virtual ~Tree();

  void insert();
  void insertAux(Nodo* pai, Pessoa& claudio);

  void remove(long int term);
  Nodo* search(Nodo* no, long int term);

  Nodo* next(Nodo* no);  // esse é pra achar o menor dentre os maiores, ou seja,
                         // o sucessor
  Nodo* sucessor(
      Nodo* no);  // não me pergunte pq tem dois métodos aparentemente iguais,
                  // faça o rastreio e vc verá...*

  Nodo* previous(Nodo* no);  // esse é pra achar o maior dentre os menores, ou
                             // seja, o antecessor
  Nodo* antecessor(Nodo* no);  // idem*

  bool isEmpty();
  void print();

  Nodo* choosePreviousOrNext(Nodo* no);

  void preOrdem(Nodo* no);
  void emOrdem(Nodo* no);
  void posOrdem(Nodo* no);

  void setHeight(int height);
  int getHeight() const;
  void setQuant(int quant);
  int getQuant() const;
  void setRoot(Nodo* root);
  Nodo* getRoot() const;

 private:
  Nodo* root;
  int quant, height;
};

#endif /* TREE_H */
