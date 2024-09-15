#include<bits/stdc++.h>
using namespace std;


struct Event{
    string id;
    int start;
    int duration;

    Event(const string&i,int s,int d){//---------------
        id=i;
        start=s;
        duration=d;
    }

};

bool compare(Event a,Event b){//-----------------
    return a.start+a.duration<b.start+b.duration;


}

bool overlapping(Event a,Event b,int break_t){
return b.start<a.start+a.duration+break_t;//___----------

}

int main()
{

    int n;
    cin>>n;
    string id;
    int start;
    int duration;
    vector<Event>events;
    for(int i=0;i<n;i++){
            cin>>id>>start>>duration;
    events.push_back(Event(id,start,duration));

    }//vector e input dear por sort

    sort(events.begin(),events.end(),compare);//comapre er pore no parameter
    int break_t;
    cin>>break_t;
     Event current("",0,0);
    for(int i=0;i<n;i++){
        //Event current("",0,0);
        Event a=events[i];
        if(i==0||!overlapping(current,a,break_t)){
            current=a;
            cout<<"club id:  "<<current.id<<"  "<<  "start :"<<" "<<current.start<<  "duration:  "<<" "<<current.duration<<endl;
        }
    }
}
