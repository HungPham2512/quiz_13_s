#pragma once   
#include "employee.h"

class Intern : public Employee
{
private:
    std::string major;
    std::string semester;
    std::string uniName;

public:
    Intern(int id, std::string eName, std::string eBirthDay, std::string ePhoneNum, std::string eEmail, std::string major,std::string semester, std::string uniName);
    std::string getMajor() const;

    std::string getSemester() const;

    std::string getUniName() const;

    void setMajor(std::string& maj);

    void setSemester(std::string& sem);

    void setUniName(std::string& uni);

    void showInfo() override;

};