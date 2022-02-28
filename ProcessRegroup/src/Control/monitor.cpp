#include "monitor.h"

void monitor::readFromJson(const std::string filePath){
    ioFromJson::read(filePath,j_Tree_ori);
}
void monitor::readFromJson(){
    ioFromJson::read(j_Tree_ori);
}
void monitor::processRegroup(const std::vector<std::string>& group_by_type){
    if(umap.empty()){
        processing::getBody(j_Tree_ori,umap);
    }
    processing::regroup(group_by_type,umap);
    j_Tree_regroup=processing::groupToJson(umap);
}
void monitor::sendToJson(const std::string filePath){
    ioFromJson::write(filePath,j_Tree_regroup);
    std::cout<< std::setfill('\t') << j_Tree_regroup << '\n';
    
}
