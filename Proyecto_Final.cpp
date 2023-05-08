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

vector<string> separar_terminos(const string& polinomio) {
    vector<string> terminos;
    string termino_actual = "";
    char signo_actual = '+';

    for (char c : polinomio) {
        if (c == '+' || c == '-') {
            if (!termino_actual.empty()) {
                termino_actual = signo_actual + termino_actual;
                terminos.push_back(termino_actual);
            }
            signo_actual = c;
            termino_actual = "";
        } else {
            termino_actual += c;
        }
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
	
//se llama a la funcion "polinomio_con_signo"
for(string polinomio : polinomios){
	string polinomio_csp = polinomio_con_signo(polinomio); //polinomio_csp = polinomio con signo  
	pol_cs.push_back(polinomio_csp);
}
 

	return 0;
}
          
