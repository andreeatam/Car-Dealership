#include "Repository.h"
#include <algorithm>
using repo::Repository;
using auto_nspc::Auto;

Repository::Repository() {
    cars.emplace_back("Model S", "Tesla", 2022, 5000, 101190.00, 1, 30, 0, 575);
    cars.emplace_back("Taycan Turbo S", "Porsche", 2022, 5000, 190860.99, 1, 30, 0, 412);
    cars.emplace_back("Model 3", "Tesla", 2021, 8000, 48189.00, 1, 30, 0, 455);
    cars.emplace_back("e", "Honda", 2020, 8000, 39980.00, 1, 30, 0, 211);
    cars.emplace_back("2", "Polestar", 2022, 7500, 45900.00, 1, 30, 0, 427);
    cars.emplace_back("e-tron GT", "Audi", 2021, 7500, 74999.99, 1, 30, 0, 430);
    cars.emplace_back("Enyaq iV", "Skoda", 2020, 4000, 3056.00, 1, 30, 0, 420);
    cars.emplace_back("Mustang Mach-E", "Ford", 2020, 4000, 43895.5, 1, 30, 0, 455);
    cars.emplace_back("Kona", "Hyundai", 2021, 4500, 40163.5, 1, 30, 0, 437);
    cars.emplace_back("i3", "BMW", 2020, 8000, 40281.95, 1, 30, 0, 235);
    cars.emplace_back("ID.4", "Volkswagen", 2021, 5000, 45500.00, 1, 45, 0, 450);
}

void Repository::add_car(Auto car){
        cars.push_back(car);
}
void Repository::delete_car(Auto car){
    cars.erase(std::find(cars.begin(), cars.end(), car));
}

void Repository::edit_car(Auto car, Auto new_car){
    ptrdiff_t pos= exists(car);
    cars[pos]=new_car;
}

vector<Auto> Repository::get_cars(){
    return cars;
}

int Repository::get_rep_size(){
    return cars.size();
}

ptrdiff_t Repository::exists(Auto car) {
    if (std::find(cars.begin(), cars.end(), car) != cars.end()) {
        return std::find(cars.begin(), cars.end(), car) - cars.begin();
    }
    return -1;
}
