#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void adiciona_tarefa();
vector <string> recebe_lista();
void organiza_lista(vector<string> linhas);
void mostra_lista(vector<string> linhas, int chama);
void remove_item(vector<string> linhas);

int main(){

    int escolha;
    cout << "[1] - Adicionar novas tarefas " << endl
         << "[2] - Ver as tarefas existentes" << endl
         << "[3] - Excluir alguma tarefa" << endl
         << "[0] - Sair" << endl;
    cin >> escolha;

    system ("cls"); // system ("clear");

    if (escolha == 1)
    {
        adiciona_tarefa();
    }

    else if (escolha == 2)
    {
        mostra_lista(recebe_lista(), 2);
    }

    else if (escolha == 3)
    {
        remove_item(recebe_lista());
    }

    else if (escolha == 0)
    {
        return 0;
    }

    else
    {
        main();
    }

    return 0;
}

/// Passando Instruções para as Funções

void adiciona_tarefa()
{
    char verificar;
    string tarefa;

    ofstream arquivo_adicionar;
    arquivo_adicionar.open ("Tarefas.txt", ios :: app);

    do{
        cout << "Digite uma nova tarefa: ";
        cin.ignore();
        getline(cin, tarefa);
        
        if (tarefa[0] >= 'a' && tarefa [0] <='z')
        {
            tarefa[0] = _toupper(tarefa[0]);
        }

        arquivo_adicionar << tarefa << endl;

        cout << "Deseja digitar uma nova tarefa? [s/n]";
        cin >> verificar;

    }while (verificar == 's');

    arquivo_adicionar.close();
    organiza_lista(recebe_lista());

    system ("cls"); // system ("clear");
    main();
}


vector <string> recebe_lista()
{
    string linha;
    vector<string> linhas;

    ifstream arquivo_organizar;
    arquivo_organizar.open("Tarefas.txt", ios::app);

    while (!arquivo_organizar.eof()) {
        getline(arquivo_organizar, linha);
        linhas.push_back(linha);
    }
    return linhas;
}


void organiza_lista(vector<string> linhas)
{
    ofstream arquivo_ordem;
    arquivo_ordem.open ("Tarefas.txt");

    sort (linhas.begin(), linhas.end());

    for (string adiciona : linhas)
    {
        if (adiciona.length() > 1)
        {
            arquivo_ordem << adiciona << endl;
        }
    }
    arquivo_ordem.close();
}


void mostra_lista(vector<string> linhas, int chama)
{
    int aumenta = 1;
    organiza_lista(recebe_lista());
    for (string linha : linhas)
    {
        if (aumenta < linhas.size())
        {
            cout << aumenta << "- "<< linha << endl;
            aumenta ++;
        }
    }
    if (chama == 2)
    {
        system ("pause");
        system ("cls"); // system ("clear");
        main();
    }
}


void remove_item(vector<string> linhas)
{
    int posicao;
    char continua;

    ofstream arquivo_adicionar;
    arquivo_adicionar.open ("Tarefas.txt");
    do {
        mostra_lista(linhas, 3);
        cout << "Digite o numero da linha que deseja apagar" << endl;
        cin >> posicao;

        posicao--;
        linhas.erase(linhas.begin() + posicao);
        organiza_lista(linhas);

        cout << "Deseja deletar outra linha?[s/n]";
        cin >> continua;

    }while (continua == 's');

    organiza_lista(linhas);

    system ("cls"); // system ("clear");
    main();

}
