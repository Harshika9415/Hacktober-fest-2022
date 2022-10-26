#include <iostream>
using namespace std;

main(){
    string color, pluralnoun, celebrity;
    cout << "enter a color: ";
    getline(cin, color);
    cout << "enter a pluralnoun: ";
    getline(cin, pluralnoun);
    cout << "enter a celebrity: ";
    getline(cin, celebrity);

    cout << "roses are "<< color<< endl;
    cout << pluralnoun << "are blue" << endl;
    cout << "i love" << celebrity << endl;
   
}