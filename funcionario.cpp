#include <iostream>
using namespace std;
#include <locale.h>

struct Funcionario
{
string nome;
int prontuario;
double salario;
struct Funcionario *prox;
};

Funcionario* init()
{
return NULL;
}

int isEmpty(Funcionario* funcionario)
{
return (funcionario==NULL);
}
Funcionario* validar(Funcionario* funcionario, int i){
Funcionario* aux;
   aux =funcionario;
    while (aux != NULL && aux->prontuario != i)
{
aux = aux->prox;
}
  return aux;
}
Funcionario* insert(Funcionario* funcionario, int i , double l,string nome)
{
Funcionario* novo = new Funcionario();
novo->prontuario = i;
novo->prox=funcionario;
novo->salario = l;
novo->prox=funcionario;
novo->nome = nome;
novo->prox=funcionario;
return novo;
}

Funcionario* remove(Funcionario* funcionario, int i)
{
 Funcionario *aux;
 Funcionario *ant = NULL;
 aux = funcionario;
 while (aux != NULL && aux->prontuario != i)
 {
  ant = aux;
  aux = aux->prox;
 }
 if (aux == NULL)
 {
  return funcionario;
 }
 if (ant == NULL)
 {
  funcionario = funcionario->prox;
 }
    else {
  ant->prox = aux->prox;
 }
 return funcionario;
}


Funcionario* find(Funcionario* funcionario, int i)
{
Funcionario* aux;
aux =funcionario;

while (aux != NULL && aux->prontuario != i)
{
aux = aux->prox;

}
return aux;

}
void print(Funcionario* funcionario)
{
Funcionario* aux;
aux = funcionario;
while(aux != NULL)
{
cout << "Prontuario do funcionario: " << aux->prontuario<< endl;
cout << "Nome: " <<aux->nome<<endl;
cout << "Salario: " <<aux->salario<<endl;

aux = aux->prox;
}
cout << endl;
}
int main(int argc, char** argv)
{
setlocale(LC_ALL, "Portuguese");
Funcionario *minhaLista;
minhaLista = init();
int pr,s,op;
string nome=" ";
do{
cout<< "------- Menu -------"<<endl;
cout<< "0. Sair"<<endl;
cout<< "1. Incluir"<<endl;
cout<< "2. Excluir"<<endl;
cout<< "3. Pesquisar"<<endl;
cout<< "4. Listar"<<endl;
cin>>op;

system("CLS");
if (op==1){
        cout<<"Digite o prontuário do novo funcionário: "<<endl;
cin>>pr;
Funcionario *procurado = validar(minhaLista, pr);
if  (procurado != NULL)
  {
  cout<<"Digite um prontuário valido"<<endl;
  cout<<"Digite o prontuário do novo funcionário"<<endl;
cin>>pr;
cout<<"Digite o nome do novo funcionário"<<endl;
cin>>nome;
cout<<"Digite o salario do novo funcionário"<<endl;
cin>>s;
minhaLista = insert(minhaLista, pr, s, nome);
system("CLS");
  }
else
{
cout<<"Digite o nome do novo funcionário"<<endl;
cin>>nome;
cout<<"Digite o salario do novo funcionário"<<endl;
cin>>s;
minhaLista = insert(minhaLista, pr, s, nome);
}
}
if (op==2){
cout << "Digite o prontuário que você deseja excluir: "<<endl;
cin>> pr;
minhaLista= remove(minhaLista, pr);

}
if (op==3){
cout << "digite o prontuário";
cin >> pr;
Funcionario *procurado = find(minhaLista, pr);
if (procurado != NULL)
{
     cout << "Prontuario: " << procurado->prontuario << endl;
cout << "Salario: " << procurado->salario << endl;
cout << "Nome: " << procurado->nome<< endl;
}
else
{
cout << "Dado nao encontrado!" << endl;
}
}
   if (op==4){
print(minhaLista);
}
}while (op!=0);
return 0;
}