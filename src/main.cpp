/*
 * File:   main.cpp
 * Author: ch
 * Created on 6 de Novembro de 2018, 13:19
 */

#include <iostream>
#include "../include/Nodo.h"
#include "../include/Pessoa.h"
#include "../include/Tree.h"

using namespace std;

void menu() {
  cout << "\n\t**********MENU PRINCIPAL**********\n";
  cout << "\n\t[1] - Cadastrar Pessoa;\n\t[2] - Remover Pessoa;";
  cout << "\n\t[3] - Mostrar lista de Pessoas;\n\t[4] - Busca por CPF;";
  cout << "\n\t[S] - Sair;\n\n\tInsira aqui a sua opção: ";
}

int main(int argc, char** argv) {
  string opt;
  int age;
  long int term;
  Tree arvore;

  do {
    menu();
    cin >> opt;

    if (opt == "1") {
      system("clear");
      arvore.insert();

    } else if (opt == "2") {
      system("clear");
      cout << "\n\tInsira aqui o CPF que deseja pesquisar: ";
      cin >> term;
      system("clear");
      arvore.remove(term);

    } else if (opt == "3") {
      system("clear");
      arvore.print();

    } else if (opt == "4") {
      system("clear");
      cout << "\n\tInsira aqui o CPF que deseja pesquisar: ";
      cin >> term;
      system("clear");
      arvore.search(arvore.getRoot(), term);

    } else if (opt == "s" || opt == "S") {
      system("clear");
      cout << "\n\tAté +! Não deixe de falar do que achou do app\n\t";
      cout << "Envie um email para claudio.h1902@gmail.com\n\tEspero sua "
              "avaliação !\n";

    } else if (opt != "1" && opt != "2" && opt != "3" && opt != "4" &&
               opt != "s" && opt != "S") {
      system("clear");
      cout << "\n\tErro! Opção Inválida. Por favor tente novamente !\n ";
    }

  } while (opt != "S" && opt != "s");

  return 0;
}
