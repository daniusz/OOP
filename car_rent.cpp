// Car rent company simulation

#include "iostream"

using namespace std;

class Client
{
public:
    string f_name;
    string l_name;
    string p_number;

    Client(string c_f_name, string c_l_name, string c_p_number)
    {
    	f_name = c_f_name;
        l_name = c_l_name;
        p_number = c_p_number;
    }

    void client_order()
    {
    	cout << "Hi. My name is " << f_name << " " << l_name << " I want to rent a car for 5 days." << endl ;
    }
};

class Dispatcher
{
public:
    string f_name;
    string l_name;
    string p_number;
    int salary;

    Dispatcher(string d_f_name, string d_l_name, string d_p_number, int d_salary)
    {
    	f_name = d_f_name;
        l_name = d_l_name;
        p_number = d_p_number;
        salary = d_salary;
    }

    void get_order()
    {
    	cout << f_name << " " << l_name << ": have a new order. " << endl;
    }
};

class Reservation
{
public:
    string start_time;
    string end_time;
    float price;

    Reservation(string r_start_time, string r_end_time, float r_price)
    {
    	start_time = r_start_time;
        end_time = r_end_time;
        price = r_price;
    }

    void reservation()
    {
    	cout << "Client ordered a car from "<< start_time<< " to " << end_time << endl;
    }
};

class Dealer
{
public:
    string f_name;
    string l_name;
    string p_number;
    int salary;
    int percent_of_sales;


    Dealer(string dl_f_name, string dl_l_name, string dl_p_number, int dl_salary, int dl_percent_of_sales)
    {
    	f_name = dl_f_name;
        l_name = dl_l_name;
        p_number = dl_p_number;
        salary = dl_salary;
        percent_of_sales = dl_percent_of_sales;
    }

    void give_car()
    {
    	cout << "Good day, I'm dealer in the company DreamCar. My name is" << f_name << " " << l_name << "Announce that your order is approved." << endl;
    }
};

class Marketing_specialist{
public:
    string f_name;
    string l_name;
    string p_number;
    int salary;

    Marketing_specialist(string m_f_name, string m_l_name, string m_p_number, int m_salary)
    {
        f_name = m_f_name;
        l_name = m_l_name;
        p_number = m_p_number;
        salary = m_salary;
    }
    void advertising()
    {
    	cout << f_name << " " << l_name <<" : Hi! You want a luxury car for the meeting or an SUV for a picnic trip? \nDreamCar provides you this opportunity! Do not limit yourself and always be on an IRON HORSE!\n" << endl;
    }
};

class Car
{
public:
    string model;
    string gearbox;
    string fuel_type;
    int number_of_seats;
    int avg_fuel_consumption;
    string state_number;

    Car(string c_model, string c_gearbox, string c_fuel_type, int c_number_of_seats, int c_avg_fuel_consumption, string c_state_number)
    {
        model = c_model;
        gearbox = c_gearbox;
        fuel_type = c_fuel_type;
        number_of_seats = c_number_of_seats;
        avg_fuel_consumption = c_avg_fuel_consumption;
        state_number = c_state_number;
    }

    void car_specs()
    {
        if(number_of_seats > 5 ){
            cout << "This is WAGON." << endl;
        }else{
            cout << "This is SEDAN." << endl;
        }
    }
};

class Payment
{
public:
    string payment_type;
    float total;


    Payment(string p_payment_type, float p_total)
    {
    	payment_type = p_payment_type;
        total = p_total;

    }

    void payment_details()
    {
        cout << "Total: " << total <<" MDL."<< "Payment type: " << payment_type << endl;
        if(total == 0){
            cout << "Need to pay !" << endl;
        }
        if(payment_type=="CARD"){
            cout<<"Payment with CARD - successfully !\n";
        }
        else{
            cout << "Payment with CASH - successfully !" << endl;
        }
    }
};

class Director
{
public:
    string f_name;
    string l_name;
    string p_number;
    float profit=0;

    Director(string dr_f_name, string dr_l_name, string dr_p_number)
    {
        f_name = dr_f_name;
        l_name = dr_l_name;
        p_number = dr_p_number;
    }

    void manage_company()
    {
        cout << "Good day. My name is " << f_name <<" "<< l_name << " I'm represent the company DreamCar." << endl;
    }

    void manage_profit(float total_amount) {
        profit = profit + total_amount;
        cout << "Profit today: " << profit << " MDL." << endl;
    }


};

class Autoservice
{
public:
    float expenses = 0;

    float calculate_expenses(float car_maintenance){
        expenses = expenses + car_maintenance;
        return expenses;
    }
    void report_expenses(){
        cout<<"Maintenance of this car per week will cost "<<expenses<<" MDL\n";
    }
};


class Rating
{
public:
    string rating;

    void service_rating(string rating){
    	cout << "Rating from client: " << rating << " out of 5." << endl;
    }
};


int main()
{
    float income_monthly = 0;

    Client client_p("Eugen", "Hincu", "079 906 588");
    Dispatcher dispatcher_p("Mihaela", "Dicusar", "022 650 650", 6800);
    Reservation reservation_p("22.10.2022", "27.10.2022", 2150);
    Marketing_specialist specialist_p("Nicolae","Sarbu","060 215 720", 8000);
    Car car_p("Hyundai Grand SantaFe", "Automtic (CVT)", "Petrol", 7 , 9.5 , "GHS 852");
    Dealer dealer_p("Elena", "Frunze", "069 748 167", 12000, 8);
    Payment payment_p("CARD", 2150);
    Director director_p("Leonid", "Broveanu", "078850500");
    Autoservice autoservice_p;
    Rating rating_p;

    specialist_p.advertising();
    client_p.client_order();
    cout << "I want to rent " << car_p.model << endl ;
    dispatcher_p.get_order();
    reservation_p.reservation();
    dealer_p.give_car();
    car_p.car_specs();
    cout << "Thanks. Nice car, I'll be back.\n";
    payment_p.payment_details();
    rating_p.service_rating("5");
    int profit= payment_p.total;
    autoservice_p.calculate_expenses(780);
    autoservice_p.report_expenses();
    profit=profit-autoservice_p.expenses;
    director_p.manage_company();
    director_p.manage_profit(profit);

    return 0;
}
