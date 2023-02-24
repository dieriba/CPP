#include "./includes/Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    std::cout << bureaucrat.getName() << " bureaucrat grade is "
              << bureaucrat.getGrade() << std::endl;
    return os;
}

int main (void)
{
    Bureaucrat dieri("dieri", 1);
    std::cout << dieri;
    Bureaucrat bala("bala", 150);
    std::cout << bala;
    try
    {
        Bureaucrat nabs("nabs", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    
    try
    {
        Bureaucrat fanta("fanta", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        bala.upGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
    dieri.downGrade();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}