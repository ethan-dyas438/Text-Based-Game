#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string FirstChoice;
int section = 0;
string name;
void save(string name);
void load();
long size;

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
        };
    };
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
        };
    if(section == 4){
        cout << "After a short time, you arrive at the bridge with C-15. What do you wish to do?";
        //cout << name << endl;


    };





    return 0;
}
//Keep troubleshooting load and save system
void save(string name) {
    ofstream mysave;
    mysave.open("Save.txt");
    mysave << name;
    mysave.close();

}

void load() {

    ifstream loadFile;
    loadFile.open ("Save.txt");
    while (loadFile.good()){
        cout << loadFile.get();
        getline(cin, name);
    }
    loadFile.close();

}