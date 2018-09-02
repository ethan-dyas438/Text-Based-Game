#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string FirstChoice;
int section = 0;
string name;
void save(string name);
void load();
//long size;

int main()
{
    cout << "Welcome to your Story! \n";
    cout << "Press 1 then ENTER to begin or the number of the section you were last on." << endl;
    cin >> section;
    if(section > 2){
        load();
    }
    if(section == 1){

        cout << "1. You wake up to the noises coming from ";
        cout << "inside the thing you are in. What do you wish to do?" << endl;
        cout << "-->Exit \n-->Sleep" << endl;
        cin >> FirstChoice;
        if(FirstChoice == "Exit"){
            section++;
        }
    }
    if(section == 2) {

        cout << "2. You exit what appears to be your cryopod and are ";
        cout << "greeted by a robotic voice coming from an android. \n";
        cout << "'What is your name?'" << endl;
        cin >> name;
        save(name);
        section++;
    }
    if(section == 1 && FirstChoice != "Exit"){
        cout << "You go back to sleep and never wake up again." << endl;
        cout << "Thank you for playing the game." << endl;
    }
    if(section == 3){

        cout << "3. 'Welcome to the Atlas " << name << ". Your very own ";
        cout << "Class 5 Star Explorer. I am the ships navigator, you may call me C-15. ";
        cout << "I will now show you to the bridge.'" << endl;
        section++;
        }
    if(section == 4){
        cout << "4. This story is a work in progress and will continue to receive updates in the future.";
        //Add next decision and more story.
    }





    return 0;
}

void save(string const name) {  //Saves inputted name variable to Save.txt
    ofstream mysave;
    mysave.open("Save.txt");
    mysave << name; //save name string to the text file
    mysave.close(); // Closes save function

}

void load() {  //If user loads from a point after section 3 the name variable is loaded from Save.txt

    ifstream file("Save.txt");
    stringstream buffer;
    buffer << file.rdbuf();
    name = buffer.str();

}
