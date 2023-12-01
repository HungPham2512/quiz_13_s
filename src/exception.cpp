#include "../header/exception.h"

    bool Exception::isValidName( std::string& name) {
        return std::regex_match(name, std::regex("[A-Za-z ]+"));
    }

    bool Exception::isValidBirthDayFormat( std::string& birthDay) {
        return std::regex_match(birthDay, std::regex(R"(\d{2}/\d{2}/\d{4})"));
    }

    bool Exception::isValidPhoneNumber( std::string& phone) {
        return std::all_of(phone.begin(), phone.end(), ::isdigit);
    }

    bool Exception::isValidEmailFormat( std::string& email) {
        return std::regex_match(email, std::regex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)"));
    }

    void Exception::nameException(std::string& name) {
    bool isValid = isValidName(name);
    if(!isValid){std::cout << "Exception occurred: Invalid Name Exception" << std::endl;}
    while(!isValid) {
    try {
            std::cout << "Enter a valid name: ";
            std::getline(std::cin, name);
            if (!isValidName(name)) {
                throw "Invalid Name Exception";
            }
            else {isValid = true;}
        } catch (const char* msg) {
            std::cout << "Exception occurred: " << msg << std::endl;
            std::cout << "Please try again." << std::endl;
        }
    }
    }

    void Exception::birthdayException(std::string& birthDay) {
    bool isValid = isValidBirthDayFormat(birthDay);
    if(!isValid){std::cout << "Exception occurred: Invalid BirthDay Exception" << std::endl;}
    while(!isValid) {
    try {
            std::cout << "Enter a valid birthDay: ";
            std::getline(std::cin, birthDay);
            if (!isValidBirthDayFormat(birthDay)) {
                throw "Invalid BirthDay Exception";
            }
            else {isValid = true;}
        } catch (const char* msg) {
            std::cout << "Exception occurred: " << msg << std::endl;
            std::cout << "Please try again." << std::endl;
        }
    }
    }

    void Exception::phoneException(std::string& phone) {
    bool isValid = isValidPhoneNumber(phone);
    if(!isValid){std::cout << "Exception occurred: Invalid Phone number Exception" << std::endl;}
    while(!isValid) {
    try {
            std::cout << "Enter a valid Phone number: ";
            std::getline(std::cin, phone);
            if (!isValidPhoneNumber(phone)) {
                throw "Invalid Phone number Exception";
            }
            else {isValid = true;}
        } catch (const char* msg) {
            std::cout << "Exception occurred: " << msg << std::endl;
            std::cout << "Please try again." << std::endl;
        }
    }
    }

    void Exception::mailException(std::string& email) {
    bool isValid = isValidEmailFormat(email);
    if(!isValid){std::cout << "Exception occurred: Invalid Email Exception" << std::endl;}
    while(!isValid) {
    try {
            std::cout << "Enter a valid Email: ";
            std::getline(std::cin, email);
            if (!isValidEmailFormat(email)) {
                throw "Invalid Email Exception";
            }
            else {isValid = true;}
        } catch (const char* msg) {
            std::cout << "Exception occurred: " << msg << std::endl;
            std::cout << "Please try again." << std::endl;
        }
    }
    }


