#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <iostream>

class MyParserXml {
public:
    MyParserXml() {}
    MyParserXml(const std::string& filename) {
        LoadXml(filename);
    }
    ~MyParserXml() {}
    void LoadXml(const std::string& filename) {
        boost::property_tree::read_xml(filename.c_str(), tree);
    }
    void SaveXml(const std::string& filename) {}
private:
    boost::property_tree::ptree tree;
};

void ReadXml(const std::string& filename) {
    boost::property_tree::ptree tree;
    boost::property_tree::read_xml(filename.c_str(), tree);
    std::string name;
    std::cout << "tree size: " << tree.size() << std::endl;
    std::cout << "tree.chenyi size: " << tree.get_child("chenyi").size() << std::endl;
    std::cout << tree.get_child("chenyi").get<std::string>("name", "hh") << std::endl;
    std::cout << tree.get_child("chenyi").get<std::string>("name", "hh") << std::endl;
    /*
<chenyi>
    <name>chenyi</name>
    <name>py</name>
    <age>21</age>
    <gender>male</gender>
</chenyi>
    
    */
    // for (boost::property_tree::ptree::value_type& child_value : tree.get_child("chenyi")) {
    //     name = child_value.second.get<std::string>("name", "hh");
    //     std::cout << child_value.first << std::endl;
    //     std::cout << child_value.second.data() << std::endl;
    // }

    // name = tree.get<std::string>("chenyi.name", "hh");
    std::cout << name << std::endl;
}


void WriteXml(const std::string& filename) {
    // boost::property_tree::ptree tree;
    // tree.put("chenyi", 1);
    // boost::property_tree::ptree tree1;
    // tree1.put_child("filename", tree);

    boost::property_tree::ptree tree1;
    tree1.put("filename.chenyi", 1);
    boost::property_tree::write_xml(filename, tree1);
}


/*
    vector<int> v;
    int a = v;    error
    for (int a : v) {    success

    }
*/

int main() {
    ReadXml("parser.xml");
    WriteXml("write.xml");

    return 0;
}