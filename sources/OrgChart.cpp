#include "OrgChart.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;
OrgChart::Iterator i;

OrgChart::OrgChart() {}

OrgChart::Iterator OrgChart::end()
{
    return i;
}

OrgChart::Iterator OrgChart::end_preorder()
{
    return i;
}

OrgChart::Iterator OrgChart::begin()
{
    return i;
}

OrgChart::Iterator OrgChart::reverse_order()
{
    return i;
}

OrgChart::Iterator OrgChart::begin_reverse_order()
{
    return i;
}

OrgChart::Iterator OrgChart::end_level_order()
{
    return i;
}

OrgChart::Iterator OrgChart::begin_level_order()
{
    return i;
}

OrgChart::Iterator OrgChart::begin_preorder()
{
    return i;
}

OrgChart &OrgChart::add_root(string boss)
{
    return *this;
}

OrgChart &OrgChart::add_sub(string Superior, string Inferior)
{
    return *this;
}

ostream &ariel::operator<<(ostream &myOutput, const OrgChart &myOrgChart)
{
    return myOutput;
}
