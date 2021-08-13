#include "complex.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
using namespace yatospace_numbers;

int main(void)
{
	try {
		ifstream fin = ifstream("input.txt");
		ofstream fout = ofstream("outut.txt");
		
		Complex a = Complex();
		Complex b = Complex();

		fin >> a; 
		cout << "Ucitan prvi kompleksan broj iz ulazne datoteke.";
		fout << a << endl;
		cout << "Prvi broj je ispisan u izlaznu datoteku." << endl;
		fin >> b;
		cout << "Unesi drugi kompleksan broj iz datoteke";
		fout << b << endl;
		cout << "Drugi broj je ispisan u ulaznu datoteku." << endl;

		Complex c, d, e, f;
		c = a + b;
		d = a - b;
		e = a * b;

		bool dvdError = false;


		try { f = a / b; }
		catch (string err) { dvdError = true; }

		fout << c << endl;
		cout << "Zbir je upisan u izalznu datoteku. " << endl;
		fout << d << endl;
		cout << "Razlika je upisana u izlaznu datotetku." << endl;
		fout << e << endl;
		cout << "Proizvod je upisan u izlaznu datoteku." << endl;

		if (dvdError) {
			fout << "ND" << endl;
			cout << "Kolicnik je nedefinisan. Napomena upisana." << endl;
		}
		else
		{
			fout << f << endl;
			cout << "Kolicnik je upisan u izalznu datoteku." << endl;
		}

		fout << a.module() << endl;
		cout << "Moduo prvog broja je upisan u izlaznu datoteku." << endl;
		fout << b.module() << endl;
		cout << "Moduo drugog broja je upisan u izlaznu datoteku." << endl;
		fout << c.module() << endl;
		cout << "Moduo zbira je upisan u izlaznu datoteku." << endl;
		fout << d.module() << endl;
		cout << "Moduo razlike je upisan u izlaznu datoteku." << endl;
		fout << e.module() << endl;
		cout << "Moduo proizvoda je upisan u izlaznu datoteku." << endl;

		if (!dvdError) {
			fout << f.module() << endl;
			cout << "Moduo kolicnika je upisan u izlaznu datoteku." << endl;
		}
		else {
			fout << "ND" << endl;
			cout << "Napomena o nedefinisanom kolicniku pri modulima zapisana.";
		}

		fout << a.phase() << endl;
		cout << "Faza prvog broja je upisana u izlaznu datoteku." << endl;
		fout << b.phase() << endl;
		cout << "Faza drugog broja je upisana u izlaznu datoteku." << endl;
		fout << c.phase() << endl;
		cout << "Faza zbira je upisana u izlaznu datoteku." << endl;
		fout << d.phase() << endl;
		cout << "Faza razlike : " << endl;
		fout << e.phase() << endl;
		cout << "Faza proizvoda je upisana u izlaznu datoteku." << endl;

		if (!dvdError) {
			fout << f.phase() << endl; 
			cout << "Faza kolicnika je upisana u izlaznu datoteku." << endl;
		}
		else {
			fout << "ND" << endl;
			cout << "Napomena o nedefinisanom kolicniku pri fazama zapisana.";
		}

		fout.close();
		fin.close();
		return 0;
	}
	catch (string error) {
		cout << "Desila se greska.";
		cout << error << endl;
		return 0;
	}
}

