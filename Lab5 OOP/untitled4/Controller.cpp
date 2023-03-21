#include "Controller.h"
using controller::Controller;
#include <algorithm>

Controller::Controller(shared_ptr<Repository>rep1) {
    rep=rep1;
}

vector<Auto> Controller::search_auto_by_model(const string &Model) const{
    vector<Auto> found_cars;
    for (int index = 0; index < rep->get_rep_size(); ++index)
    {
        auto current_car = rep->get_cars().at(index);
        if (current_car.getModel() == Model)
            found_cars.push_back(current_car);
    }
    return found_cars;
}

vector<Auto> Controller::search_auto_by_brand(const string &Brand) const{
    vector<Auto> found_cars;
    for (int index = 0; index < rep->get_rep_size(); ++index)
    {
        auto current_car = rep->get_cars().at(index);
        if (current_car.getBrand() == Brand)
            found_cars.push_back(current_car);
    }
    return found_cars;
}

vector<Auto> Controller::filter_by_age(int Age) const{
    vector<Auto> found_cars;
    for (int index = 0; index < rep->get_rep_size(); ++index)
    {
        auto current_car = rep->get_cars().at(index);
        if (current_car.getRegistrationYear() <= Age)
            found_cars.push_back(current_car);
    }
    return found_cars;
}

vector<Auto> Controller::filter_by_distance(int Distance) const{
    vector<Auto> found_cars;
    for (int index = 0; index < rep->get_rep_size(); ++index)
    {
        auto current_car = rep->get_cars().at(index);
        if (current_car.getKm() <= Distance)
            found_cars.push_back(current_car);
    }
    return found_cars;
}

vector<Auto> Controller::sort_by_price(){
    vector<Auto> sorted_cars=rep->get_cars();
    std::sort(sorted_cars.begin(), sorted_cars.end(), [](const Auto &first, const Auto &second) { return first.getPrice() > second.getPrice(); });
    return sorted_cars;
}