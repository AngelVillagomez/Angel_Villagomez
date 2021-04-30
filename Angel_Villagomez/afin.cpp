#include <iostream>
#include <string>
using namespace std;

int divis(int a1, int b1)
{
	int q = 0;
	int r = 0;

	if (a1 == b1)
	{
		return 0;
	}

	else if (a1 > 0)
	{
		while (a1 > b1)
		{
			a1 = a1 - b1;
			q++;
		}

		r = a1;
	}
	else
	{
		while (a1 < 0)
		{
			a1 = a1 + b1;
			q--;
		}
		r = a1;
	}

	return r;
}

int encriptar(string mensaje_original, int a, int b, string alfa)
{
	string alphaL = alfa;
	// mod n
	int mensage_l = mensaje_original.length();

	for (int i = 0; i < mensage_l; i++)
	{
		for (int j = 0; j < alphaL.length(); j++)
		{
			if (mensaje_original[i] == alphaL[j])
			{
				// j es la posicion en el alphabeto de la leta, a = 0, b = 1 , c = 2 . . . . . etc 
				int result = divis((j * a) + b, alphaL.length());
				mensaje_original[i] = alphaL[result];
				break;
			}
		}

	}
	cout << mensaje_original;
	return 1;
}

int desencriptar(string mensaje_original, int a, int b, string alfa)
{
	string alphaL = alfa;

	// mod n
	int n = 0;
	while (divis(a * n, alphaL.length()) != 1)
	{
		n++;
	}

	int mensage_l = mensaje_original.length();

	for (int i = 0; i < mensage_l; i++)
	{
		for (int j = 0; j < alphaL.length(); j++)
		{
			if (mensaje_original[i] == alphaL[j])
			{
				int result = divis(n * (j - b), alphaL.length());
				mensaje_original[i] = alphaL[result];
				break;
			}
		}
	}

	cout << mensaje_original;
	return 1;
}

int mcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}

	return mcd(divis(b, a), a);
}

int revisar(string mensaje_original, int a, int b, string alfa)
{
	string alphaL = alfa;

	if (mcd(a, alphaL.length()) != 1)
	{
		cout << "El mcd no es 1, no se puede descifrar" << endl;
	}

	cout << "1 para encriptar, 2 para desencriptar: ";
	int choice;
	cin >> choice;
	cin.ignore();

	if (choice == 1)
	{
		encriptar(mensaje_original, a, b, alphaL);
	}

	else if (choice == 2)
	{
		desencriptar(mensaje_original, a, b, alfa);
	}

	else
	{
		cout << "Ingrese un numero correcto" << endl;
		revisar(mensaje_original, a, b, alfa);
	}

	return 1;
}



int main()
{
	int a;
	string alfa("abcdefghijklmnopqrstuvwxyz,.-_ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789()");
	cout << "Ingrese a (decimacion): ";
	cin >> a;

	int b;
	cout << "Ingrese b (desplazamiento): ";
	cin >> b;


	cin.ignore();

	cout << "mensaje: ";
	string mensaje_original;
	getline(cin, mensaje_original);

	revisar(mensaje_original, a, b, alfa);
}




