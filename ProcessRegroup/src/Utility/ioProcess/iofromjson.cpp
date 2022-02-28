#include "iofromjson.h"

void ioFromJson::read(const std::string& filePath, nlohmann::json& j_Object){
    std::ifstream datafile(filePath,std::ios_base::in);
    if(!datafile){
        std::cout<<"can not read from "+filePath<<'\n';
        exit(1);
    }
    datafile>>j_Object;
}
void ioFromJson::read(nlohmann::json& j_Object){
    std::string text=R"({
	"name": "root",
	"type": "group",
	"children": [{
			"name": "Body1",
			"type": "body",
			"shape": "cube",
			"boundingSphere": 3,
			"material": "plastic",
			"color": "red",
			"transparent": false
		},{
			"name": "Body2",
			"type": "body",
			"shape": "cylinder",
			"boundingSphere": 52,
			"material": "wood",
			"color": "red",
			"transparent": false
		},{
			"name": "Body3",
			"type": "body",
			"shape": "sphere",
			"boundingSphere": 7,
			"material": "glass",
			"color": "yellow",
			"transparent": true
		},{
			"name": "Group2",
			"type": "group",
			"children": [{
				"name": "Body4",
				"type": "body",
				"shape": "cube",
				"boundingSphere": 11.9,
				"material": "plastic",
				"color": "green",
				"transparent": true
			},{
				"name": "Group3",
				"type": "group",
				"children": [{
					"name": "Body5",
					"type": "body",
					"shape": "cylinder",
					"boundingSphere": 6.75,
					"material": "wood",
					"color": "white",
					"transparent": false
				},{
					"name": "Body232",
					"type": "body",
					"shape": "cube",
					"boundingSphere": 47,
					"material": "plastic",
					"color": "white",
					"transparent": false
				}]
			}]
		}]
})";
    j_Object=nlohmann::json::parse(text);
}
void ioFromJson::write(const std::string& filePath, nlohmann::json& j_Object){
    std::ofstream datafile(filePath,std::ios_base::out);
    if(!datafile){
        std::cout<<"can not write to "+filePath<<'\n';
        exit(1);
    }
    datafile<<std::setw(1) << std::setfill('\t') <<j_Object;
}