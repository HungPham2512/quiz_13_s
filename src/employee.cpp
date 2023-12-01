#include "../header/employee.h"


    Employee::Employee(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, EmployeeType eType)
    : id(id), eName(eName), eBirthDay(eBirthDay), ePhoneNum(ePhoneNum), eEmail(eEmail), eType(eType){}

    void Employee::addCertificate (std::shared_ptr<Certificate> cer)
    {
        CertificateList.push_back(cer);
    }

    int Employee::getID() const
    {
        return id;
    }

    std::string Employee::getEName() const
    {
        return eName;
    }

    std::string Employee::getEBirthDay() const
    {
        return Employee::eBirthDay;
    }

    std::string Employee::getEPhoneNum() const
    {
        return Employee::ePhoneNum;
    }

    std::string Employee::getEEmail() const
    {
        return eEmail;
    }

    EmployeeType Employee::getEType() const
    {
        return eType;
    }    

    void Employee::setEName(std::string& name) 
    {
        eName = name;
    }

    void Employee::setEBirthDay(std::string& birthDay) 
    {
        eBirthDay = birthDay;
    }

    void Employee::setEPhoneNum(std::string& phoneNum) 
    {
        ePhoneNum =  phoneNum;
    }

    void Employee::setEEmail(std::string& email) 
    {
        eEmail =  email;
    }

