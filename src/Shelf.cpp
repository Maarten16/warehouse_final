#include "include/Shelf.hpp"

Shelf::Shelf() {}

//Two pallets inside a Shelf are swapped
bool Shelf::swapPallet(int slot, int slot2){
    Pallet temp = pallets[slot];//temporary variable
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
    return true;
}

