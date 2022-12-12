#include <iostream>
#include <Windows.h>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	
	bool operator==(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
		}
		if (n1 == n2) {
			return true;
		}
		else return false;
	}
	bool operator!=(const Fraction& f) {
		return !(*this == f);
	}

	bool operator<(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
		}
		if (n1 < n2) {
			return true;
		}
		else return false;
	}

	bool operator>(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
		}
		if (n1 > n2) {
			return true;
		}
		else return false;
	}

	bool operator<=(const Fraction& f) {
		return !(*this > f);
	}

	bool operator>=(const Fraction& f) {
		return !(*this < f);
	}

	std::string operator+(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
			n1 = n1 + n2;
		}
		while (true) {
			int x = 0;
			for (int i = 2; i < 100; i++) {
				if ((n1 % i) == 0 && (d1 % i) == 0) {
					n1 = n1 / i; d1 = d1 / i;
					x++;
				}
			}
			if (x == 0) break;
		}
		std::string str = std::to_string(n1);
		std::string str2 = std::to_string(d1);
		return str + '/' + str2;
	}

	std::string operator-(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
			n1 = n1 - n2;
		}
		while (true) {
			int x = 0;
			for (int i = 2; i < 100; i++) {
				if ((n1 % i) == 0 && (d1 % i) == 0) {
					n1 = n1 / i; d1 = d1 / i;
					x++;
				}
			}
			if (x == 0) break;
		}
		std::string str = std::to_string(n1);
		std::string str2 = std::to_string(d1);
		return str + '/' + str2;
	}

	std::string operator*(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		n1 = n1 * n2; d1 = d1 * d2;
		while (true) {
			int x = 0;
			for (int i = 2; i < 100; i++) {
				if ((n1 % i) == 0 && (d1 % i) == 0) {
					n1 = n1 / i; d1 = d1 / i;
					x++;
				}
			}
			if (x == 0) break;
		}
		std::string str = std::to_string(n1);
		std::string str2 = std::to_string(d1);
		return str + '/' + str2;
	}

	std::string operator/(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		n1 = n1 * d2; d1 = d1 * n2;
		while (true) {
			int x = 0;
			for (int i = 2; i < 100; i++) {
				if ((n1 % i) == 0 && (d1 % i) == 0) {
					n1 = n1 / i; d1 = d1 / i;
					x++;
				}
			}
			if (x == 0) break;
		}
		std::string str = std::to_string(n1);
		std::string str2 = std::to_string(d1);
		return str + '/' + str2;
	}

	std::string operator-() {
		int n1 = -numerator_, d1 = denominator_;
		std::string str = std::to_string(n1);
		std::string str2 = std::to_string(d1);
		return str + '/' + str2;
	}

	std::string operator++() {
		numerator_ = numerator_ + denominator_;
		std::string str = std::to_string(numerator_);
		std::string str2 = std::to_string(denominator_);
		return str + '/' + str2;
	}

	friend std::string operator++(Fraction& f, int);

	std::string operator--() {
		numerator_ = numerator_ - denominator_;
		std::string str = std::to_string(numerator_);
		std::string str2 = std::to_string(denominator_);
		return str + '/' + str2;
	}

	friend std::string operator--(Fraction& f, int);
	
	std::string printF() {
		std::string pstr = std::to_string(numerator_);
		std::string pstr2 = std::to_string(denominator_);
		return pstr + "/" + pstr2;
	}
};

std::string operator++(Fraction& f, int) {
	std::string str = std::to_string(f.numerator_);
	std::string str2 = std::to_string(f.denominator_);
	f.numerator_ = f.numerator_ + f.denominator_;
	return str + '/' + str2;
}

std::string operator--(Fraction& f, int) {
	std::string str = std::to_string(f.numerator_);
	std::string str2 = std::to_string(f.denominator_);
	f.numerator_ = f.numerator_ - f.denominator_;
	return str + '/' + str2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n1 = 0, d1 = 0, n2 = 0, d2 = 0;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> d1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> n2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d2; 
	std::cout << std::endl;
	Fraction f1(n1, d1);
	Fraction f2(n2, d2);

	std::cout << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " = " << (f1 + f2) << std::endl;
	std::cout << n1 << "/" << d1 << " - " << n2 << "/" << d2 << " = " << (f1 - f2) << std::endl;
	std::cout << n1 << "/" << d1 << " * " << n2 << "/" << d2 << " = " << (f1 * f2) << std::endl;
	std::cout << n1 << "/" << d1 << " / " << n2 << "/" << d2 << " = " << (f1 / f2) << std::endl;
	std::cout << n1 << "/" << d1 << "-" << " = " << -f1 << std::endl;
	std::cout << f1++ << "++" << " = ";
	std::cout << f1.printF() << std::endl;
	std::cout << "++" << ++f1 << " = ";
	std::cout << f1.printF() << std::endl;

	std::cout << f1-- << "--" << " = ";
	std::cout << f1.printF() << std::endl;
	std::cout << "--" << --f1 << " = ";
	std::cout << f1.printF() << std::endl;
}
