//
// Created by Xianze on 11/7/2016.
//

#ifndef HAIR_SALON_SCHEDULER_H
#define HAIR_SALON_SCHEDULER_H
#include <iostream>
#include <map>
using namespace std;


class scheduler {
    map<int,pair<int,int>> mymap; //map of the schedule, map<time,pair<appoint num, type>>
    int count; // appointment count;
public:
    scheduler(){
        mymap =  map <int,pair<int,int>>();
        count=0;

        int begin =900;//start from 9am ,last appointment at 9pm
        while(begin<=2100){
            mymap[begin].first = -1; //-1 means no appointment at this time
            mymap[begin].second = -1;
            begin=add_time(begin,15);
        }
    }
    bool schedule_haircut (string time){
        int t = stoi(time);
        if(mymap[t].first!=-1)//not available
        {
            return false;
        }

        cout<<"adding haircut to time: "<<t<<endl;
        count++;
        mymap[t].first=count;
        mymap[t].second=1;
        mymap[add_time(t,15)].first=count;
        mymap[add_time(t,15)].second=1;
        return true;
    }
    bool schedule_sh (string time){
        int t = stoi(time);
        if(mymap[t].first!=-1)//not available
        {
            return false;
        }
        cout<<"adding shampoo & haircut to time: "<<t<<endl;
        count++;
        mymap[t].first=count;
        mymap[t].second=2;
        mymap[add_time(t,15)].first=count;
        mymap[add_time(t,15)].second=2;
        mymap[add_time(t,30)].first=count;
        mymap[add_time(t,30)].second=2;
        mymap[add_time(t,45)].first=count;
        mymap[add_time(t,45)].second=2;
        return true;
    }

    void list(){
     //print all schedule
        int prev=-1;
        int counts=0;
        for(auto it=mymap.begin();it!=mymap.end();it++){
            if(it->second.first!=-1 && it->second.first!=prev) {
                prev=it->second.first;
               if(it->second.second==1){
                   counts++;
                   cout << "Appointment "<<counts << ": Haircut at " << it->first<<endl;
               }
               if(it->second.second==2) {
                   counts++;
                   cout << "Appointment " << counts << ": Shampoo & Haircut at " << it->first << endl;
               }
            }
        }
    }

    int add_time(int t1,int t2){
        //t2 is either 15, 30 or 45.
        int h1=t1/100;
        int m1=t1-h1*100;
        int m =m1+t2;
        int h = h1;
        if(m>59){
            m=m-60;
            h++;
        }
        return h*100+m;
    }
};

#endif //HAIR_SALON_SCHEDULER_H
