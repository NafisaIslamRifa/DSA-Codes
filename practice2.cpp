#include<bits/stdc++.h>
using namespace std;


/*vector<int>min_coins;
int min_no(int coins[],int n,int amount){
    int coins_no=0;
    sort(coins,coins+n,greater<int>());
    for(int i=0;i<n;i++){
    if(coins[i]<amount){
        int need=amount/coins[i];
        amount-=need*coins[i];
        coins_no+=need;
        while(need--)
            min_coins.push_back(coins[i]);
    }
    }
    return coins_no;





}






int main(){

    int minNocoins=min_no(a,n,amount);

}*/
//jeta maximize korte chai oita/onno ta ,marks maximixe
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Question {
    int marks;
    int time;
    double progress;

    double marks_perMinute() {
        return (double)marks / time;
    }
};

bool question_com(Question a, Question b) {
    return a.marks_perMinute() > b.marks_perMinute();
}

int main() {
    vector<Question> questions;
    int N, total_time, total_marks;

    cout << "Enter the number of questions (N): ";
    cin >> N;

    cout << "Enter total time for the exam (T minutes): ";
    cin >> total_time;

    cout << "Enter total marks of the exam (M): ";
    cin >> total_marks;

    cout << "Enter the marks and time for each question:\n";
    for (int i = 0; i < N; i++) {
        int marks, time;
        cin >> marks >> time;

        Question question;
        question.marks = marks;
        question.time = time;
        questions.push_back(question);
    }

    sort(questions.begin(), questions.end(), question_com);

    int current_time = 0;
    int obtained_marks = 0;
    vector<int> selected_questions;

    for (int i = 0; i < N; i++) {
        if (current_time + questions[i].time <= total_time) {
            current_time += questions[i].time;
            obtained_marks += questions[i].marks;
            selected_questions.push_back(i);
            questions[i].progress = 100.0;
        } else {
            int remaining_time = total_time - current_time;
            obtained_marks += (remaining_time * questions[i].marks_perMinute());
            questions[i].progress = (remaining_time / (double)questions[i].time) * 100.0;
            break; // No more questions can be answered within the remaining time
        }
    }

    cout << "Maximum marks obtained: " << obtained_marks << " marks" << endl;
    cout << "Selected questions:\n";
    for (int i = 0; i < selected_questions.size(); i++) {
        int idx = selected_questions[i];
        cout << "ques " << idx + 1 << " " << questions[idx].progress << "% done -- " << questions[idx].marks << " marks" << endl;
    }

    return 0;
}
