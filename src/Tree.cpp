/*
 * File:   Tree.cpp
 * Author: ch
 * Created on 6 de Novembro de 2018, 13:24
 */

#include "../include/Tree.h"

Tree::Tree() {
  this->root = NULL;
  this->quant = this->height = 0;
}

Tree::Tree(const Tree& orig) {
  this->root = orig.getRoot();
  this->height = orig.getHeight();
  this->quant = orig.getQuant();
}

Tree::~Tree() {}

void Tree::setHeight(int height) {
  this->height = height;
}

int Tree::getHeight() const {
  return height;
}

void Tree::setQuant(int quant) {
  this->quant = quant;
}

int Tree::getQuant() const {
  return quant;
}

void Tree::setRoot(Nodo* root) {
  this->root = root;
}

Nodo* Tree::getRoot() const {
  return root;
}

bool Tree::isEmpty() {
  if (this->quant == 0)
    return true;
  else
    return false;
}

Nodo* Tree::previous(Nodo* no) {
  if (no->GetLeft() != NULL) {  // se houver algo à sua esquerda...
    return antecessor(no->GetLeft());
  } else {
    cout << "\n\tEste nó não possui antecessor\n";
    return NULL;
  }
}

Nodo* Tree::antecessor(Nodo* no) {
  if (no->GetRight() != NULL)
    return antecessor(no->GetRight());
  else
    return no;
}

Nodo* Tree::next(Nodo* no) {
  if (no->GetRight() != NULL) {
    return sucessor(no->GetRight());
  } else {
    cout << "\n\tEste nó não possui sucessor.\n";
    return NULL;
  }
}

Nodo* Tree::sucessor(Nodo* no) {
  if (no->GetLeft() != NULL)
    return sucessor(no->GetLeft());
  else
    return no;
}

void Tree::print() {
  int opt = 0;
  do {
    cout << "\n\tQual algoritmo deseja utilizar? ";
    cout << "\n\t[1] - Pré-Ordem;\n\t[2] - Em Ordem;\n\t[3] - "
            "Pós-Ordem;\n\tInsira aqui a sua opção: ";
    cin >> opt;

    if (opt != 1 && opt != 2 && opt != 3)
      cout << "\n\tErro! Opção Inválida.\n";

  } while (opt != 1 && opt != 2 && opt != 3);

  if (opt == 1)
    preOrdem(this->root);
  else if (opt == 2)
    emOrdem(this->root);
  else if (opt == 3)
    posOrdem(this->root);
  if (this->isEmpty() == true)
    cout << "\n\tA lista está vazia.\n";
  else
    cout << "\n\tQuant: " << this->quant << "\n";
}

void Tree::preOrdem(Nodo* no) {
  if (no != NULL) {  // esse é o meu 'critério de parada'. Quando ele achar
                     // algum nulo, ele para a recursão
    no->GetItem().print();
    preOrdem(no->GetLeft());
    preOrdem(no->GetRight());
  }
}

void Tree::emOrdem(Nodo* no) {
  if (no != NULL) {
    emOrdem(no->GetLeft());
    no->GetItem().print();
    emOrdem(no->GetRight());
  }
}

void Tree::posOrdem(Nodo* no) {
  if (no != NULL) {
    posOrdem(no->GetLeft());
    posOrdem(no->GetRight());
    no->GetItem().print();
  }
}

void Tree::insert() {
  Pessoa claudio;
  claudio.fill();
  Nodo* filho = new Nodo(claudio);

  if (isEmpty() == true) {
    this->root = filho;
    filho->SetDad(NULL);
    this->quant++;
  } else {
    insertAux(this->root, claudio);
  }
}

void Tree::insertAux(Nodo* pai, Pessoa& claudio) {
  // se for menor, então insere à esquerda
  if (claudio.getCpf() < pai->GetItem().getCpf()) {
    // verifica se a esquerda é nulo
    if (pai->GetLeft() == NULL) {
      Nodo* filho = new Nodo(claudio);
      pai->SetLeft(filho);
      filho->SetDad(pai);
      this->quant++;
    } else {
      // senão, continua percorrendo recursivamente
      insertAux(pai->GetLeft(), claudio);
    }
  }  // se for maior, então insere à direita
  else if (claudio.getCpf() > pai->GetItem().getCpf()) {
    // verifica se a direita é nulo
    if (pai->GetRight() == NULL) {
      Nodo* filho = new Nodo(claudio);
      pai->SetRight(filho);
      filho->SetDad(pai);
      this->quant++;
    } else  // senão, continua percorrendo recursivamente
      insertAux(pai->GetRight(), claudio);
  }
  // se for igual, não vai poder inserir, já que não podem existir 2 nós iguais
}

Nodo* Tree::search(Nodo* no, long int term) {
  if (no != NULL) {
    int result = no->GetItem().comparacao(term);

    if (result == 0) {
      cout << "\n\tAqui está.\n";
      no->GetItem().print();
      return no;
    } else if (result == -1) {  // busca recursiva à esquerda
      return search(no->GetLeft(), term);
    } else if (result == 1) {  // busca recursiva à esquerda
      return search(no->GetRight(), term);
    }
  } else {  // caso ele percorra toda a árvore sem sucesso...
    cout << "\n\tA busca não encontrou resultados para o CPF [" << term
         << "].\n";
    return NULL;
  }
}

void Tree::remove(long int term) {
  Nodo* tchau = search(this->root, term);  // nodo que será removido
  Nodo* paiDoTchau = tchau->GetDad();
  int filhos = tchau->numberSons();  // número de filhos
  int result = paiDoTchau->GetItem().comparacao(
      term);  // verificando se 'tchau' é menor ou maior que o pai

  if (filhos == 0) {
    if (result == -1) {  // se o pai for menor, aponta o direito pra nulo
      paiDoTchau->SetRight(NULL);
      tchau->SetDad(NULL);
    } else if (result == 1) {  // se o pai for maior, aponta a esquerda pra nulo
      paiDoTchau->SetLeft(NULL);
      tchau->SetDad(NULL);
    } else {
      cout << "\n\tSe vc está vendo isso, há um item duplicado na árvore.\n\n";
    }
  } else if (filhos == 1) {  // caso 'tchau' tenha um filho, "este irá ocupar o
                             // lugar dele"
    Nodo* filhoDoTchau;
    if (tchau->GetLeft() != NULL) {  // se o 'filhoDoTchau' estiver à
                                     // esquerda...
      paiDoTchau->SetLeft(filhoDoTchau);
      filhoDoTchau->SetDad(paiDoTchau);
      tchau->SetDad(NULL);
    } else if (tchau->GetRight() != NULL) {
      paiDoTchau->SetRight(filhoDoTchau);
      filhoDoTchau->SetDad(paiDoTchau);
      tchau->SetDad(NULL);
    }
  } else if (filhos == 2) {
    // aí fudeu bahia
  }
}
// eu não sei o que essa função faz
/*Nodo* Tree::choosePreviousOrNext (Nodo* no) {
    Nodo* antecessor = previous (no);
    Nodo* sucessor = next (no);
    Nodo* substituto;

    if (sucessor == 0)
        substituto = sucessor;
        
    else if (antecessor == 0)
        substituto = antecessor;
        
    else if (sucessor < antecessor)
        substituto = sucessor;
        
    else if (sucessor > antecessor)
        substituto = antecessor;

    return substituto;
}*/
