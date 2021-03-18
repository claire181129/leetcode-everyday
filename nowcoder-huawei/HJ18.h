
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

bool valid_netMask(int mask[4])
{
    unsigned long temp = mask[0] & 0xFF;
    for (int i = 1; i <= 3; i++)
    {
        temp = temp << 8;
        temp = temp | (mask[i] & 0xFF);
    }
    //std::cout << std::hex << temp << std::endl;
    int count = 0;
    unsigned int check_mask = 0x80000000;
    while (check_mask & temp)
    {
        check_mask >>= 1;
        count += 1;
    }
    if (count == 0 || count == 32)
        return false;
    count = 32 - count;
    while (count > 0)
    {
        if (check_mask & temp)
            return false;
        check_mask >>= 1;
        count--;
    }
    return true;

}

int main(int argc, char* argv[])
{
    std::vector<std::string> input_list;
    std::string str;
    while (std::cin >> str)
    {
        if (!str.empty())
            input_list.push_back(str);
    }
    int A_address_count = 0, B_address_count = 0, C_address_count = 0, D_address_count = 0, E_address_count = 0, wrong_address_count = 0, private_address_count = 0;
    for (int i = 0; i < input_list.size(); i++)
    {
        std::string regex = "([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)~([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+).*";
        std::cmatch match;
        std::regex_match(input_list[i].data(), match, std::regex(regex, std::regex_constants::ECMAScript));
        if (match.size() == 9)
        {
            std::string ip = match.str(1) + " " + match.str(2) + " " + match.str(3) + " " + match.str(4) + " " + match.str(5) + " " + match.str(6) + " " + match.str(7) + " " + match.str(8);
            std::istringstream sstream(ip.data());
            int a[8];
            sstream >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7];
            if (valid_netMask(a + 4))
            {
                if (a[0]>=1 && a[0]<=126)//!(a[0] & 0x80)
                {
                     //std::cout << input_list[i] << " : A" << std::endl;
                     A_address_count++;
                    if (a[0] == 10)
                    {
                        //std::cout << input_list[i] << " :P1" << std::endl;
                        private_address_count++;
                    }
                }
                //else if ((a[0] & 0x80) && !(a[0] & 0x40))
                else if((a[0]>=128)&&(a[0]<=191))
                {
                    //std::cout << input_list[i] << " :B" << std::endl;
                    B_address_count++;
                    if ( (a[0] == 172) && (a[1] >= 16) && (a[1] <= 31))
                    {
                        //std::cout << input_list[i] << " :P2" << std::endl;
                        private_address_count++;
                    }
                }
                //else if ((a[0] & 0x80) && (a[0] & 0x40) && !(a[0] & 0x20))
                else if((a[0]>=192)&&(a[0]<=223))
                {
                    //std::cout << input_list[i] << " :C" << std::endl;
                    C_address_count++;
                    if ((a[0] == 192) &&( a[1] == 168))
                    {
                        //std::cout << input_list[i] << " :P3" << std::endl;
                        private_address_count++;
                    }
                }
                //else if ((a[0] & 0x80) && (a[0] & 0x40) && (a[0] & 0x20) && !(a[0] & 0x10))
                else if((a[0]>=224)&&(a[0]<=239))
                {
                    //std::cout << input_list[i] << " :D" << std::endl;
                    D_address_count++;
                }
                //else if ((a[0] & 0x80) && (a[0] & 0x40) && (a[0] & 0x20) && (a[0] & 0x10))
                else if((a[0]>=240)&&(a[0]<=255))
                {
                    //std::cout << input_list[i] << " :E" << std::endl;
                    E_address_count++;
                }
            }
            else
                wrong_address_count++;
        }
        else
                wrong_address_count++;
    }
    std::cout << A_address_count
        << " " << B_address_count
        << " " << C_address_count
        << " " << D_address_count
        << " " << E_address_count
        << " " << wrong_address_count
        << " " << private_address_count
        << std::endl;
    return 0;
}


