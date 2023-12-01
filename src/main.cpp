#include "../header/employee.h"
#include "../header/experience.h"
#include "../header/fresher.h"
#include "../header/intern.h"
#include "../header/manager.h"
#include "../header/certificate.h"
#include "../header/exception.h"
#include "../header/employeeType.h"

int main()
{
    EmployeeManager employeeManager;
    
    while (true)
    {
        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Edit Employee\n";
        std::cout << "3. Delete Employee\n";
        std::cout << "4. Display All Employees\n";
        std::cout << "5. Find Experiences\n";
        std::cout << "6. Find Freshers\n";
        std::cout << "7. Find Interns\n";
        std::cout << "8. Find Employee by ID\n";
        std::cout << "9. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character 

        switch (choice)
        {
        case 1:
        {
            std::cout << "Employee type: EXPERIENCE/FRESHER/INTERN? ";
            std::string employeeTypeStr;
            std::getline(std::cin, employeeTypeStr);

            if (employeeTypeStr == "EXPERIENCE" || employeeTypeStr == "FRESHER" || employeeTypeStr == "INTERN")
            {
                EmployeeType type;
                if (employeeTypeStr == "EXPERIENCE")
                    type = EmployeeType::EXPERIENCE;
                else if (employeeTypeStr == "FRESHER")
                    type = EmployeeType::FRESHER;
                else
                    type = EmployeeType::INTERN;

                // Input employee info
                std::shared_ptr<Employee> employee;
                employeeManager.inputEmployeeInfo(employeeManager, employee, type);
                // if (employee)
                // {
                //     qlnv.addEmployee(employee);
                // }
            }
            else
            {
                std::cout << "Invalid employee type." << std::endl;
            }
            break;
        }

        case 2:
        {
            int employeeID;
            std::cout << "Enter the ID of the employee to edit: ";
            std::cin >> employeeID;
            std::cin.ignore(); // Clear newline character 

            std::cout << "Employee type to edit: EXPERIENCE/FRESHER/INTERN? ";
            std::string employeeTypeStr;
            std::getline(std::cin, employeeTypeStr);

            if (employeeTypeStr == "EXPERIENCE" || employeeTypeStr == "FRESHER" || employeeTypeStr == "INTERN")
            {
                EmployeeType type;
                if (employeeTypeStr == "EXPERIENCE")
                    type = EmployeeType::EXPERIENCE;
                else if (employeeTypeStr == "FRESHER")
                    type = EmployeeType::FRESHER;
                else
                    type = EmployeeType::INTERN;

                employeeManager.editEmployee(employeeID, type);
            }
            else
            {
                std::cout << "Invalid employee type." << std::endl;
            }
            break;
        }

        case 3:
        {
            int employeeID;
            std::cout << "Enter the ID of the employee to delete: ";
            std::cin >> employeeID;
            std::cin.ignore(); // Clear newline character 

            employeeManager.deleteEmployee(employeeID);
            break;
        }

        case 4:
        {
            employeeManager.displayInfo();
            break;
        }

        case 5:
        {
            employeeManager.findExperiences();
            break;
        }

        case 6:
        {
            employeeManager.findFreshers();
            break;
        }

        case 7:
        {
            employeeManager.findInterns();
            break;
        }

        case 8:
        {
            int employeeID;
            std::cout << "Enter the ID of the employee to find: ";
            std::cin >> employeeID;
            std::cin.ignore(); // Clear newline character 

            employeeManager.findEmployee(employeeID);
            break;
        }


        case 9:
            return 0;
            
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    }
    return 0;
}