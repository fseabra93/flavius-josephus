#include <iostream>
#include <vector>
using namespace std;

//void imprime(int num[]);
void imprime(vector<int>& vet, int tam);
void sort(vector<int>& arr, int size);
void remover1(vector<int>& arr, int & ini, int & t, int sto, int flag, int & ult, int & rst, vector<int>& arr2, int sto_ini);
void remover2(vector<int>& arr, int & ini, int & t, int flag, vector<int>& arr2, int sto_ini);


int main() {

  int valor = 1;
  int tam = 5;
  int & t = tam;
  cout << "Quantas pessoas há no círculo? ";
  cin >> tam;
  int flag = tam+1;
  int salto = 2;
  cout << "De quanto é o salto? ";
  cin >> salto;
  int resto = 0;
  int & rst = resto;

  int tam_inic = tam;
  int salto_ini = salto-1;
  
  vector<int> num (tam);
  vector<int> descartes = {};

  for (int j = valor, i=0; i < tam; i++, j++)
    num[i] = j;

int inicio = salto-1;
int & ini = inicio;
int ultimo;
int & ult = ultimo;

//imprime(num, tam);

while (tam > 0){


  //cout << "o salto é " << salto_ini+1 << " e o tam é " << tam << endl;
  if (salto_ini+1 < tam){
    
    //cout << "inicio= " << inicio << endl;
   // imprime(num, tam);
    remover1(num, inicio, tam, salto, flag, ultimo, resto, descartes, salto_ini);
    if (tam==1){
      break;
    }
   
    //cout << "inicio2= " << inicio << endl;
       
  } else {
    remover2(num, inicio, tam, flag, descartes, salto_ini);
    if (tam==1){
      break;
    }
    
    
    
   }
 
  }

  //imprime(descartes, tam_inic);
 ////////////////////////////////////////
  
}

void imprime(vector<int>& vet, int tam){

  for (int i=0; i<tam; i++){
    cout << vet[i] << " ";
  }
  cout << endl;
}



void sort(vector<int>& arr, int size){

  int dezena;

  int i, j, temp;

  for (i = 0; i < size-1; i++){
    for (j = i+1; j < size; j++){
      if (arr[i]>arr[j]){
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
      }
    }
  }
}


void remover1(vector<int>& arr, int & ini, int & t, int sto, int flag, int & ult, int & rst, vector<int>& arr2, int sto_ini){
      for (int i=ini; i<t; i+=sto){
        //cout << "remover o " << (arr[i])<<  endl;
        arr2.push_back(arr[i]);
        arr[i] = flag;
        ult = i;
      }
      //imprime(arr, t);
  
      //cout << "t= " << t << endl;
      //cout << "ult= " << ult << endl;
      if (ult < t-1){
        ini = sto-(t-1-ult)-1;
      } else {
        ini = sto_ini;
      }
      if (ini < 0){
        ini = -ini;
      }
      int remover = 0;
      for (int i=0; i<t; i++){
        if(arr[i] == flag){
          remover++;
        }
      }  
      sort(arr, t);

      for (int i=0; i<remover; i++){
        arr.pop_back();
      }

      t = arr.size();
    
      //cout << "tam = " << tam << endl;
  if (t==1){
    cout << "Flavius Josephus é o elemento " << arr[0] << "." << endl;
  }
      
      
}

void remover2(vector<int>& arr, int & ini, int & t, int flag, vector<int>& arr2, int sto_ini){
  //cout << "ini=" << ini << endl;
  //imprime(arr, t);
  //cout << "remover o " << (arr[ini])<<  endl;
  arr2.push_back(arr[ini]);
  arr[ini] = flag;
  //int remover = 0;
  /*for (int i=0; i<t; i++){
    if(arr[i] == flag){
      remover++;
    }
  }  */
  sort(arr, t);
  arr.pop_back();
  //imprime(arr, t-1);
  t = arr.size();
  //

  /*for (int i=0; i<remover; i++){
    arr.pop_back();
  }*/

  ini = ini + (sto_ini % t);
  if (ini==t){
    ini =0;
  } else if (ini > t){
    ini = ini-t;
  }

  //ini = sto_ini-arr.size();
  //ini = (ini%(sto_ini+1))+2;
  //ini = sto_ini - t;
  //cout << "t=" << t << endl;
  if (t==1){
    cout << "Flavius Josephus é o elemento " << arr[0] << "." << endl;
  }
  
}
