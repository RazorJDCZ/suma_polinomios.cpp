#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Necesario para usar la función sort()
#include <cstdlib> // limpiar consola

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
    
    if (!termino_actual.empty()) {
        termino_actual = signo_actual + termino_actual;
        terminos.push_back(termino_actual);
    }

    return terminos;
}

vector<string> separar_terminos(const vector<string>& pol_cs) {
    vector<string> terminos;

    for (string polinomio : pol_cs) {
        vector<string> terminos_polinomio = separar_terminos(polinomio);
        terminos.insert(terminos.end(), terminos_polinomio.begin(), terminos_polinomio.end());
    }

    return terminos;
}

void elimina_termino(vector<string>& terminos) {
    for (auto it = terminos.begin(); it != terminos.end(); ++it) {
        if (it->find("0*x") != string::npos) {
            it = terminos.erase(it);
            --it;
        }
    }
}

vector<vector<double>> ordena_exponentes_y_coeficientes (vector<string> terminos){
    vector<vector<double>> coeficientes;
    double exponente, coeficiente_del_term;

    for (string termino : terminos) {
        size_t exponente_pos = termino.find("x");
        // Obtener la dirección de memoria del último carácter de termino
        char* ultimo_caracter = &termino[termino.length() - 1];
        // Verificar si exponente_pos es igual a la dirección de memoria del último carácter
        if (&termino[exponente_pos] == ultimo_caracter) {
            // exponente_pos es igual a la posición del último carácter de termino
            exponente = 1;
        } else if (exponente_pos == string::npos) {
            exponente = 0;
        } else {
            exponente = stod(termino.substr(exponente_pos + 1));
        }
        
        coeficiente_del_term = (stod(termino.substr(0, termino.find("*"))));
	
        bool exponente_encontrado = false;
        

        // Buscar si ya existe un vector en coeficientes con el exponente actual
        for (int i = 0; i < coeficientes.size(); i++) {
            if (exponente == coeficientes[i][0]) {
                exponente_encontrado = true;
                coeficientes[i].push_back(coeficiente_del_term);
                break;
            }
        }

        // Si no existe, agregar un nuevo vector con el exponente y el coeficiente actual
        if (!exponente_encontrado) {
            vector<double> coeficiente = {exponente, coeficiente_del_term};
            coeficientes.push_back(coeficiente);
        }
    }
    
    // Ordenar de mayor a menor los vectores dependiendo de los exponentes, es decir, la coef[0] de cada vector.
    sort(coeficientes.begin(), coeficientes.end(), [](const vector<double>& a, const vector<double>& b) {
    	return a[0] > b[0];
	});

    return coeficientes;
}

vector<vector<double>> suma_coeficientes(vector<vector<double>> coeficientes) {
    vector<vector<double>> vec_coefi_sumados;
    for (vector<double> coeficiente : coeficientes) {
        double suma = 0;
        for (int i = 1; i < coeficiente.size(); i++) {
            suma += coeficiente[i];
        }
        vector<double> coeficiente_sumado;
        coeficiente_sumado.push_back(coeficiente[0]);
        coeficiente_sumado.push_back(suma);
        vec_coefi_sumados.push_back(coeficiente_sumado);
    }
    return vec_coefi_sumados;
}
void resultado(vector<vector<double>> vec_coefi_sumados){
	for(vector<double>coefi : vec_coefi_sumados){
		if(coefi[1]!= 0){
			if(coefi[0] == 0){
			string coef_string = to_string(coefi[1]);
			if(coef_string[0] != '-'){
				if(coefi[1]!= 0){
					cout<<"+"<<coefi[1];
				}
				
			}else {
				if(coefi[1]!= 0){
					cout<<coefi[1];
				}
			}
			}else if(coefi[0]== 1){
				string coef_string = to_string(coefi[1]);
				if(coef_string[0] != '-'){
					if(coefi[1]!= 0){
						cout<<"+"<<coefi[1]<<"*x";
					}
					
				}else {
					cout<<coefi[1]<<"*x";
				}
			}else{
				string coef_string = to_string(coefi[1]);
				if(coef_string[0] != '-'){
					cout<<"+"<<coefi[1]<<"*x"<<coefi[0];
				}else {
					cout<<coefi[1]<<"*x"<<coefi[0];
				}
			}
		}
		
	}
}

bool revisarSignosSeguidos(string polinomio){
	char buffer = ' ';
	for(char caracter:polinomio){
		if(isdigit(caracter) or isalpha(caracter)){
			buffer = ' ';
			continue;
		} 
		else if (caracter==' '){
			continue;
		}
		else {
			if(buffer == ' '){
				buffer = caracter;
				continue;
			}
			system("cls");
			cout << endl<<"     El polinomio no debe contener dos signos juntos. Vuelve a ingresar el polinomio por favor." << endl << endl<<endl;
			return true;
		} 
	}
	return false;
}

bool revisarIfInt(string polinomio){
	for(char caracter:polinomio){
		if(isdigit(caracter)){
			continue;
		} 
		else {
			return false;
		}
	}
	return true;
}

bool validar_asteriscos(string polinomio){
    int astrsc = 0;
    size_t pos;
    string sub;
    for(char c: polinomio){
        if(c == '+' || c== '-'){
            pos = polinomio.find(c);
            sub = polinomio.substr(0, pos);
            polinomio = polinomio.substr(pos + 1);
            for(char c: sub){
                if(c == '*'){
                    astrsc ++;
                }
            }
            if (astrsc > 1){
                system("cls");
                cout<<"     No se permite ingresar mas de un '*' dentro de un mismo termino. Por favor vuelva a ingresar el polinomio."<<endl<<endl<<endl;
                return true;
            }
            astrsc = 0;
        }
    }
    for(char c: polinomio){
        if(c == '*'){
            astrsc ++;
        }
    }
    if (astrsc > 1){
        system("cls");
        cout<<"     No se permite ingresar mas de un '*' dentro de un mismo termino. Por favor vuelva a ingresar el polinomio."<<endl<<endl<<endl;
        return true;
    }
    return false;
}

