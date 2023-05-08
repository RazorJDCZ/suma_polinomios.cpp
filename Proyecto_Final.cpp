#include<iostream>;
#include<vector>;

using namespace std;
int main(){

  int n;
  
	cout<<"Ingresa la cantidad de polinomios a sumar: ";
	cin>>n;
    cin.ignore();
	if (n < 2){
        cout<<"     Por favor, ingresa mas de dos polinomios"<<endl<<endl;
        cout<<"     Ingrese la cantidad de polinomios a sumar:";
        cin>>n;
        cin.ignore();
    }
    
  vector<string>polinomios;
    string polinomio, polinomio_sin_es;
    for(int i=0; i<n; i++){
        cout<<"     Ingresa el polinomio "<<i+1<<" : ";
        getline (cin, polinomio);

}return 0;
          
