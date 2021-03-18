/*
lsjmkwoqijggmybr 645
rzuwnjvnuz 633
atl 637
rwyfvzsopsuiqjnr 647
eez 648
fmwafhhgeyawnool 649
c 637
f 633
ywzqaop 631
ywzqaop 631
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
struct Record {
    std::string name;
    unsigned int line;
    unsigned int count = 1;
/*
    bool operator==(Record r) {
        if (r.name == name && r.line == line)
            return true;
        else
            return false;
    }*/
};
int main()
{
    std::vector<std::string> input_list;
    //std::string str;
    char str[1024];
    while (std::cin.getline(str,1024))
    {
        input_list.push_back(std::string(str));
        //std::cout << std::string(str) << std::endl;
    }
    std::vector<Record> records;
    for (int i = 0; i < input_list.size(); i++)
    {
        std::string name;
        unsigned int line;
        std::istringstream sstream(input_list[i]);
        sstream >> name >> line;
        size_t begin = name.find_last_of("\\");
        if(begin <name.size()-1)
            name = name.substr(begin + 1);
        if (name.size() > 16)
            name = name.substr(name.size()-16);
        Record record;
        record.name = name;
        record.line = line;
        bool find_it = false;
        for (auto& it : records)
        {
            if ((record.name == it.name) &&(record.line == it.line))
            {
                it.count++;
                find_it = true;
            }
        }
        if (find_it == false)
            records.push_back(record);
        /*
            if (records.size() == 8)
            {
                //records.erase(records.begin());
                std::vector<Record> temp(7);
                std::copy(records.begin() + 1, records.end(), temp.begin());
                records = temp;
                records.shrink_to_fit();
                records.push_back(record);
                //std::cout << record.name << std::endl;
            }
            else if (records.size() < 8)
            {
                records.push_back(record);
                
            }
        */
    }
    //std::cout << "result:" << std::endl;
    if (records.size() < 8)
        for (auto it : records)
            std::cout << it.name << " " << it.line << " " << it.count << std::endl;
    else
    {
        for (int i = records.size() - 8; i < records.size(); i++)
            std::cout << records[i].name << " " << records[i].line << " " << records[i].count << std::endl;
    }
    return 0;
}