bool revisarEspacios(string polinomio) {
    bool espacioEntreNumeros = false;
    bool hayOperador = false;

    for (int i = 0; i < polinomio.size(); i++) {
        char caracter = polinomio[i];

        if (isdigit(caracter) or isalpha(caracter)) {
            if (i > 0 and polinomio[i+1] == ' ' and !hayOperador) {
                espacioEntreNumeros = true;
                break;
            }
        } else if (caracter == '+' or caracter == '-' or caracter == '*') {
            hayOperador = true;
        }
    }

    if (espacioEntreNumeros) {
	system("cls");
        cout <<endl<< "     No se permite ingresar un numero separado por un espacio. Vuelve a ingresar el polinomio por favor." << endl << endl<<endl;
        return true;
    }

    return false;
}

bool revisarNumerosDespuesDeAsterisco(string polinomio) {
    bool asteriscoEncontrado = false;
    bool hayNumeroDespuesDeAsterisco = false;
 
    for(int i=0; i<polinomio.size();++i){
    	char caracter = polinomio[i];

    	if(caracter =='*'){
    		if(isdigit(polinomio[i+1])){
			system("cls");
    			cout << endl << "     No se permite colocar un numero despues de un asterisco ('*').Vuelve a ingresar el polinomio por favor." << endl<<endl<<endl;
                return true;
			}
		}
	}

    return false;
}

bool revisarNumVariables(string polinomio, char variable = 'x'){
	for(char caracter:polinomio){
		if(isdigit(caracter)){
			continue;
		} else if(caracter == '*' or caracter == '+' or caracter == '-' or caracter =='.'){
			continue;
		}
		else if(isalpha(caracter)){
			if(caracter != variable){
				system("cls");
				cout << "     El polinomio solo debe contener una variable, por defecto x (minuscula). Vuelve a ingresar el polinomio por favor." << endl << endl<<endl;
				return true;
			}
		}
	}
	return false;
}
	
bool revisarAlphaNum(string polinomio){
	for(char caracter:polinomio){
		if(isdigit(caracter)){
			continue;
		}
		else if(isalpha(caracter)){
			continue;
		}
		else {
			if (caracter == '*' or caracter == '+' or caracter == '-' or caracter == ' ' or caracter =='.'){
				continue;
			}
			
			else{
				system("cls");
				cout << "     No se permite usar caracteres alpha numericos diferentes que: '*', '+' y '-'.";
				cout<<endl<<"     Vuelve a ingresar el polinomio por favor." << endl << endl<<endl;
				return true;
			}
			}
		}
	return false;
	}

int main(){
	
 int n;
string n_input;
vector<string>pol_cs; //pol_cs =  vector de polinomios con signo
cout<<endl<<"     * * * * * SUMA DE POLINOMIOS * * * * * "<<endl<<endl;
	
while(true){
	cout<<"Ingresa la cantidad de polinomios a sumar: ";
	cin>>n_input;
	cin.ignore();
	if(stoi(n_input) < 2 or revisarIfInt(n_input) == false){
		system("cls");
		cout << endl << "     Valor no permitido. Usa un valor entero igual o mayor a 2" << endl << endl;
		continue;
	}
	else{
		n = stoi(n_input);
		break;
	}
	}
  
vector<string>polinomios;
string polinomio, polinomio_sin_es;
for(int i=0; i<n; i++){
    	do{
        cout<<"     Ingresa el polinomio "<<i+1<<" : ";
        getline(cin, polinomio);
    	}
	//Se revisa si hay signos seguidos, caracteres alpha numericos o la variable es x
	while( revisarNumVariables(polinomio) or revisarSignosSeguidos(polinomio) or revisarAlphaNum(polinomio) or revisarEspacios(polinomio) or revisarNumerosDespuesDeAsterisco(polinomio) or validar_asteriscos(polinomio));
//se llama a la funcion que quita los espacios a la cadena "polinomio"
polinomio_sin_es = limpiar_espacios(polinomio);
polinomios.push_back(polinomio_sin_es);
}
	
//se llama a la funcion "polinomio_con_signo"
for(string polinomio : polinomios){
	string polinomio_csp = polinomio_con_signo(polinomio); //polinomio_csp = polinomio con signo  
	pol_cs.push_back(polinomio_csp);
}

//se llama a la funcion "separar_terminos" (para vectores)
vector<string> terminos = separar_terminos(pol_cs);
	
//se llama a la funcion "elimina_termino" que revisa si hay un 0*x y lo elimina del programa
elimina_termino(terminos);

//se llama a la funcion "ordena_exponentes_y_coeficientes"
vector<vector<double>>coeficientes = ordena_exponentes_y_coeficientes(terminos);

//se llama a la funcion "suma_coeficientes"
vector<vector<double>> vec_coefi_sumados = suma_coeficientes(coeficientes);

//se define al grado del polinomio
 double grado = coeficientes[0][0];
system("cls");
cout<<endl<<"     * * * * * //R E S U L T A D O S// * * * * * "<<endl<<endl;
 
 cout<<endl<<"     El grado del polinomio sumado es: "<<grado;
    
 //Se llama a la funcion "resultado"
cout<<endl<<"     El polinomio sumado es: ";
resultado(vec_coefi_sumados);
	
	return 0;
}
          
