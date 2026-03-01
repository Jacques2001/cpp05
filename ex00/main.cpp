#include "Bureaucrat.hpp"

int main() 
{
    Bureaucrat test("Jacques", 1);
    for (int i = 0; i < 150; i++)
    {
        std::cout << "min grade : " << test << std::endl;
        test.minGrade();
    }
    
    Bureaucrat test2("Bob", 150);
    for (int i = 0; i < 150; i++)
    {
        std::cout << "inc grade : " << test2 << std::endl;
        test2.plusGrade();
    }
    return 0;
}