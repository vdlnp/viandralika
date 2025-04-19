#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Trivia {
private:
    string name, country, game_name;
    int age;
    float score[3];
    char status[20];
public:
    void setParticipant() {
        cin.ignore();
        cout << "\nEnter Name\t: ";
        getline(cin, name);
        cout << "Enter Country\t: ";
        getline(cin, country);
        cout << "Enter Age\t: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Game Name : ";
        getline(cin, game_name); 
    }

    void score_Gained() {
        cout << "Enter Score 1 : ";
        cin >> score[0];
        cout << "Enter Score 2 : ";
        cin >> score[1];
        cout << "Enter Score 3 : ";
        cin >> score[2];
    }

    void average_Val() {
        float total = 0.0;
        for (int i = 0; i < 3; ++i) {
            total += score[i];
        }
        float avg = total / 3;
        set_status(avg);
    }

    void set_status(double avg) {
        if (avg >= 80 && avg <= 100)
            strcpy(status, "Excellent");
        else if (avg >= 60 && avg < 80)
            strcpy(status, "Great");
        else 
            strcpy(status, "Keep Trying");
    }

    void display_result() {
        cout << "------------------------------\n";
        cout << "RESULT SCORED\n";
        cout << "------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Country: " << country << endl;
        cout << "Age: " << age << endl;
        cout << "Game name: " << game_name << endl;
        cout << "Score 1: " << score[0] << endl;
        cout << "Score 2: " << score[1] << endl;
        cout << "Score 3: " << score[2] << endl;
        cout << "Status: " << status << endl;
    }
};

int main() {
    int numParticipants;
    cout << "How many warriors? ";
    cin >> numParticipants;

    Trivia tv;
    Trivia* tv1 = &tv;

    for (int i = 0; i < numParticipants; ++i) {
        tv1->setParticipant();
        tv1->score_Gained();
        tv1->average_Val();
        tv1->display_result();
    }

    return 0;
}

