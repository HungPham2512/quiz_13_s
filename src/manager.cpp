#include "../header/manager.h"
#include "../header/exception.h"

    void EmployeeManager::findEmployee(const int& id)
    {
        auto it = std::find_if(employeesList.begin(), employeesList.end(),[id](std::shared_ptr<Employee> emp) -> bool
        {
            return emp->getID() == id;
        });

        if(it != employeesList.end())
        {
            std::cout<<"Employee found"<<std::endl;
            (*it)->showInfo();
        } else {
            std::cout<<"Employee not found"<<std::endl;
        }
    }

    void EmployeeManager::addEmployee(std::shared_ptr<Employee>& employee) 
    {
        auto it = std::find_if(employeesList.begin(), employeesList.end(), [employee](std::shared_ptr<Employee> emp) -> bool 
        {
            return emp->getID() == employee->getID();
        });

        if (it != employeesList.end()) 
        {
            
            *it = employee;
            std::cout << "Employee with ID " << employee->getID() << " updated" << std::endl;
        } else {
            // Add new employee if ID doesn't exist
            employeesList.push_back(employee);
            std::cout << "Employee with ID " << employee->getID() << " added" << std::endl;
        }
    }


    void EmployeeManager::deleteEmployee(const int& id)
    {
        auto it = std::find_if(employeesList.begin(), employeesList.end(),[id](std::shared_ptr<Employee> emp) -> bool
        {
            return emp->getID() == id;
        });

        if(it != employeesList.end())
        {
            std::cout<<"Employee"<< (*it)->getID() <<" has been deleted"<<std::endl;
            employeesList.erase(it);
        } else {
            std::cout<<"Employee not found"<<std::endl;
        }
    }

    void EmployeeManager::inputEmployeeInfo(EmployeeManager& employeeManager, std::shared_ptr<Employee>& employee, const EmployeeType& type)
    {
        int id;
        std::string name, birthDay, phoneNum, email;

        std::cout << "Enter employee ID: ";
        std::cin >> id;
        std::cin.ignore(); // Clear newline character 

        std::cout << "Enter employee name: ";
        std::getline(std::cin, name);
        Exception::nameException(name);

        std::cout << "Enter employee birth date (dd/mm/yyyy): ";
        std::getline(std::cin, birthDay);
        Exception::birthdayException(birthDay);

        std::cout << "Enter employee phone number: ";
        std::getline(std::cin, phoneNum);
        Exception::phoneException(phoneNum);

        std::cout << "Enter employee email: ";
        std::getline(std::cin, email);
        Exception::mailException(email);

        if (type == EmployeeType::EXPERIENCE) {
            int expInYear;
            std::string proSkill;

            std::cout << "Enter experience in years: ";
            std::cin >> expInYear;
            std::cin.ignore(); // Clear newline character 

            std::cout << "Enter professional skill: ";
            std::getline(std::cin, proSkill);

            employee = std::make_shared<Experience>(id, name, birthDay, phoneNum, email, expInYear, proSkill);
        } else if (type == EmployeeType::FRESHER) {
            std::string gradDate, gradRank, gradSchool;

            std::cout << "Enter graduation date: ";
            std::getline(std::cin, gradDate);

            std::cout << "Enter graduation rank: ";
            std::getline(std::cin, gradRank);

            std::cout << "Enter graduation school: ";
            std::getline(std::cin, gradSchool);

            employee = std::make_shared<Fresher>(id, name, birthDay, phoneNum, email, gradDate, gradRank, gradSchool);
        } else if (type == EmployeeType::INTERN) {
            std::string major, semester, uniName;

            std::cout << "Enter major: ";
            std::getline(std::cin, major);

            std::cout << "Enter semester: ";
            std::getline(std::cin, semester);

            std::cout << "Enter university name: ";
            std::getline(std::cin, uniName);

            employee = std::make_shared<Intern>(id, name, birthDay, phoneNum, email, major, semester, uniName);
        }

        if (employee) {
            employeeManager.addEmployee(employee);
        }
    }

    // void EmployeeManager::editEmployee(const int& id, std::string& name, std::string& birthDay, std::string& phoneNum, std::string& email)
    // {
    //     auto it = std::find_if(employeesList.begin(), employeesList.end(),[id](std::shared_ptr<Employee> emp) -> bool
    //     {
    //         return emp->getID() == id;
    //     });

    //     if(it != employeesList.end())
    //     {
    //         std::cout<<"Make change to employee"<<std::endl;
    //         (*it)->setEName(name);
    //         (*it)->setEBirthDay(birthDay);
    //         (*it)->setEPhoneNum(phoneNum);
    //         (*it)->setEEmail(email);
    //     } else {
    //         std::cout<<"Employee not found"<<std::endl;
    //     }
    // }

    void EmployeeManager::editEmployee(const int& id, const EmployeeType& type)
    {
        bool employeeFound = false;
        for(auto& employee : employeesList) 
        {
            if(employee->getID() == id && employee->getEType() == type)
            {
                employeeFound = true;
                if(type == EmployeeType::EXPERIENCE)
                {
                    auto exp = std::dynamic_pointer_cast<Experience>(employee);
                    if(exp)
                    {
                        std::string name, birthDay, phoneNum, email, proSkill;
                        int expInYear;
                        std::cout << "Insert edited Experience info" << std::endl;

                        std::cout << "Enter new name: ";
                        std::getline(std::cin, name);
                        Exception::nameException(name);

                        std::cout << "Enter new birthDay: ";
                        std::getline(std::cin, birthDay);
                        Exception::birthdayException(birthDay);

                        std::cout << "Enter new phoneNum: ";
                        std::getline(std::cin, phoneNum);
                        Exception::phoneException(phoneNum);

                        std::cout << "Enter new email: ";
                        std::getline(std::cin, email);
                        Exception::mailException(email);
                        std::cout<<"Enter new proSkill: ";
                        std::getline(std::cin, proSkill);
                        std::cout<<"Enter new expInYear: ";
                        std::cin>>expInYear;

                        exp->setEName(name);
                        exp->setEBirthDay(birthDay);
                        exp->setEPhoneNum(phoneNum);
                        exp->setEEmail(email);
                        exp->setExpInYear(expInYear);
                        exp->setProSkill(proSkill);
                        std::cout << "Experience Employee edited" << std::endl;

                    }
                }
                else if(type == EmployeeType::FRESHER)
                {
                    auto fresher = std::dynamic_pointer_cast<Fresher>(employee);
                    if(fresher)
                    {
                        std::string name, birthDay, phoneNum, email, gradDate, gradRank, gradSchool;
                        std::cout<<"Insert edited Fresher info"<<std::endl;

                        std::cout << "Enter new name: ";
                        std::getline(std::cin, name);
                        Exception::nameException(name);

                        std::cout << "Enter new birthDay: ";
                        std::getline(std::cin, birthDay);
                        Exception::birthdayException(birthDay);

                        std::cout << "Enter new phoneNum: ";
                        std::getline(std::cin, phoneNum);
                        Exception::phoneException(phoneNum);

                        std::cout << "Enter new email: ";
                        std::getline(std::cin, email);
                        Exception::mailException(email);

                        std::cout<<"Enter new gradDate: ";
                        std::getline(std::cin, gradDate);

                        std::cout<<"Enter new gradRank: ";
                        std::getline(std::cin, gradRank);

                        std::cout<<"Enter new gradSchool: ";
                        std::getline(std::cin, gradSchool);

                        fresher->setEName(name);
                        fresher->setEBirthDay(birthDay);
                        fresher->setEPhoneNum(phoneNum);
                        fresher->setEEmail(email);
                        fresher->setGradDate(gradDate);
                        fresher->setGradRank(gradRank);
                        fresher->setGradSchool(gradSchool);
                        std::cout << "Fresher Employee edited" << std::endl;

                    }                    
                }
                else if(type == EmployeeType::INTERN)
                {
                    auto intern = std::dynamic_pointer_cast<Intern>(employee);
                    if(intern)
                    {
                        std::string name, birthDay, phoneNum, email, major, semester, uni;
                        std::cout<<"Insert edited Fresher info"<<std::endl;

                        std::cout << "Enter new name: ";
                        std::getline(std::cin, name);
                        Exception::nameException(name);

                        std::cout << "Enter new birthDay: ";
                        std::getline(std::cin, birthDay);
                        Exception::birthdayException(birthDay);

                        std::cout << "Enter new phoneNum: ";
                        std::getline(std::cin, phoneNum);
                        Exception::phoneException(phoneNum);

                        std::cout << "Enter new email: ";
                        std::getline(std::cin, email);
                        Exception::mailException(email);

                        std::cout<<"Enter new major: ";
                        std::getline(std::cin, major);

                        std::cout<<"Enter new semester: ";
                        std::getline(std::cin, semester);

                        std::cout<<"Enter new uni: ";
                        std::getline(std::cin, uni);

                        intern->setEName(name);
                        intern->setEBirthDay(birthDay);
                        intern->setEPhoneNum(phoneNum);
                        intern->setEEmail(email);
                        intern->setMajor(major);
                        intern->setSemester(semester);
                        intern->setUniName(uni);
                        std::cout << "Intern Employee edited" << std::endl;

                    }                    
                }                
            }
        }
        if(!employeeFound) 
        {
            std::cout << "Employee not matched" << std::endl;
        }
    }

    void EmployeeManager::displayInfo()
    {
        for (std::shared_ptr<Employee> employee : employeesList)
        {
            employee->showInfo();
        }
    }

    void EmployeeManager::findExperiences() const
    {
        std::cout << "List of Experience Employees:" << std::endl;
        for (const auto& employee : employeesList) 
        {
            if (employee->getEType() == EmployeeType::EXPERIENCE) 
            { 
                employee->showInfo();
            }
        }
    }

    void EmployeeManager::findFreshers() const
    {
        std::cout << "List of Fresher Employees:" << std::endl;
        for (const auto& employee : employeesList) 
        {
            if (employee->getEType() == EmployeeType::FRESHER) 
            { 
                employee->showInfo();
            }
        }
    }

    void EmployeeManager::findInterns() const
    {
        std::cout << "List of Intern Employees:" << std::endl;
        for (const auto& employee : employeesList) 
        {
            if (employee->getEType() == EmployeeType::INTERN) 
            { 
                employee->showInfo();
            }
        }
    }