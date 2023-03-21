#ifndef UNTITLED4_REPOSITORY_H
#define UNTITLED4_REPOSITORY_H
#include "Auto.h"
using auto_nspc::Auto;
using namespace std;
#include <vector>

namespace repo{
    class Repository {
    private:
        std::vector<Auto> cars;
    public:
        Repository();
        void add_car(Auto car);
        void delete_car(Auto car);
        void edit_car(Auto car, Auto new_car);
        vector<Auto>get_cars();
        ptrdiff_t exists(Auto car);
        int get_rep_size();
    };
}



#endif //UNTITLED4_REPOSITORY_H
