#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Certificate
{
private:
    int cerID;
    std::string cerName;
    std::string cerRank;
    std::string cerDate;

public:
    Certificate(int cerID, std::string cerName, std::string cerRank, std::string cerDate);
};