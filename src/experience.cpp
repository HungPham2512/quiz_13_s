#include "../header/experience.h"

    Experience::Experience(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, int expInYear,std::string proSkill)
    : Employee(id, eName, eBirthDay, ePhoneNum, eEmail, EmployeeType::EXPERIENCE), expInYear(expInYear), proSkill(proSkill) {}

    int Experience::getExpInYear() const
    {
        return expInYear;
    }

    std::string Experience::getProSkill() const
    {
        return proSkill;
    }

    void Experience::setExpInYear(int& exp) 
    {
        expInYear = exp;
    }

    void Experience::setProSkill(std::string& skill) 
    {
        proSkill = skill;
    }

    void Experience::showInfo()
    {
        std::cout << getID() <<" "<< getEName() <<" "<< getEBirthDay() <<" " << getEPhoneNum()<<" "<< getEEmail()<<" "<< getExpInYear()<<" "<<getProSkill()<<std::endl;
    }