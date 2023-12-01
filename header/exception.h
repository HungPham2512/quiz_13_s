#pragma once
#include <iostream>
#include <string>
#include <regex>

class Exception 
{
private:
    static bool isValidName(std::string& name);

    static bool isValidBirthDayFormat( std::string& birthDay);

    static bool isValidPhoneNumber( std::string& phone);

    static bool isValidEmailFormat( std::string& email);

public:
    static void nameException(std::string& name);

    static void birthdayException(std::string& birthDay);

    static void phoneException(std::string& phone);

    static void mailException(std::string& email);

};