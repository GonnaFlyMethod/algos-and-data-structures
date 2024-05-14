#include <iostream>

int find_greatest_common_devisor(int u, int v) {
	if (u == 0)
		return v;
	if (v == 0)
		return u;

	int k;
	for (k = 0; ((u | v) & 1) == 0; ++k) {
		u >>= 1;
		v >>= 1;
	}

	while ((u & 1) == 0)
		u >>= 1;

	do {
		while ((v & 1) == 0)
			v >>= 1;

		if (u < v)
			std::swap(u, v);

		u -= v;
	} while (u != 0);

	return v << k;
}

struct Fraction {
	int numerator, denominator;

	Fraction(int n, int d) : numerator(n), denominator(d){}
	Fraction() : numerator(1), denominator(1) {}

	Fraction Add(Fraction& other) {
		Fraction result{};

		if (denominator == other.denominator) {
			result.numerator = numerator + other.numerator;
			result.denominator = denominator;
		}
		else if (denominator % other.denominator == 0) {
			int multiplication_factor = denominator / other.denominator;
			
			result.numerator = multiplication_factor * other.numerator + numerator;
			result.denominator = denominator;
		}
		else if (other.denominator % denominator == 0) {
			int multiplication_factor = other.denominator / denominator;

			result.numerator = multiplication_factor * numerator + other.numerator;
			result.denominator = denominator;
		}
		else {
			result.numerator = (denominator * other.numerator) + (other.denominator * numerator);
			result.denominator = denominator * other.denominator;
		}

		int simplification_factor = find_greatest_common_devisor(result.numerator, result.denominator);

		result.numerator /= simplification_factor;
		result.denominator /= simplification_factor;
		
		return result;
	}
};

struct TestCase
{
	Fraction a, b, expected_result;

	TestCase(Fraction provided_a, Fraction provided_b, Fraction provided_expected_result)
		: a(provided_a), b(provided_b), expected_result(provided_expected_result) {}
};

int main() {
	const int NUMBER_OF_TESTCASES = 8;

	TestCase test_cases[NUMBER_OF_TESTCASES] = {
		// Common denominator
		
		TestCase(
			Fraction(6, 8),
			Fraction(6, 8),
			Fraction(3, 2)
		),
		TestCase(
			Fraction(6, 8),
			Fraction(3, 8),
			Fraction(9, 8)
		),

		// 1st denominator is divisable by the 2nd one

		TestCase(
			Fraction(6, 8),
			Fraction(4, 2),
			Fraction(11, 4)
		),
		TestCase(
			Fraction(6, 6),
			Fraction(7, 2),
			Fraction(9, 2)
		),

		// 2nd denominator is divisable by the 1st one
		TestCase(
			Fraction(4, 2),
			Fraction(6, 8),
			Fraction(11, 4)
		),
		TestCase(
			Fraction(7, 2),
			Fraction(6, 6),
			Fraction(27, 6)
		),

		// neither 1st denominator is devisable by the 2nd one nor the 2nd denominator is devisable by the 1st one:

		TestCase(
			Fraction(4, 9),
			Fraction(10, 15),
			Fraction(10, 9)
		),
		TestCase(
			Fraction(5, 8),
			Fraction(3, 7),
			Fraction(59, 56)
		),
	};

	for (int i{}; i < NUMBER_OF_TESTCASES; i++) {
		TestCase test_case = test_cases[i];
		
		Fraction a = test_case.a;
		Fraction b = test_case.b;

		Fraction actual_result = a.Add(b);

		if (actual_result.numerator != test_case.expected_result.numerator &&
			actual_result.denominator != test_case.expected_result.denominator) {

			std::cerr << "expected: "
				<< test_case.expected_result.numerator << '/'
				<< test_case.expected_result.denominator << '\n'

				<< "got: " << actual_result.numerator << '/'
				<< actual_result.denominator << '\n'
				<< "test index: " << i;

			return 1;
		}

	}

	std::cout << "Hooray! All tests passed" << '\n';

	return 0;
}