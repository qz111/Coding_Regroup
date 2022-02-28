#include "Control/monitor.h"

int main(){
    {//test using required input
        monitor processing_regroup;
        processing_regroup.readFromJson("..\\src\\Data\\1_sample_in.json");
        processing_regroup.processRegroup(std::vector<std::string>{std::string("shape"),std::string("material")});
        processing_regroup.sendToJson("..\\src\\Data\\1_sample_out.json");
    }
    {//test reading hard coded string
        monitor processing_regroup;
        processing_regroup.readFromJson();
        processing_regroup.processRegroup(std::vector<std::string>{std::string("shape"),std::string("material")});
        processing_regroup.sendToJson("..\\src\\Data\\1_sample_out_str.json");
    }
    {//test using further extended regroup
        monitor processing_regroup;
        processing_regroup.readFromJson("..\\src\\Data\\1_sample_in.json");
        processing_regroup.processRegroup(std::vector<std::string>{std::string("color"),std::string("transparent")});
        processing_regroup.sendToJson("..\\src\\Data\\1_sample_out_ext.json");
    }
    {//test using regroup based on regrouped data
        monitor processing_regroup;
        processing_regroup.readFromJson("..\\src\\Data\\1_sample_in.json");
        processing_regroup.processRegroup(std::vector<std::string>{std::string("shape"),std::string("material")});
        processing_regroup.processRegroup(std::vector<std::string>{std::string("transparent")});
        processing_regroup.sendToJson("..\\src\\Data\\1_sample_out_multi.json");
    }
}