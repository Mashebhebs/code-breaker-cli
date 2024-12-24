#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

vector<int> set_code() {
    vector<int> code(4, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 8);

    for (int i = 0; i < 4; ++i) {
        int value = dis(gen);
        while (find(code.begin(), code.end(), value) != code.end()) {
            value = dis(gen);
        }
        code[i] = value;
    }
    return code;
}

string get_user_answer() {
    string answer;
    cout << "Input 4 digit code: ";
    cin >> answer;
    return answer;
}

pair<int, int> code_checker(const vector<int>& code, const string& answer) {
    int correct_digits_and_position = 0;
    int correct_digits_only = 0;

    for (int i = 0; i < 4; ++i) {
        if (code[i] == (answer[i] - '0')) {
            correct_digits_and_position++;
        } else if (find(code.begin(), code.end(), (answer[i] - '0')) != code.end()) {
            correct_digits_only++;
        }
    }

    return make_pair(correct_digits_and_position, correct_digits_only);
}

void check_and_print_outcome(const vector<int>& code) {
    cout << "4-digit Code has been set. Digits in range 1 to 8. You have 12 turns to break it." << endl;
    bool correct = false;
    int turns = 0;

    while (!correct && turns < 12) {
        string answer = get_user_answer();

        if (answer.length() != 4) {
            cout << "Please enter exactly 4 digits." << endl;
            continue;
        }

        int correct_digits_and_position, correct_digits_only;
        tie(correct_digits_and_position, correct_digits_only) = code_checker(code, answer);

        cout << "Number of correct digits in correct place:    " << correct_digits_and_position << endl;
        cout << "Number of correct digits not in correct place: " << correct_digits_only << endl;
        turns++;

        if (correct_digits_and_position == 4) {
            correct = true;
            cout << "Congratulations! You are a codebreaker!" << endl;
        } else {
            cout << "Turns left: " << 12 - turns << endl;
        }
    }

    cout << "The code was: ";
    for (int digit : code) {
        cout << digit;
    }
    cout << endl;
}

int main() {
    vector<int> code = set_code();
    check_and_print_outcome(code);
    return 0;
}
