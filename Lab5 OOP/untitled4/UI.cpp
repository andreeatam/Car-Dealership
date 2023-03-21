#include "UI.h"
using ui::UI;
#include "Controller.h"
using controller::Controller;
#include "Auto.h"
using auto_nspc::Auto;
using auto_nspc::Time;
#include "domain.h"
using domain::Manager;
using domain::Client;

UI::UI(shared_ptr<Controller>ctrl1){
    ctrl=ctrl1;
}

void UI::pick_user() {
    cout << "Are you a manager or a client?" << endl;
    string user;
    cin >> user;
    try {
        if (user != "manager" && user != "Manager" && user != "client" && user != "Client") {
            throw exception();
        }
    }
    catch (exception &e) {
        cout << "Enter a valid role";
    }
    if (user == "manager" || user == "Manager") {
        pick_manager();
    } else if (user == "client" || user == "Client") {
        pick_client();
    }
}

Auto read_car_data(){
    string model;
    cout << "Model: ";
    cin >> model;

    string brand;
    cout << "Brand: ";
    cin >> brand;

    int registrationYear;
    cout << "Registration year: ";
    cin >> registrationYear;
    while (registrationYear > 2022)
    {
        cout << "Please enter a valid year!\n";
        cin >> registrationYear;
    }

    int km;
    cout << "Mileage: ";
    cin >> km;

    float price;
    cout << "Price: ";
    cin >> price;

    int hr, min, sec;
    cout << "Loading time:\n";
    cout << "\tNumber of Hours: ";
    cin >> hr;

    cout << "\tNumber of Minutes: ";
    cin >> min;

    cout << "\tNumber of Seconds: ";
    cin >> sec;

    int range;
    cout << "Range: ";
    cin >> range;

    return {model, brand, registrationYear, km, price, hr, min, sec, range};
}

void UI::pick_manager() {
    int choice = 1;
    while (choice != 0) {
        cout << " 1. Add car\n";
        cout << " 2. Remove car\n";
        cout << " 3. Edit car \n";
        cout << " 4. Search cars by specific model\n";
        cout << " 5. Search cars by specific brand \n";
        cout << " 6. Filter cars by registration year \n";
        cout << " 7. Filter cars by km \n";
        cout << " 8. Sort cars by price \n";
        cout << " 0. Exit \n";
        cout << " Choose:";
        cin >> choice;
        try {
            if (choice < 0 || choice > 6) {
                throw exception();
            }
        }
        catch (exception &e) {
            cout << "Invalid option";
        }

        switch (choice) {
            case 1: {
                //add car
                Auto car=read_car_data();
                UI::mng->add_car(car);
                break;
            }
            case 2: {
                //remove car
                Auto car=read_car_data();
                UI::mng->delete_car(car);
                break;
            }
            case 3: {
                //edit car
                Auto car=read_car_data();
                cout<<"Modified info";
                Auto new_car=read_car_data();
                UI::mng->edit_car(car, new_car);
                break;
            }
            case 4: {
                string model;
                cout << "Model:";
                cin >> model;
                //search by model
                vector<Auto>cars=UI::ctrl->search_auto_by_model(model);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 5: {
                string brand;
                cout << "Brand:";
                cin >> brand;
                //search by brand
                vector<Auto>cars=UI::ctrl->search_auto_by_brand(brand);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 6: {
                int year;
                cout << "Registration year:";
                cin >> year;
                //filter by year
                vector<Auto>cars=UI::ctrl->filter_by_age(year);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 7: {
                int km;
                cout << "km:";
                cin >> km;
                //filter by km
                vector<Auto>cars=UI::ctrl->filter_by_distance(km);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 8: {
                //sort by price
                vector<Auto>cars=UI::ctrl->sort_by_price();
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 0:
                exit(0);
        }
    }
}

void UI::pick_client() {
    int choice = 1;
    while (choice != 0) {
        cout << " 1. Search specific Model\n";
        cout << " 2. Search specific Brand\n";
        cout << " 3. Filter by Registration Year\n";
        cout << " 4. Filter by Mileage\n";
        cout << " 5. Sort by Price\n";
        cout << " 6. Add to Favourites\n";
        cout << " 7. Show Favourites\n";
        cout << " 0. Exit \n";
        cout << " Choose:";
        cin >> choice;
        try {
            if (choice < 0 || choice > 6) {
                throw exception();
            }
        }
        catch (exception &e) {
            cout << "Invalid option";
        }
        switch (choice) {
            case 1: {
                ///search by model
                string model;
                cout << "Model: ";
                cin >> model;
                vector <Auto>cars=UI::ctrl->search_auto_by_model(model);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 2: {
                ///search by brand
                string brand;
                cout << "Brand: ";
                cin >> brand;
                vector<Auto>cars=UI::ctrl->search_auto_by_brand(brand);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 3: {
                ///filter by year
                int year;
                cout << "Latest Registration Year: ";
                cin >> year;
                vector<Auto>cars=UI::ctrl->filter_by_age(year);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 4: {
                ///filter by km
                int km;
                cout << "Maximal Mileage: ";
                cin >> km;
                vector<Auto>cars=UI::ctrl->filter_by_distance(km);
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 5: {
                ///sort by price
                cout << "Cars sorted by Price (Ascending):\n";
                vector<Auto>cars=UI::ctrl->sort_by_price();
                for(int i=0; i<cars.size(); ++i){
                    cars[i].to_string();
                }
                break;
            }
            case 6: {
                ///add to fav
                Auto car=read_car_data();
                UI::cst->add_to_fav(car);
                break;
            }
            case 7: {
                vector<Auto>favs=UI::cst->show_fav();
                for(int i=0; i<favs.size(); ++i){
                    favs[i].to_string();
                }
                break;
            }
            case 0:
                exit(0);
        }
    }
}