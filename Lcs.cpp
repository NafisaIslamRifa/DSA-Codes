#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 int dpTable[100][100];
 int LCS(string s1,int sz1,string s2,int sz2){
     //if string 1 is empty
     for(int i=0;i<=sz1;i++){
        dpTable[i][0]=0;
     }
     //if string 2 is empty
     for(int j=0;j<=sz2;j++){
        dpTable[0][j]=0;
     }

     for(int i=1;i<=sz1;i++){
        for(int j=1;j<=sz2;j++){
            if(s1[sz1-1]==s2[sz2-1]){
                dpTable[sz1][sz2]=1+dpTable[sz1-1][sz2-1];
            }
            else{
               dpTable[sz1][sz2]=max(dpTable[sz1][sz2-1],dpTable[sz1-1][sz2]);
            }
        }
     }

     return dpTable[sz1][sz2];


 }


 int main(){
     string s1="AGGTAB";

     int sz1=s1.size();

     string s2="GXTXAYB";
     int sz2=s2.size();

     cout<<LCS(s1,sz1,s2,sz2)<<endl;
     return 0;



 }

