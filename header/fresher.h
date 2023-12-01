#pragma once
#include "employee.h"

class Fresher : public Employee
{
private:
    std::string gradDate;
    std::string gradRank;
    std::string gradSchool;

public:
    Fresher(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, std::string gradDate,std::string gradRank, std::string gradSchool);

    std::string getGradDate() const;

    std::string getGradRank() const;

    std::string getGradSchool() const;

    void setGradDate(std::string date);

    void setGradRank(std::string rank);

    void setGradSchool(std::string school);

    void showInfo() override;
};