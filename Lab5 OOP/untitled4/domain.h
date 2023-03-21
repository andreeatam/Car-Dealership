#include <vector>
#include "Auto.h"
using auto_nspc::Auto;
using auto_nspc::Time;
#ifndef UNTITLED4_DOMAIN_H
#define UNTITLED4_DOMAIN_H

namespace domain{
    class Manager{
    public:
        void add_car(Auto car);
        void delete_car(Auto car);
        void edit_car(Auto car, Auto new_car);
    };
class Client{
public:
    std::vector<Auto>favs;
    void add_to_fav(Auto car);
    vector<Auto> show_fav();
};
}


#endif //UNTITLED4_DOMAIN_H
