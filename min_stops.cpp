#include<bits/stdc++.h>
using namespace std;

bool find_ToStop(int d,int m,vector<int>&gas_stations,vector<int>&station_stop){
    int cur_position=0;
    for(int i=0;i<gas_stations.size();++i){
            if(gas_stations[i]-cur_position>m){
                station_stop.push_back(i-1);
                cur_position=gas_stations[i-1];
            }

    }
    if(d-cur_position>m){
       return false;
    }

    return true;



}

int main(){
    int m;
    int d;
    int n;
    cout<<"enter d:"<<endl;
    cin>>d;
    cout<<"enter m:"<<endl;
    cin>>m;
    cout<<"enter n:"<<endl;
    cin>>n;

    vector<int>gas_stations;
    vector<int>station_stop;
    int station;
     cout<<"enter gas stations"<<endl;
    for(int i=0;i<n;++i){
        cin>>station;
        gas_stations.push_back(station);
    }

    bool flag=find_ToStop( d, m,gas_stations,station_stop);

    if(flag){
            if(station_stop.empty()){
                cout<<"can reach without stops"<<endl;
            }
            else{
                    for(int i=0;i<station_stop.size();++i){
                       cout<< "Stop at gas station "<<station_stop[i]+1<<"("<<gas_stations[station_stop[i]]<<" miles)\n";
                    }

            }


    }

    else {
        cout << "Can't reach destination." << endl;
    }
    return 0;




}
