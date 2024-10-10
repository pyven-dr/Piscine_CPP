#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdlib>
#include <vector>
#include <exception>

class Span
{
	public:
		Span(void);
		explicit Span(unsigned int N);
		Span(const Span& copy);
		~Span(void);
		Span& operator=(const Span& other);

		void addNumber(int number);

		template<typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			unsigned int size = std::distance(begin, end);
			if (this->NumList.size() + size > N)
				throw Span::SpanFull();
			this->NumList.insert(this->NumList.end(), begin, end);
		}

		int shortestSpan(void);
		int longestSpan(void);

	private:
		unsigned int N;
		std::vector<int> NumList;

		class SpanFull: public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class NotEnoughNumbers: public std::exception
		{
			virtual const char* what(void) const throw();
		};
};

#endif
