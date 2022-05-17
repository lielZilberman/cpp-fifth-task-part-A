#include "OrgChart.hpp"
#include "doctest.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("Should be working")
{
    OrgChart myOrg;
    myOrg.add_root("Boss");
    myOrg.add_sub("Boss", "Eng");
    myOrg.add_sub("Boss", "Frd");
    myOrg.add_sub("Boss", "Gg");
    myOrg.add_sub("Eng", "Jon");
    myOrg.add_sub("Gg", "Prf");

    vector<string> vec = {"Boss", "Eng", "Frd", "Gg", "Jon", "Prf"};
    vector<string> testy;
    for (auto it = myOrg.begin_level_order(); it != myOrg.end_level_order(); ++it)
    {
        testy.push_back(*it);
    }
    CHECK(testy.at(0) == vec.at(0));
    CHECK(testy.at(1) == vec.at(1));
    CHECK(testy.at(2) == vec.at(2));
    CHECK(testy.at(3) == vec.at(3));
    CHECK(testy.at(4) == vec.at(4));
    
    vector<string> vec2 = {"Jon", "Prf", "Eng", "Frd", "Gg", "Boss"};
    vector<string> testy2;
    for (auto it = myOrg.begin_reverse_order(); it != myOrg.reverse_order(); ++it)
    {
        testy2.push_back(*it);
    }
    CHECK(testy2.at(0) == vec2.at(0));
    CHECK(testy2.at(1) == vec2.at(1));
    CHECK(testy2.at(2) == vec2.at(2));
    CHECK(testy2.at(3) == vec2.at(3));
    CHECK(testy2.at(4) == vec2.at(4));

    vector<string> vec3 = {"Boss", "Eng", "Jon", "Frd", "Gg", "Prf"};
    vector<string> testy3;
    for (auto it = myOrg.begin_preorder(); it != myOrg.end_preorder(); ++it)
    {
        testy3.push_back(*it);
    }
    CHECK(testy3.at(0) == vec3.at(0));
    CHECK(testy3.at(1) == vec3.at(1));
    CHECK(testy3.at(2) == vec3.at(2));
    CHECK(testy3.at(3) == vec3.at(3));
    CHECK(testy3.at(4) == vec3.at(4));

    vector<string> testy4;
    for (auto element : myOrg)
    {
        testy4.push_back(element);
    }
    CHECK(testy4.at(0) == vec.at(0));
    CHECK(testy4.at(1) == vec.at(1));
    CHECK(testy4.at(2) == vec.at(2));
    CHECK(testy4.at(3) == vec.at(3));
    CHECK(testy4.at(4) == vec.at(4));
}

TEST_CASE("Should not be working"){
    OrgChart myOrg;
    CHECK_THROWS(myOrg.add_sub("gg", "ee"));
    myOrg.add_root("YY");
    CHECK_THROWS(myOrg.add_sub("yy", "gg"));
}