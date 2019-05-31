// by ch

#include "../include/Nodo.h"

Nodo::Nodo() {
  this->left = NULL;
  this->dad = NULL;
  this->right = NULL;
  this->level = 0;
}

Nodo::Nodo(Pessoa& claudio) {
  this->left = this->dad = this->right = NULL;
  this->level = 0;
  this->item.copy(claudio);
}

void Nodo::SetLevel(int level) {
  this->level = level;
}

int Nodo::GetLevel() const {
  return level;
}

Nodo::Nodo(const Nodo& orig) {
  this->dad = orig.GetDad();
  this->left = orig.GetLeft();
  this->right = orig.GetRight();
  this->item.copy(orig.GetItem());
}

Nodo::~Nodo() {}

void Nodo::SetItem(Pessoa item) {
  this->item = item;
}

Pessoa Nodo::GetItem() const {
  return item;
}

void Nodo::SetRight(Nodo* right) {
  this->right = right;
}

Nodo* Nodo::GetRight() const {
  return right;
}

void Nodo::SetLeft(Nodo* left) {
  this->left = left;
}

Nodo* Nodo::GetLeft() const {
  return left;
}

void Nodo::SetDad(Nodo* dad) {
  this->dad = dad;
}

Nodo* Nodo::GetDad() const {
  return dad;
}

int Nodo::numberSons() {
  if (this->right == NULL && this->left == NULL)
    return 0;
  else if ((this->right == NULL && this->left != NULL) ||
           (this->right != NULL && this->left == NULL))
    return 1;
  else if (this->right != NULL && this->left != NULL)
    return 2;
}
