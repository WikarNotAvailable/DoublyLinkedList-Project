#include "functions.h"
using namespace std;
bool load_arguments(int& argc, char* argv[], string& data_base_in, string& data_base_in2, string& data_base_in3, string& data_base_out) {

    int const count = 9;

    if (argc == count) {

        for (int i = 1; i < argc; i += 2) {

            string temp = argv[i];

            if (temp == "-inper") {

                if (data_base_in == "")
                    data_base_in = argv[i + 1];

                else {

                    cout << "You have given the name of people file twice." << endl;
                    return false;
                }
            }
            else if (temp == "-inbook") {

                if (data_base_in2 == "")
                    data_base_in2 = argv[i + 1];

                else {

                    cout << "You have given the name of books file twice." << endl;
                    return false;
                }
            }
            else if (temp == "-inbor") {

                if (data_base_in3 == "")
                    data_base_in3 = argv[i + 1];

                else {

                    cout << "You have given the name of borrowings file twice." << endl;
                    return false;
                }

            }
            else if (temp == "-out") {

                if (data_base_out == "")
                    data_base_out = argv[i + 1];

                else {

                    cout << "You have given the name of output file twice." << endl;
                    return false;
                }

            }
            else {

                cout << "Invalid arguments." << endl;
                return false;
            }

        }

        return true;
    }
    else
    {
        cout << "You have written invalid amount of arguments out of " << count - 1 << endl;
        cout << "To start the program you have to enter arguments using following flags: " << endl;
        cout << "-inper name of people file " << endl;
        cout << "-inbook name of books file" << endl;
        cout << "-inbor name of borrowings file" << endl;
        cout << "-out name of output file" << endl;
        return false;
    }
}