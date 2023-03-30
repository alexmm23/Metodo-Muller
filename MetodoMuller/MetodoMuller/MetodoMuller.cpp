// MetodoMuller.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
using namespace std;

double f(double*, double, int);

int main()
{
	double x0, x1, x2, x3, errorR, errorActual; 
	double a, b, c, h0, h1, d0,d1;
	double* funcion;
	double coeficienteError,potenciaError;
	bool continuar = true;
	char cont = 'y';
	int pos = 0, pot, contador = 0;
	
	cout << fixed;
	cout << setprecision(6);

	while (continuar) {
		
		cout << "Metodo de Muller\n";
		cout << "Ingresa el cirterio de Error Relativo Absoluto" << endl;
		cout << "Nota: Primero ingresa el coeficiente y despues la potencia incluyendo el signo" << endl << endl;
		cout << "Coeficiente: ";
		cin >> coeficienteError;
		cout << "Potencia: ";
		cin >> potenciaError;

		errorR = pow(coeficienteError, potenciaError);
		errorActual = errorR + 1;
		system("cls");
		
		cout << "Ingresa la maxima potencia de x en la funcion: ";
		cin >> pot;

		//Inicializar el arreglo
		funcion = new double[pot + 1];
		pos = pot;
		for (int i = 0; i < pot + 1; i++) {
			cout << "Ingresa el coeficiente de x^" << pos << ":";
			cin >> funcion[i];
			pos--;

		}
		cout << "Ingresa el valor de X0, X1, X2 respectivamente\n";
		cout << "Xsub0: ";
		cin >> x0;

		cout << "Xsub1: ";
		cin >> x1;

		cout << "Xsub2: ";
		cin >> x2;

		system("cls");

		for (int i = 0; i < pot + 1; i++) {
			cout << "posicion " << i << " = " << funcion[i] << endl;
		}
		system("pause");
		system("cls");
		while (true) {
			
			//Calcular h
			h0 = x1 - x0;
			h1 = x2 - x1;

			//Calcular d
			d0 = (f(funcion, x1, pot) - f(funcion, x0, pot)) / h0;
			d1 = (f(funcion, x2, pot) - f(funcion, x1, pot)) / h1;

			//Calcular a,b,c
			a = (d1 - d0) / (h0 + h1);
			b = (a * h1) + d1;
			c = f(funcion, x2, pot);

			//Checar que valor tomará x3 según x2
			if (x2 >= 0) {
				x3 = x2 + ((-2 * c) / (b + sqrt(pow(b, 2) - (4 * a * c))));

			}
			else {
				x3 = x2 + ((-2 * c) / (b - sqrt(pow(b, 2) - (4 * a * c))));
			}

			//Calcular el error relativo en esta iteracion
			errorActual = abs((x3 - x2) / x3);

			//Imprimir resultados
			cout <<"Iteracion["<<contador<<"]" << " | x3 = " << x3 << " |";
			cout << "Error Relativo Absoluto = " << errorActual << " |" << endl;
			
			contador++;

			x1 = x2;
			x2 = x3;
			x3 = 0;
	
			if (errorActual < errorR) {
				break;
			}
		}
		//Continuar con el bucle?
		cout << "Deseas hacer otra operacion?[Y/N]: ";
		cin >> cont;
		system("cls");
		if (cont == 'y' || cont == 'Y') {
			continuar = true;
		}
		else {
			continuar = false;
		}
	}
}

double f(double* funcion, double x, int tamano) {
	double resultado = 0;
	int potencia = tamano + 1;
	int tamano2 = tamano;

	for(int i = 0; i < potencia; i++)
	{
		resultado += funcion[i]*pow(x,tamano2);
		tamano2--;
	}


	return resultado;
}


