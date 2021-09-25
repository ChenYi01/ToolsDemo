#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>
/*
解析json方法与解析xml方法一致，详细demo可以参考xml解析
*/
void ReadJson(const std::string& filename) {
    boost::property_tree::ptree tree;
    boost::property_tree::read_json(filename, tree);
    std::string name = tree.get<std::string>("chenyi.gender");

    std::cout << name << std::endl;
}

void WriteJson(const std::string& filename) {
    boost::property_tree::ptree tree;

    tree.put("chenyi.filename", "chenyi");
    boost::property_tree::write_json(filename, tree);
}

void test01() {
    ReadJson("parser.json");
    WriteJson("write.json");
}

int main() {
    test01();

    return 0;
}