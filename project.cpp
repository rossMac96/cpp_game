#include <iostream>
#include <string>
#include <random>
#include "project.h"
int generateMap () {
    environment center_room("Center Room", "A room at the center of the map");
    environment cavern("cavern", "A deep cavern");
    environment staircase("staircase", "a tall spiral stairs");
    environment mineshaft("mineshaft", "a hella dank mineshaft");
    environment cellar("cellar", "a dank cellar");
    center_room.setSurroundings(&cavern, &staircase, &mineshaft, &cellar);
    //spawn containers in center_room
    center_room.addContainers(0, "Chest", "An ornate wooden chest." ,false);
    center_room.addContainers(1, "Bucket", "A plain, metal bucket." ,false);
    center_room.addContainers(2, "Safe", "A large, antique safe." ,true);
    //chest items
    center_room.containers[0].addItems(0, "hammer", 5);
    //bucket items
    center_room.containers[1].addItems(0, "saw", 20);
    center_room.containers[1].addItems(1, "hammer", 20);
    center_room.containers[1].addItems(2, "gold dust", 0);
    center_room.containers[1].addItems(3, "a bottle of jack", 10);
    center_room.containers[1].addItems(4, "bones of an ancient ancestor", 0);
    center_room.containers[1].addItems(5, "religious relics", 2);
    //safe items
    center_room.containers[2].addItems(0, "pickaxe", 17);
    
    //as of now, we are calling this from generate. in game,
    //this function will accept user input and can be called
    //from any environment.
    center_room.inspect("Bucket");
    return 0;
}

int main() {
    generateMap();
    return 0;
}
