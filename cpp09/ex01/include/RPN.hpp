#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN(void);

		void resolve(const std::string &operation);
		int calculate(const std::string &strOperator);
		int	addNumber(const std::string &str_number);
		__int64_t PopAndGet(void);

	private:
		std::stack<__int64_t> stack;
};

int	checkNumber(const std::string &strNumber);
int checkOperator(const std::string &Operator);
__int64_t makeOperation(char Operator, __int64_t firstNum, __int64_t secNum);

#endif
