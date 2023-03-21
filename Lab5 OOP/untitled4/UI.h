#ifndef UNTITLED4_UI_H
#define UNTITLED4_UI_H
#include "Controller.h"
#include "domain.h"
using domain::Manager;
using domain::Client;
using controller::Controller;
#include <memory>

namespace ui{
    class UI {
    private:
        shared_ptr<Controller> ctrl;
        shared_ptr<Manager> mng = make_shared<Manager>();
        shared_ptr<Client> cst = make_shared<Client>();
    public:
        UI(shared_ptr<Controller>ctrl1);
        void pick_user();
        void pick_manager();
        void pick_client();
    };
}



#endif //UNTITLED4_UI_H
