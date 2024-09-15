#include<bits/stdc++.h>
using namespace std;


 struct Activity{
     string club_name;
     int start_time;
     int dur_time;
     Activity(const string&id,int s,int d){
     club_name=id;
     start_time=s;
     dur_time=d;


     }
 };

 bool compare(Activity a,Activity b){  //ascending order
   return a.start_time+a.dur_time<b.start_time+b.dur_time;

 }


 bool over_lapping(Activity a,Activity b,int break_time){
    return b.start_time<a.start_time+a.dur_time+break_time;

 }

 int main(){

     int n;
     cin>>n;
     vector<Activity>activities;
     for(int i=0;i<n;i++){   // parameter must same as Activity struct
            string club_name;
       int start_time;
       int dur_time;

        cin>>club_name>>start_time>>dur_time;
        activities.push_back(Activity(club_name,start_time,dur_time));
     }

     sort(activities.begin(),activities.end(),compare);
     int break_time;
     cin>>break_time;

     Activity current("",0,0);
     for(int i=0;i<n;i++){

        Activity e=activities[i];
        if (i == 0 || !over_lapping(current, e, break_time))
        {
            current = e;
            cout << "Club " << current.club_name<< ": Start Time = " << current.start_time << ", Duration = " << current.dur_time << " hours" << endl;
        }
     }

 }
