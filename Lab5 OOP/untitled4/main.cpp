#include <iostream>
using namespace std;
#include "Controller.h"
#include "UI.h"
#include "Repository.h"
using controller::Controller;
using ui::UI;
using repo::Repository;
#include <memory>

int main(){

    shared_ptr<Repository> rep=make_shared<Repository>();
    shared_ptr<Controller> ctrl= make_shared<Controller>(rep);
    UI ui(ctrl);
    ui.pick_user();
}