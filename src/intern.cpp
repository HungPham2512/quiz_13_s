#include "../header/intern.h"

    Intern::Intern(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, std::string major,std::string semester, std::string uniName)
    : Employee(id, eName, eBirthDay, ePhoneNum, eEmail, EmployeeType::INTERN), major(major), semester(semester), uniName(uniName) {}

    std::string Intern::getMajor() const
    {
        return major;
    }

    std::string Intern::getSemester() const
    {
        return semester;
    }

    std::string Intern::getUniName() const
    {
        return uniName;
    }

    void Intern::setMajor(std::string& maj) 
    {
        major = maj;
    }

    void Intern::setSemester(std::string& sem) 
    {
        semester = sem;
    }

    void Intern::setUniName(std::string& uni)  
    {
        uniName = uni;
    }

    void Intern::showInfo() 
    {
        std::cout << getID() <<" "<< getEName() <<" "<< getEBirthDay() <<" " << getEPhoneNum()<<" "<< getEEmail()<<" "<< getMajor()<<" "<<getSemester()<<" "<<getUniName()<<std::endl;
    }