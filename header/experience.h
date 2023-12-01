#pragma once
#include "employee.h"

class Experience : public Employee
{
private:
    int expInYear;
    std::string proSkill;

public:
    Experience(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, int expInYear,std::string proSkill);

    int getExpInYear() const;

    std::string getProSkill() const;

    void setExpInYear(int& exp);

    void setProSkill(std::string& skill);

    void showInfo() override;
};