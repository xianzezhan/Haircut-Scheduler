#include <iostream>
#include "scheduler.h"
using namespace std;
int main() {
    cout<<"Please enter your command. Enter help for command info."<<endl;
    string in;
    getline(cin,in);
    string time;
    scheduler s;

    while(in!="exit"){
        if(in.find(" ") != string::npos){
        time= in.substr(in.find(" ") + 1);
        in = in.substr(0,in.find(" "));
        }
        else
            time="";
        if (in == "help") {
            cout << "You may enter list, haircut/h [time], shampoo&haircut/sh [time], exit. Please use lower case only." << endl;
            cout<<"Example: sh 1300 means schedule a shampoo&haircut at 13:00."<<endl;
            cout << "Please enter your command. Enter help for command info"<<endl;
            getline(cin,in);
        } else if (in == "list") {
            s.list();
            cout << "Finish Printing all schedules."<<endl;
            getline(cin,in);
        } else if (in == "haircut" || in=="h") {
            if(time==""){
                cout<<"Missing schedule time. Please re-enter command."<<endl;
                getline(cin,in);
                continue;
            }
            bool res=s.schedule_haircut (time);
            if(!res){
                cout<<"Timeslot is not available, please re schedule."<<endl;
            }
            getline(cin,in);
        } else if (in == "shampoo&haircut"|| in=="sh") {
            if(time==""){
                cout<<"Missing schedule time. Please re-enter command."<<endl;
                getline(cin,in);
                continue;
            }
            bool res=s.schedule_sh (time);
            if(!res){
                cout<<"Timeslot is not available, please re schedule."<<endl;
            }
            getline(cin,in);
        }
        else{
            cout<<"Invalid Input. You may enter list, haircut [time], shampoo&haircut [time], exit. Please use lower case only."<<endl;
            cout<<"Please enter your command."<<endl;
            getline(cin,in);
        }
    }
    return 0;
}