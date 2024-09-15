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

bool compare(Activity a, Activity b)//ascending order
{
    return a.finish < b.finish;
}

bool overlapping(Activity a, Activity b)
{
    return !(b.finish <= a.start || a.finish <= b.start);
}

int main()
{
    int n;
    vector<Activity> activities;

    cout << "Enter the number of activities: ";
    cin >> n;

    cout << "Enter the start and finish times for each activity:\n";
    for (int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        activities.push_back(Activity(s, f));
    }

    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";
    Activity current(0, 0);   //first activity always selected
    for (int i = 0; i < n; i++)
    {
        Activity a = activities[i];
        if (i == 0 || !overlapping(current, a))//activity object a
        {
            current = a;
            cout << "Doing activity (start = " << current.start << ", finish = " << current.finish << ")" << endl;
        }
    }

    return 0;
}

