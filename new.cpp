#include<bits/stdc++.h>
using namespace std;

void plag(string s1,string s2){
    int c=0;
    vector<string>p;
   // if(s1.substr(0,s2.length())==s2)
   for(int i=0;i<s2.length();i++){
   if(s1[i]==s2[i]){
    c++;
    p.push_back(s1[i]);
   }
   }


}
