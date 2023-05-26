#include "include/instructions.hpp"

void printItems(Warehouse warehouse)
{
    for (Shelf shelf : warehouse.shelves) {
        for (Pallet pallet : shelf.pallets) {
            std::cout << pallet.getItemName()<< '\t' << pallet.getItemCount()<< '\n';
        }
    }
}

void printStock(std::string itemName, Warehouse warehouse){
    int itemsAvailable = 0;
    for (Shelf shelf : warehouse.shelves) {
        for (Pallet pallet : shelf.pallets) {
            if(itemName == pallet.getItemName()){
                itemsAvailable += pallet.getItemCount();
            }
        }
    }
    std::cout << itemsAvailable << '\n';
}

void printEmployees(Warehouse warehouse){
    for (Employee employee : warehouse.employees) {
        std::cout << employee.getName() << "\tforklift: " << employee.getForkLiftCertificate() << "\tbusy: " << employee.getBusy() << '\n';
    }
}