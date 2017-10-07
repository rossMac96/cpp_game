#include <iostream>
#include <string>
#include <random>
using namespace std;

//this is the base class for items contained in containers.
class item {
public:
    string name;
    int attack_strength;
	void setItem(string _name, int _attack_strength) {
		name = _name;
		attack_strength = _attack_strength;
	}
    virtual ~item() {};
};

//this is the base class for containers that are in room objects (environment objects)
class container {
public: 
    string name;
    string description;
    item items[10];
    bool isLocked;
    void setContainer(string _name, string _description, bool _isLocked) {
        isLocked = _isLocked;
        description = _description;
		name = _name;
	}
	
    void addItems(int index, string name, int attack_strength) {
		items[index].setItem(name, attack_strength);
    }
	
    virtual ~container() {};
};

//this is the class that room objects all inherit from. so far we 
//just have rooms, but we can also have other types of environments.
//if we want, we can have specific types of environments like rooms
//or dungeons or underground things etc, but for now it's just rooms
class environment {
public:
    string name;
    string intro;
	container containers[10];
    environment* east; environment* west; 
    environment* north; environment* south;
    //constructor
    environment(string _name, string _intro) {
		name = _name;
        intro = _intro;
    }
    //destructor
    virtual ~environment() {};

    //add references to other environment objects that are in the 
    //cardinal directions from the environment object in question
    void setSurroundings(environment* _north, environment* _south, 
    environment* _east, environment* _west) {
        north = _north;
        south = _south;
        east = _east;
        west = _west;
    }

    //spawns containers in the container list for the 
    //environment object you call this from.  add up to 10.
    void addContainers(int index, string name, string description, bool isLocked) {
		containers[index].setContainer(name, description, isLocked);
    }

    //note that inspect works only on containers, not items. (for now)
    int inspect(string input) {
        int i = 0;
        int j = 0;
        //iterate through this list of items in container.
        //error checking to make sure it doesn't segfault if given
        //bad container name.
        while(containers[i].name.compare(input) && i < 10) {
            i++;
        }
        if (i == 10) {
            cout<<"No such container to open." << endl;
        }
        else {
            cout << "Inspecting " << containers[i].name << ".\n" 
            << containers[i].description << "\n"<<endl;
            if (containers[i].isLocked == true) {
                cout<<"Unfortunately, it seems to be locked.\n"<< endl;
            }
    
            else {
                cout<<"It contains:"<< endl;
                while (containers[i].items[j].name != "") {
                    cout<<containers[i].items[j].name<<endl;
                    j++;
                }
            }
            
        }
        return 0;        
    }
};
