#ifndef UNTITLED4_CONTROLLER_H
#define UNTITLED4_CONTROLLER_H
#include <iostream>
using namespace std;
#include "Repository.h"
using repo::Repository;
#include <memory>

namespace controller{
    class Controller {
    private:
        shared_ptr<Repository> rep;
    public:

        Controller(shared_ptr<Repository>rep1);

        vector<Auto> search_auto_by_model(const string &Model) const;

        vector<Auto> search_auto_by_brand(const string &Brand) const;

        vector<Auto> filter_by_age(int Age) const;

        vector<Auto> filter_by_distance(int Distance) const;

        vector<Auto> sort_by_price();
    };
}




#endif //UNTITLED4_CONTROLLER_H
