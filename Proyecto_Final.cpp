#include<iostream>;
#include<vector>;

using namespace std;

string limpiar_espacios(string polinomio){
    string polinomio_sin_es ="";
    for (int i = 0; i<polinomio.length(); i++){
        if ( polinomio[i] != ' '){
            polinomio_sin_es += polinomio[i];
        }
    }
    return polinomio_sin_es;
}

string polinomio_con_signo (string polinomio){
    string polinomio_con_signo;
    if ((polinomio[0] != '+') && (polinomio[0] != '-')){
        char signo_a_insertar = '+';
        polinomio_con_signo = signo_a_insertar + polinomio;
    } else {
        polinomio_con_signo = polinomio;
    }
    return polinomio_con_signo;
}

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
}
//se llama a la funcion que quita los espacios a la cadena "polinomio"
polinomio_sin_es = limpiar_espacios(polinomio);
polinomios.push_back(polinomio_sin_es);

}return 0;
          
