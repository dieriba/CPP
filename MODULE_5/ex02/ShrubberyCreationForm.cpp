#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/AForm.hpp"
#include <fstream>
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm():AForm("test", 145, 137),target("target")
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("target", 145, 137),target(target)
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs):AForm(rhs.getTarget(), 145, 137),target(rhs.target)
{
    setIsSigned(rhs.getIsSigned());
};
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this == &rhs)
        return (*this);
    setIsSigned(rhs.getIsSigned());
    return (*this);
};
ShrubberyCreationForm::~ShrubberyCreationForm(){;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/
/*----------------------------MEMBER FUNCTION----------------------------*/
const std::string& ShrubberyCreationForm::getTarget(void) const {return target;};

void  ShrubberyCreationForm::formMessage(void) const
{
    std::string file_name(target + "_shruberry");
    std::ofstream outfile(file_name.c_str());
    outfile.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);
    outfile << "            .        +          .      .          ." << std::endl;
    outfile << "     .            _        .                    ." << std::endl;
    outfile << ",              /;-._,-.____        ,-----.__" << std::endl;
    outfile << "((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
    outfile << "`                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
    outfile << "                     ,    `./  \\:. `.   )==-'  ." << std::endl;
    outfile << "   .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
    outfile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
    outfile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
    outfile << " .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
    outfile << " `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
    outfile << "             \\:  `  X` _| _,\\/'   .-'" << std::endl;
    outfile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
    outfile << "                    \\::.  :\\/:'  /              +" << std::endl;
    outfile << "  .                 `.:.  /:'  }      ." << std::endl;
    outfile << "           .           ):_(:;   \\           ." << std::endl;
    outfile << "                     /:. _/ ,  |" << std::endl;
    outfile << "                 . (|::.     ,`                  ." << std::endl;
    outfile << "  .                |::.    {\\" << std::endl;
    outfile << "                   |::.\\  \\ `." << std::endl;
    outfile << "                     |:::(\\    |" << std::endl;
    outfile << "             O       |:::/{ }  |                  (o" << std::endl;
    outfile << "              )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
    outfile << "         ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
}
/*----------------------------MEMBER FUNCTION----------------------------*/