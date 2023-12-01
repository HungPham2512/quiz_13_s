#include "../header/fresher.h"

    Fresher::Fresher(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, std::string gradDate,std::string gradRank, std::string gradSchool)
    : Employee(id, eName, eBirthDay, ePhoneNum, eEmail, EmployeeType::FRESHER), gradDate(gradDate), gradRank(gradRank), gradSchool(gradSchool) {}

    std::string Fresher::getGradDate() const
    {
        return gradDate;
    }

    std::string Fresher::getGradRank() const
    {
        return gradRank;
    }

    std::string Fresher::getGradSchool() const
    {
        return gradSchool;
    }

    void Fresher::setGradDate(std::string date) 
    {
        gradDate = date;
    }

    void Fresher::setGradRank(std::string rank) 
    {
        gradRank = rank;
    }

    void Fresher::setGradSchool(std::string school) 
    {
        gradSchool = school;
    }

    void Fresher::showInfo() 
    {
        std::cout << getID() <<" "<< getEName() <<" "<< getEBirthDay() <<" " << getEPhoneNum()<<" "<< getEEmail()<<" "<< getGradDate()<<" "<<getGradRank()<<" "<<getGradSchool()<<std::endl;
    }