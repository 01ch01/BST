// by ch

#include "Pessoa.h"

#ifndef NODO_H
#define NODO_H

class Nodo {
 public:
  Nodo();
  Nodo(Pessoa& claudio);
  Nodo(const Nodo& orig);
  virtual ~Nodo();

  void SetItem(Pessoa item);
  Pessoa GetItem() const;
  void SetRight(Nodo* right);
  Nodo* GetRight() const;
  void SetLeft(Nodo* left);
  Nodo* GetLeft() const;
  void SetDad(Nodo* dad);
  Nodo* GetDad() const;
  void SetLevel(int level);
  int GetLevel() const;

  int numberSons();

 private:
  Pessoa item;
  Nodo* left;
  Nodo* right;
  Nodo* dad;
  int level;
};

#endif /* NODO_H */
