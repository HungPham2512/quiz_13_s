#pragma once
#include <iostream>
#include <string>
#include <regex>

class Exception 
{
private:
    static bool isValidName(const std::string& name);

    static bool isValidBirthDayFormat(const std::string& birthDay);

    static bool isValidPhoneNumber(const std::string& phone);

    static bool isValidEmailFormat(const std::string& email);

public:
    static void nameException(const std::string& name);

    static void birthdayException(const std::string& birthDay);

    static void phoneException(const std::string& phone);

    static void mailException(const std::string& email);

};