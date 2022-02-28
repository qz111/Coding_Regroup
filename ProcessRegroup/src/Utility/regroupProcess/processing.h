#ifndef PROCESSING_H
#define PROCESSING_H
#include <string>
//#include "../../../../../nlohmann/json/single_include/nlohmann/json.hpp"
#include "../../Obj/body.h"
#include "../../json.hpp"
class processing{
    public:
    static void getBody(const nlohmann::json& j_Object, std::unordered_map<std::string,std::vector<body>>& umap);
    static void regroup(const std::vector<std::string>& type,std::unordered_map<std::string,std::vector<body>>& umap);
    static nlohmann::json groupToJson(const std::unordered_map<std::string,std::vector<body>>& umap);
};
#endif