#ifndef PROCESSING_H
#define PROCESSING_H
#include <string>
#include "../../Obj/body.h"
#include "../../json.hpp"
class processing{
    public:
    static void getBody(const nlohmann::ordered_json& j_Object, std::unordered_map<std::string,std::vector<body>>& umap);
    static void regroup(const std::vector<std::string>& type,std::unordered_map<std::string,std::vector<body>>& umap);
    static nlohmann::ordered_json groupToJson(const std::unordered_map<std::string,std::vector<body>>& umap);
};
#endif
