#include "complex.h"
#include <cstdlib>
#include <cctype>
#include <cmath>
#define PI 3.14159265359

using namespace std; 
using namespace yatospace_numbers;


namespace yatospace_numbers {
	static const Quadrant q0 = Quadrant(0);
	static const Quadrant q1 = Quadrant(1);
	static const Quadrant q2 = Quadrant(2);
	static const Quadrant q3 = Quadrant(3);
	static const Quadrant q4 = Quadrant(4);

	bool operator==(const Quadrant& a, const Quadrant& b) {
		return a.value == b.value;
	}
	bool operator!=(const Quadrant& a, const Quadrant& b) {
		return a.value != b.value;
	}
	bool operator<=(const Quadrant& a, const Quadrant& b) {
		return a.value <= b.value;
	}
	bool operator>=(const Quadrant& a, const Quadrant& b) {
		return a.value >= b.value; 
	}
	bool operator<(const Quadrant& a, const Quadrant& b) {
		return a.value < b.value;
	}
	bool operator>(const Quadrant& a, const Quadrant& b) {
		return a.value > b.value;
	}

	ostream& operator<<(ostream& stream, const Complex& point)
	{
		if (point.imag == 0.0 && point.real == 0) return stream << "0";
		else if (point.imag == 0.0) return stream << point.real;
		else if (point.real == 0.0) {
			if (point.imag < 0.0) return stream << "-i" << -point.imag;
			else stream << "i" << point.imag;
		}
		else if (point.imag < 0) return stream << point.real << "-i" << -point.imag;
		else             return stream << point.real << "+i" << point.imag;
	}
	

	istream& operator>>(istream& stream, Complex& point) {
		string number = "";  istream& streem = stream >> number;
		const int len = number.length();
		char* const text = new char[len + 5];
		int i = 0; 
		double real = 0, imag = 0;
		bool realMode = true, 
			 positive = true,
			 negative = false, 
			 realSign = false, imagSign = false,
			 realDot = false, imagDot = false;
		char previous = 0;
		char next = 0;
		double realDotBase = 1.0; 
		double imagDotBase = 1.0; 
		text[i] = '\0'; 
		if (len == 0) throw "Complex number. Number";
		for (i = 0; i < number.length(); i++)
			text[i] = number.at(i);
		if (text[i - 1] == '+') throw "Complex number. Number";
		if (text[i - 1] == '-') throw "Complex number. Number";
		if (text[i - 1] == 'i') throw "Complex number. Number";
		for (i = 0; i < number.length(); i++) {
			if (i != 0) previous = text[i - 1];
			if (i != number.length() - 1) next = text[i + 1];
			else next = 0; 
			if (isdigit(text[i]) || text[i]=='.') {
				if (realMode) {
					realSign = true;
					if (text[i] == '.') {
						if (realDot) throw "Complex Number. Dot.";
						realDot = true; 
					}
					else if (!realDot) {
						real *= 10;
						switch (text[i]) {
							case '0':
								real += 0;
								break;
							case '1':
								real += 1;
								break;
							case '2':
								real += 2;
								break;
							case '3':
								real += 3;
								break;
							case '4':
								real += 4;
								break;
							case '5':
								real += 5;
								break;
							case '6':
								real += 6;
								break;
							case '7':
								real += 7;
								break;
							case '8':
								real += 8;
								break;
							case '9':
								real += 9;
								break;
						}
					}
					else {
						realDotBase /= 10;
						switch (text[i]) {
							case '0':
								real += 0.0l *realDotBase;
								break;
							case '1':
								real += 1.0l *realDotBase;
								break;
							case '2':
								real += 2.0l * realDotBase;
								break;
							case '3':
								real += 3.0l * realDotBase;
								break;
							case '4':
								real += 4.0l * realDotBase;
								break;
							case '5':
								real += 5.0l * realDotBase;
								break;
							case '6':
								real += 6.0l * realDotBase;
								break;
							case '7':
								real += 7.0l * realDotBase;
								break;
							case '8':
								real += 8.0l * realDotBase;
								break;
							case '9':
								real += 9.0l * realDotBase;
								break;
							}
					}
				} 
				else {
					imagSign = true;
					realSign = true;
					if (text[i] == '.') {
						if (imagDot) throw "Complex Number. Dot.";
						imagDot = true; 
					}
					else if (!imagDot) {
						imag *= 10; 
						switch (text[i]) {
							case '0':
								imag += 0;
								break;
							case '1':
								imag += 1;
								break;
							case '2':
								imag += 2;
								break;
							case '3':
								imag += 3;
								break;
							case '4':
								imag += 4;
								break;
							case '5':
								imag += 5;
								break;
							case '6':
								imag += 6;
								break;
							case '7':
								imag += 7;
								break;
							case '8':
								imag += 8;
								break;
							case '9':
								imag += 9;
								break;
						}
					}
					else {
						imagDotBase /= 10; 
						switch (text[i]) {
							case '0':
								imag += 0.0l*imagDotBase;
								break;
							case '1':
								imag += 1.0l*imagDotBase;
								break;
							case '2':
								imag += 2.0l*imagDotBase;
								break;
							case '3':
								imag += 3.0l*imagDotBase;
								break;
							case '4':
								imag += 4.0l*imagDotBase;
								break;
							case '5':
								imag += 5.0l*imagDotBase;
								break;
							case '6':
								imag += 6.0l*imagDotBase;
								break;
							case '7':
								imag += 7.0l*imagDotBase;
								break;
							case '8':
								imag += 8.0l*imagDotBase;
								break;
							case '9':
								imag += 9.0l*imagDotBase;
								break;
							}
					}
				}
			}
			else if (realMode) {
				if (text[i] == '+') {
					if (realSign && next != 'i') throw "Complex number. Sign."; 
					if (!realMode && imagSign) throw "Complex number. Sign.";
					if (previous == '+') throw "Complex number. Sign.";
					if (previous == '-') throw "Complex number. Sign.";
					if (previous == 'i') throw "Complex number. Sign.";
					if (negative) real = -real;
					positive = true;
					negative = false;
				}
				else if (text[i] == '-') {
					if (realSign && next != 'i') throw "Complex number. Sign.";
					if (!realMode && imagSign) throw "Complex number. Sign.";
					if (previous == '+') throw "Complex number. Sign.";
					if (previous == '-') throw "Complex number. Sign.";
					if (previous == 'i') throw "Complex number. Sign.";
					if (negative) real = -real;
					positive = false;
					negative = true;
				}
				else if (text[i] == 'i') {
					if (!realMode) throw "Complex number. Sign";
					if (previous == 'i') throw "Complex number. Sign.";
					realMode = false;
					if (previous == '-') {
						positive = false;
						negative = true;
					}
					else if (previous == '+') {
						negative = false;
						positive = true;
					}
					else if (previous != 0) {
						throw "Complex number. Number";
					}
				}
				else {
					throw "Complex number. Number";
				}
			}
			else {
				throw "Complex number. Number.";
			}
		}
		if (realMode) {
			if (negative) real = -real;
		}
		else {
			if (negative) imag = -imag;
		}

		delete[] text;
		point.real = real;
		point.imag = imag;
		return stream;
	}

