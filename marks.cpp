#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Question
{
    int index;
    int marks;
    int time;
    double progress;

    double marks_per_minute()
    {
        return (double)marks / time;
    }
};

bool questionComparator(Question a, Question b)
{
    return a.marks_per_minute() > b.marks_per_minute();
}

void maximizeMarks(vector<Question>& questions, int total_marks, int total_time)
{
    sort(questions.begin(), questions.end(), questionComparator);

    int current_time = 0;
    int obtained_marks = 0;
    vector<int> selected_questions;

    for (int i = 0; i < questions.size(); i++)
    {
        if (current_time + questions[i].time <= total_time)
        {
            current_time += questions[i].time;
            obtained_marks += questions[i].marks;
            selected_questions.push_back(i);
            questions[i].progress = 100.0;
        }
        else
        {
            double remaining_time = total_time - current_time;
           // obtained_marks += (remaining_time / questions[i].time) * questions[i].marks;
           obtained_marks += (remaining_time * questions[i].marks_per_minute());
            questions[i].progress = (remaining_time / questions[i].time) * 100.0;
            break;
        }
    }

    cout << "Maximum marks obtained: " << obtained_marks << " marks" << endl;
    cout << "Selected questions:\n";
   for (int i = 0; i < selected_questions.size(); i++)
    {
        int idx = selected_questions[i];
        cout << "ques " << questions[idx].index << " " << questions[idx].progress << "% done -- " << questions[idx].marks << " marks" << endl;
    }
}

int main()
{
    int M, T, N;
    cout << "Enter total marks of the exam (M): ";
    cin >> M;

    cout << "Enter total time for the exam (T minutes): ";
    cin >> T;

    cout << "Enter the number of questions (N): ";
    cin >> N;

    vector<Question> questions;
    int marks_i, time_i;

    cout << "Enter the marks and time for each question:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> marks_i >> time_i;
        questions.push_back({i + 1, marks_i, time_i, 0.0});
    }

    maximizeMarks(questions, M, T);

    return 0;
}
