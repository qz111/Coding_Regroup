#include "../Utility/ioProcess/iofromjson.h"
#include "../Utility/regroupProcess/processing.h"

class monitor{
    private:
    nlohmann::ordered_json j_Tree_ori;
    std::unordered_map<std::string,std::vector<body>> umap;
    nlohmann::ordered_json j_Tree_regroup;
    public:
    void readFromJson(const std::string filePath);
    void readFromJson();
    void processRegroup(const std::vector<std::string>& group_by_type);
    void sendToJson(const std::string filePath);
};