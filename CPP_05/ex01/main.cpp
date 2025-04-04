#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "---------VALID---------" << std::endl;
    try
    {
        Bureaucrat firstBureaucrat("FirstBureaucrat", 110);
        std::cout << firstBureaucrat << std::endl;

        Form firstForm("FirstForm", 110, 110);
        firstForm.beSigned(firstBureaucrat);
        std::cout << firstForm << std::endl;

        firstBureaucrat.signForm(firstForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------INVALID-------" << std::endl;
    try
    {
        Bureaucrat errorBureaucrat("Error Bureaucrat", 151);
        std::cout << errorBureaucrat << std::endl;

        Form errorForm("ErrorForm", 100, 100);
        errorForm.beSigned(errorBureaucrat);
        std::cout << errorForm << std::endl;

        errorBureaucrat.signForm(errorForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------DESTRUCTOR--------" << std::endl;
    return 0;
}