	Complex operator+(const Complex& a, const Complex& b) {
		Complex res = Complex();
		res.real = a.real + b.real; 
		res.imag = a.imag + b.imag;
		return res;
	}
	Complex operator-(const Complex& a, const Complex& b) {
		Complex res = Complex();
		res.real = a.real - b.real;
		res.imag = a.imag - b.imag;
		return res;
	}
	Complex operator*(const Complex& a, const Complex& b) {
		Complex res =  Complex();
		res.real = a.real * b.real - a.imag * b.imag;
		res.imag = a.real * b.imag + a.imag * b.real; 
		return res; 
	}
	Complex operator/(const Complex& a, const Complex& b) {
		Complex res = Complex(); 
		res.real = a.real * b.real + a.imag * b.imag;
		res.imag = a.imag * b.real - a.real * b.imag;
		res.real /= b.real * b.real + b.imag * b.imag; 
		res.imag /= b.real * b.real + b.imag * b.imag;
		return res; 
	}

	double Complex::module() {
		return sqrt(real * real + imag * imag);
	}

	Quadrant Complex::quadrant() {
		if (real > 0 && imag > 0) return q1;
		if (real < 0 && imag > 0) return q2;
		if (real < 0 && imag < 0) return q3;
		if (real > 0 && imag < 0) return q4;
		return q0;
	}

	double Complex::argument() {
		return atan(abs(imag)/abs(real))*(180 / PI);
	}

	double Complex::phase() {
		if (imag == 0 && real > 0) return 0; 
		if (imag == 0 && real < 0) return 180;
		if (imag > 0 && real == 0) return 90;
		if (imag < 0 && real == 0) return 270;
		if (quadrant() == q1) return argument(); 
		if (quadrant() == q2) return 180 - argument();
		if (quadrant() == q3) return 180 + argument(); 
		if (quadrant() == q4) return 360 - argument();
		throw "Complex number. Zero quadrant point phase.";
	}
}

