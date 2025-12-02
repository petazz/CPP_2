#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span {
	private:
		std::vector<int> numbers;
		unsigned int N;
	public:

		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif