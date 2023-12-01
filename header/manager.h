#pragma once
#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"

class EmployeeManager
{
private:
    std::vector<std::shared_ptr<Employee>> employeesList;

public:
    void findEmployee(const int& id);

    void addEmployee(std::shared_ptr<Employee>& employee);

    void deleteEmployee(const int& id);

    void inputEmployeeInfo(EmployeeManager& qlnv, std::shared_ptr<Employee>& employee, const EmployeeType& type);

    // void editEmployee(const int& id, std::string& name, std::string& birthDay, std::string& phoneNum, std::string& email);

    void editEmployee(const int& id, const EmployeeType& type);

    void displayInfo();

    void findExperiences() const;

    void findFreshers() const;

    void findInterns() const;

};