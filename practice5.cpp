#include<bits/stdc++.h>
using namespace std;

string prefix(const string &right,const string &left){
int min_length=min(left.length(),right.length());

for(int i=0;i<min_length;i++){

    if(left[i]!=right[i]){
        return left.substr(0,i);
    }
}
return left.substr(0, min_length);


}

string dnc(const vector<string>&strs,int left,int right){
  if(left==right){
    return strs[left];
  }

  int mid=(left+right)/2;
   string left_prefix=dnc(strs,left,mid);
   string right_prefix=dnc(strs,mid+1,right);

   return prefix(left_prefix,right_prefix);

}


string longest_common_prefix(vector<string> &strs) {
    if (strs.empty()) {
        return "";  // Return an empty string for no common prefix
    }

    return dnc(strs, 0, strs.size() - 1);
}


int main() {
    int N;
    cout << "Enter the number of strings: ";
    cin >> N;

    vector<string> strings(N);
    cout << "Enter " << N << " strings:\n";
    for (int i = 0; i < N; ++i) {
        cin >> strings[i];
    }

    string result = longest_common_prefix(strings);
    if (result.empty()) {
        cout << "No common prefix" << endl;
    } else {
        cout << "Longest common prefix: " << result << endl;
    }

    return 0;
}
