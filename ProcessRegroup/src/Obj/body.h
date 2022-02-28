#ifndef BODY_H
#define BODY_H
#include <string>
#include "../json.hpp"
class body{
    private:
    std::string name;
    std::string type;
    std::string shape;
    double boundingSphere;
    std::string material;
    std::string color;
    bool transparent;
    public:
    body():type("body"){}
    body(const nlohmann::ordered_json& j_Object){
        name=j_Object["name"];
        type=j_Object["type"];
        shape=j_Object["shape"];
        boundingSphere=j_Object["boundingSphere"];
        material=j_Object["material"];
        color=j_Object["color"];
        transparent=j_Object["transparent"];
    }
    std::string operator[](const std::string attribute) const{
        if(attribute=="name")return name;
        else if(attribute=="type")return type;
        else if(attribute=="shape")return shape;
        else if(attribute=="boundingSphere")return std::to_string(boundingSphere);
        else if(attribute=="material")return material;
        else if(attribute=="color")return color;
        else if(attribute=="transparent")return transparent?"true":"false";
        return "";
    }
    void toJson(nlohmann::ordered_json& j_Object){
        j_Object["name"]=name;
        j_Object["type"]=type;
        j_Object["shape"]=shape;
        j_Object["boundingSphere"]=boundingSphere;
        j_Object["material"]=material;
        j_Object["color"]=color;
        j_Object["transparent"]=transparent;
    }
};
#endif
