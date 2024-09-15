#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start;
    int finish;

    Activity(int s, int f)
    {
        start = s;
        finish = f;
    }
};

bool compare(Activity a, Activity b)//sorts in ascending order
{
    return a.finish < b.finish;
}

bool overlapping(Activity a, Activity b)
{
    return b.finish > a.start || a.finish > b.start;
}

int main()
{
    int n;
    vector<Activity> activities;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        activities.push_back(Activity(s, f));
    }

    sort(activities.begin(), activities.end(), compare);

    int i = 0;
    Activity current(0, 0);//first activity always selected
    do
    {
        Activity a = activities[i];
        if(i == 0 || !overlapping(current, a))
        {
            current = a;
            cout << "Doing activity (start = " << current.start << ", finish = " << current.finish << ")" << endl;
        }
        i++;
    }
    while(i < n);


   /* Activity current(0, 0);//first activity always selected
    for (int i = 0; i < n; i++)
    {
        Activity a = activities[i];//Activity object a
        if (i == 0 || !overlapping(current, a))
        {
            current = a;
            cout << "Doing activity (start = " << current.start << ", finish = " << current.finish << ")" << endl;
        }
    }*/



    for(int i = 0; i < n; i++)
    {
        cout << activities[i].start << ", " << activities[i].finish << endl;
    }
    return 0;
}
