#include "include/Pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount)
: itemName(itemName),
itemCapacity(itemCapacity),
itemCount(itemCount) {
    //limits itemcount to itemCapacity
    if(itemCount > itemCapacity) {
        this->itemCount = itemCapacity;
    }
}

Pallet::Pallet() {
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;}

std::string Pallet::getItemName() {//gets name of item in pallet
    return this->itemName;
}

int Pallet::getItemCount() {//gets amount of item in pallet
    return this->itemCount;
}

int Pallet::getRemainingSpace() {//gets remaining pallet space
    return this->itemCapacity - this->itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    //itemCont is already 0
    this->itemName = "";
    this->itemCapacity = 0;
}

//takes a single item from pallet
bool Pallet::takeOne() {
    if (itemCount > 0){
        itemCount -= 1;
        return true;
    } else {
        return false;
    }
}

//puts a single item in pallet
bool Pallet::putOne() {
    if (itemCount < itemCapacity){
        itemCount += 1;
        return true;
    } else {
        return false;
    }
}
