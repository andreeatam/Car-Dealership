#ifndef UNTITLED4_AUTO_H
#define UNTITLED4_AUTO_H
#include <iostream>
using namespace std;

namespace auto_nspc{
    struct Time {
        int hr;
        int min;
        int sec;
    };

    class Auto {
    private:
        string model;
        string brand;
        int registrationYear;
        int km;
        float price;
        Time loadingTime;
        int range;

    public:
        Auto();

        Auto(string model, string brand, int registrationYear, int km, float price, int hr, int min, int sec,
             int range);

        const string &getModel() const;

        void setModel(const string &model);

        const string &getBrand() const;

        void setBrand(const string &brand);

        int getRegistrationYear() const;

        void setRegistrationYear(int registrationYear);

        int getKm() const;

        void setKm(int km);

        float getPrice() const;

        void setPrice(float price);

        const Time &getLoadingTime() const;

        void setLoadingTime(const Time &loadingTime);

        int getRange() const;

        void setRange(int range);

        void to_string() const;

        void operator=(Auto car2);

        bool operator==(Auto car2);

    };
}



#endif //UNTITLED4_AUTO_H
