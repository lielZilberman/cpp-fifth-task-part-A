#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel
{
    class OrgChart
    {
        public: 
        struct node
        {
            vector<string> sub;
            string data;
            node *next;
        };
        class Iterator
        {
            public:
            node *current;
            unsigned int i;
            Iterator()
            {
                this->current = NULL;
                this->i = 1;
            }
            const Iterator &operator++() const
            {
                return *this;
            }
            Iterator operator++(int)
            {
                return *this;
            }
            bool operator!=(const Iterator &cur){
                return false;
            }
            string *operator->() const
            {
                string *h = NULL;
                return h;
            }
            string operator*() const
            {
                return "";
            }
        };
        Iterator end();
        Iterator begin();
        Iterator begin_preorder();
        Iterator end_preorder();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator end_level_order();
        Iterator begin_level_order();
        OrgChart();
        OrgChart& add_sub(string Superior, string Inferior);
        OrgChart& add_root(string boss);
        friend ostream& operator<<(ostream& myOutput, const OrgChart &myOrgChart);
    };
}