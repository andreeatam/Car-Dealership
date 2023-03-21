#include "Auto.h"
#include <utility>
using auto_nspc::Auto;
using auto_nspc::Time;

Auto::Auto()
{
    this->model = "";
    this->brand = "";
    this->registrationYear = 0;
    this->km = 0;
    this->price = 0.0;
    this->loadingTime.hr = 0;
    this->loadingTime.min = 0;
    this->loadingTime.sec = 0;
    this->range = 0;
}

Auto::Auto(string model, string brand, int registrationYear, int km, float price, int hr, int min, int sec, int range) :
        model(std::move(model)), brand(std::move(brand)), registrationYear(registrationYear), km(km), price(price),
        range(range)
{
    this->loadingTime.hr = hr;
    this->loadingTime.min = min;
    this->loadingTime.sec = sec;
}

const string &Auto::getModel() const
{
    return model;
}

void Auto::setModel(const string &model)
{
    this->model = model;
}

const string &Auto::getBrand() const
{
    return brand;
}

void Auto::setBrand(const string &brand)
{
    this->brand = brand;
}

int Auto::getRegistrationYear() const
{
    return registrationYear;
}

void Auto::setRegistrationYear(int registrationYear)
{
    this->registrationYear = registrationYear;
}

int Auto::getKm() const
{
    return km;
}

void Auto::setKm(int km)
{
    this->km = km;
}

float Auto::getPrice() const
{
    return price;
}

void Auto::setPrice(float price)
{
    this->price = price;
}

const Time &Auto::getLoadingTime() const
{
    return loadingTime;
}

void Auto::setLoadingTime(const Time &loadingTime)
{
    this->loadingTime = loadingTime;
}

int Auto::getRange() const
{
    return range;
}

void Auto::setRange(int range)
{
    this->range = range;
}

void Auto::to_string() const
{
    cout << "Auto: " << model << " " << brand << "\n\tRegistration Year: " <<
         registrationYear << "\n\tMileage: " << km << "\n\tPrice: " << price << "\n\tTime: " << loadingTime.hr << ":"
         << loadingTime.min << ":" << loadingTime.sec << "\n\tRange: " << range << '\n';
}

void Auto::operator=(Auto car2) {
    this->loadingTime=car2.loadingTime;
    this->registrationYear=car2.registrationYear;
    this->price=car2.price;
    this->brand=car2.brand;
    this->km=car2.km;
    this->model=car2.model;
    this->range=car2.range;
}

bool Auto::operator==(Auto car2){
    if(this->loadingTime.hr == car2.loadingTime.hr &&this->loadingTime.min == car2.loadingTime.min && this->loadingTime.sec == car2.loadingTime.sec   && this->registrationYear==car2.registrationYear&&this->price==car2.price && this->brand==car2.brand&&this->km==car2.km&&    this->model==car2.model&&this->range==car2.range){
        return true;
    }
    return false;

}