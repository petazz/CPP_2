
#include "Span.hpp"
#include <climits>

Span::Span(){
	N = 0;
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span (unsigned int N) {
	this->N = N;
	std::cout << "Span parameterized constructor called" << std::endl;	
}

Span::Span (const Span &other) {
	*this = other;
	std::cout << "Span copy constructor called" << std::endl;	
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->N = other.N;
		this->numbers = other.numbers;
	}
	std::cout << "Span assignment operator called" << std::endl;	
	return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;	
}

void Span::addNumber(int n) {
	if (numbers.size() >= N) {
		throw std::runtime_error("Span is full");
	}
	numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (numbers.size() + std::distance(start, end) > N) {
		throw std::runtime_error("Adding these numbers would exceed the span's capacity");
	}
	numbers.insert(numbers.end(), start, end);
}

int Span::shortestSpan() {
	if (numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	int minNum = *std::min_element(numbers.begin(), numbers.end());
	int maxNum = *std::max_element(numbers.begin(), numbers.end());
	return maxNum - minNum;
}

