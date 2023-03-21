#include "domain.h"
using domain::Manager;
using domain::Client;

#include "Repository.h"
using auto_nspc::Auto;
using auto_nspc::Time;
using repo::Repository;

Repository rep;

void Manager::add_car(Auto car)
{
    rep.add_car(car);
}

void Manager::delete_car(Auto car)
{
    try{
        if(rep.exists(car)==-1){
            throw exception();
        }
    }
    catch(exception &e){
        cout<<"Car does not exist";
    }
    if(rep.exists(car)!=-1){
        rep.delete_car(car);
    }

}

void Manager::edit_car(Auto car, Auto new_car)
{
    try{
        if(rep.exists(car)==-1){
            throw exception();
        }
    }
    catch(exception &e){
        cout<<"Car does not exist";
    }
    if(rep.exists(car)!=-1){
        rep.edit_car(car,new_car);
    }
}

void Client::add_to_fav(Auto car)
{

    favs.push_back(car);
}

vector<Auto> Client::show_fav()
{
    return favs;
}