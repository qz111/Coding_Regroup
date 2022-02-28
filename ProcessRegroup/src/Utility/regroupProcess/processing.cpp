#include "processing.h"

void processing::getBody(const nlohmann::json& j_Object, std::unordered_map<std::string,std::vector<body>>& umap){
    for(auto& obj:j_Object["children"]){
        if(obj.count("children")==0){
            umap[std::string(obj["name"])].push_back(body(obj));
        }
        else{
            getBody(obj,umap);
        }
    }
}
void processing::regroup(const std::vector<std::string>& type,std::unordered_map<std::string,std::vector<body>>& umap){
    size_t n=type.size();
    std::unordered_map<std::string,std::vector<body>> umap_tmp;
    for(auto i:umap){
        for(auto j:i.second){
            std::string new_name;
            for(int m=0;m<n;m++){   
                new_name+=std::string(j[type[m]])+" ";   
            }
            if(i.first[0]=='g'){
                umap_tmp[i.first+new_name].push_back(j);
            }
            else{
                umap_tmp["group "+new_name].push_back(j);
            }
        }
    }
    umap=umap_tmp;
}
nlohmann::json processing::groupToJson(const std::unordered_map<std::string,std::vector<body>>& umap){
    nlohmann::json result;
    result["name"]="root";
    result["type"]="group";
    for(auto i:umap){
        nlohmann::json group;
        group["name"]=i.first;
        group["type"]="group";
        for(auto j:i.second){
            nlohmann::json j_Object;
            j.toJson(j_Object);
            group["children"]+=j_Object;
        }
        result["children"]+=group;
    }
    return result;
}