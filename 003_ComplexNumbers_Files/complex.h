#pragma once
#include<iostream>
#include<cstdlib>

using namespace std; 

namespace yatospace_numbers {
	class Quadrant {
		friend bool operator==(const Quadrant&, const Quadrant&);
		friend bool operator!=(const Quadrant&, const Quadrant&);
		friend bool operator<=(const Quadrant&, const Quadrant&);
		friend bool operator>=(const Quadrant&, const Quadrant&);
		friend bool operator<(const Quadrant&, const Quadrant&);
		friend bool operator>(const Quadrant&, const Quadrant&);

		private:
			int value = 0;
		public:
			Quadrant() {}

			Quadrant(int value) {
				if (value < 0) value = 0;
				if (value > 4) value = 0;
				this->value = value;
			}

			int getValue() {
				return value;
			}
	};

	class Complex
	{
		friend Complex operator+(const Complex&, const Complex&);
		friend Complex operator-(const Complex&, const Complex&);
		friend Complex operator*(const Complex&, const Complex&);
		friend Complex operator/(const Complex&, const Complex&);

		friend ostream& operator <<(ostream&, const Complex&);
		friend istream& operator >>(istream&, Complex&);

		private:
			double real = 0.0;
			double imag = 0.0;

		public:
			Complex(double a = 0.0) {
				this->real = a;
				this->imag = 0.0;
				cout << "Create complex number." << endl;
			}

			Complex(double a, double b) {
				this->real = a;
				this->imag = b;
				cout << "Create complex number." << endl;
			}

			~Complex() {
				cout << "Delete complex number." << endl;
			}

			int getReal() {
				return real;
			}

			int getImag() {
				return imag;
			}

			void setReal(int real) {
				this->real = real;
			}

			void setImag(int imag) {
				this->imag = imag;
			}

			double module();
			double argument();
			Quadrant quadrant();
			double phase(); 
	};


	class complex :
		public Complex
	{
	};
};