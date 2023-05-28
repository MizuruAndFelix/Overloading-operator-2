#include <iostream>
#include <cmath>
#include <locale.h>
#include <windows.h>
using namespace std;

class Fraction
{
private:
	int numerator_ = 0;
	int denominator_ = 0;
	int NOD(int numerator, int denominator) 
	{
		numerator = abs(numerator);
		denominator = abs(denominator);

		while (numerator > 0 && denominator > 0)
			if (numerator > denominator)
				numerator %= denominator;
			else
				denominator %= numerator;

		return numerator + denominator;
	}
public:
	Fraction() = default;
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	// t = temp
	Fraction operator + (const Fraction& other)//Сложение и сокращение 
	{
		Fraction t;

		t.numerator_ = ((this->numerator_ * other.denominator_) + (other.numerator_ * this->denominator_));
		t.denominator_ = (this->denominator_ * other.denominator_);

		int n = NOD(t.numerator_ , t.denominator_);

		t.numerator_ = t.numerator_ / n;
		t.denominator_ = t.denominator_ / n;

		return t;
	}

	Fraction operator - (const Fraction& other)//Вычитание и сокращение 
	{
		Fraction t;

		t.numerator_ = ((this->numerator_ * other.denominator_) - (other.numerator_ * this->denominator_));
		t.denominator_ = (this->denominator_ * other.denominator_);

		int n = NOD(t.numerator_, t.denominator_);

		t.numerator_ = t.numerator_ / n;
		t.denominator_ = t.denominator_ / n;

		return t;
	}

	Fraction operator * (const Fraction& other)//Умножение и сокращение 
	{
		Fraction t;

		t.numerator_ = this->numerator_ * other.numerator_;
		t.denominator_ = this->denominator_ * other.denominator_;

		int n = NOD(t.numerator_, t.denominator_);

		t.numerator_ = t.numerator_ / n;
		t.denominator_ = t.denominator_ / n;

		return t;
	}

	Fraction operator / (const Fraction& other)//Деление и сокращение 
	{
		Fraction t;

		t.numerator_ = this->numerator_ * other.denominator_;
		t.denominator_ = this->denominator_ * other.numerator_;

		int n = NOD(t.numerator_, t.denominator_);

		t.numerator_ = t.numerator_ / n;
		t.denominator_ = t.denominator_ / n;

		return t;
	}

	Fraction& operator++ ()//Инкремент префикс
	{
		this->numerator_ = this->numerator_ + this->denominator_;
		int n = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / n;
		this->denominator_ = this->denominator_ / n;

		return *this;
	}

	Fraction operator++ (int)//Инкремент постфикс
	{
		Fraction t = *this;

		this->numerator_ = this->numerator_ + this->denominator_;
		int n = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / n;
		this->denominator_ = this->denominator_ / n;

		return t;
	}

	Fraction& operator-- ()//Декремент префикс
	{
		this->numerator_ = this->numerator_ - this->denominator_;
		int n = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / n;
		this->denominator_ = this->denominator_ / n;

		return *this;
	}

	Fraction operator-- (int)//Декремент постфикс
	{
		Fraction temp = *this;

		this->numerator_ = this->numerator_ - this->denominator_;
		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return temp;
	}

	friend std::ostream& operator << (std::ostream& os, const Fraction& fra);
};

std::ostream& operator << (std::ostream& os, const Fraction& fra)
{
	if (fra.denominator_ == 1)
		os << fra.numerator_;
	else
		os << fra.numerator_ << "/" << fra.denominator_;

	return os;
}

int main()
{
	setlocale(LC_ALL, ".UTF8");
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int numerator1 = 3;
	int denominator1 = 4;
	int numerator2 = 4;
	int denominator2 = 5;


	cout << "Введите числитель дроби 1: ";
	cin >> numerator1;
	cout << "Введите знаменатель дроби 1: ";
	cin >> denominator1;

	cout << "Введите числитель дроби 2: ";
	cin >> numerator2;
	cout << "Введите знаменатель дроби 2: ";
	cin >> denominator2;


	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);


	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	cout << endl;


	cout << "++f1 = " << ++f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << "--f1 = " << --f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << "f1 = " << f1 << std::endl;
	cout << endl;


	cout << "f2++ = " << f1 << " * " << ++f2 << " = " << f1 * f2 << endl;
	cout << "f2-- = " << f1 << " * " << f2-- << " = " << f1 * f2 << endl;
	cout << "f2-- = " << f1 << " * " << f2-- << " = " << f1 * f2 << endl;
	cout << "f2 = " << f2 << endl;
	cout << endl;

	return 0;
}