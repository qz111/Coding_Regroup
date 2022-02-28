#ifndef READFROMJSON_H
#define READFROMJSON_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../../json.hpp"

class ioFromJson{
    public:
    static void read(const std::string& filePath, nlohmann::json& j_Object);
    static void read(nlohmann::json& j_Object);
    static void write(const std::string& filePath, nlohmann::json& j_Object);
};
#endif
