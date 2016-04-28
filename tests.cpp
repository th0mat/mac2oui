// MacLookup -  v0.2

#include <iostream>
#include <vector>
#include "mac2oui.h"


std::vector<std::pair<std::string, std::string>> t1Targets = {
        {"00:1e:65:cb:82:10",    "IntelCor_8210"},
        {"00:1f:5b:b9:65:d5",    "NIM_Mac"},
        {"00:24:d7:80:8a:dc",    "IntelCor_8ADC"},
        {"00:26:bb:d9:1c:63",    "Apple_1C63"},
        {"00:26:bb:d9:1c:63",    "Apple_1C63"},
        {"00:d0:00:01:7c:11",    "FerranSc_7C11"},
        {"04:0c:ce:dd:e9:f2",    "TOM_Air"},
        {"ff:ff:ff:ff:ff:ff",    "Broadcast"},
        {"ff:ff:ff:ff:ff:ff",    "Broadcast"},
        {"ff:CD:ee:99:99:99",    "[FFCDEE999999]"},
        {"gg:ff:ff:ff:ff:ff",    "invalid"},
        {"ab:cd:ff:ff:ff",       "invalid"},
        {"ab:cd:ff:ff:ff:aa:bb", "invalid"},
        {"not_a_mac",            "invalid"}
};


std::vector<std::pair<u_int64_t, std::string>> t2Targets = {

        {893353294865,      "FerranSc_7C11"},
        {4453056768498,     "TOM_Air"},
        {4453056768498,     "TOM_Air"},
        {48358720412822203, "invalid"},
        {281259936422297,   "[FFCDEE999999]"}
};





void t_lookupByString() {
    //MacLookup& manuf = MacLookup::getMacLookup();
    std::cout << "\nTEST - Lookup by std::string\n\n";
    std::string s, result;
    for (auto itr = t1Targets.begin(); itr != t1Targets.end(); itr++) {
        s = itr->first;
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        result = resolveMac(s);
        printf("%-22s  found: %-21s should be: %-25s  %s\n", s.c_str(), result.c_str(), itr->second.c_str(),
               result == itr->second ? "correct" : "wrong");
    }
}

void t_lookupByLong() {
    MacLookup& manuf = MacLookup::getMacLookup();
    std::cout << "\n\nTEST - Lookup by u_int64_t\n\n";
    std::string result;
    for (auto itr = t2Targets.begin(); itr != t2Targets.end(); itr++) {
        result = resolveMac(itr->first);
        printf("%-22lld  found: %-21s should be: %-25s  %s\n", itr->first, result.c_str(), itr->second.c_str(),
               result == itr->second ? "correct" : "wrong");
    }
}


// input in network byte order
void t_lookupByChar() {


    u_char a[] = {0x00, 0x1e, 0x65, 0xcb, 0x82, 0x10};
    u_char b[] = {0x00, 0xd0, 0x00, 0x01, 0x7c, 0x11};

    struct TestData {std::string oui; std::string desc; u_char* mac;};

    std::vector<TestData> t3;
    t3.push_back(TestData{"IntelCor_8210", "0x00, 0x1e, 0x65, 0xcb, 0x82, 0x10", &a[0]});
    t3.push_back(TestData{"IntelCor_8210", "0x00, 0x1e, 0x65, 0xcb, 0x82, 0x10", &a[0]});
    t3.push_back(TestData{"FerranSc_7C11", "0x00, 0xd0, 0x00, 0x01, 0x7c, 0x11", &b[0]});
    t3.push_back(TestData{"IntelCor_8210", "0x00, 0x1e, 0x65, 0xcb, 0x82, 0x10", &a[0]});

    MacLookup& manuf = MacLookup::getMacLookup();

    std::cout << "\n\nTEST - Lookup by char (in network byte order)\n\n";


    for (int i = 0; i < t3.size(); i++) {
        std::string result = resolveMac(t3[i].mac);
        printf("%-35s  found: %-17s should be: %-16s  %s\n", t3[i].desc.c_str(), result.c_str(), t3[i].oui.c_str(),
               result == t3[i].oui ? "correct" : "wrong");
    }
}


void runTests() {
    t_lookupByString();
    t_lookupByLong();
    t_lookupByChar();
}


int main() {
    runTests();
    return 0;
}
