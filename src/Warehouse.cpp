#include "include/Warehouse.hpp"
#include "include/Shelf.hpp"

Warehouse::Warehouse() {}

//employee is added to the employees vector
void Warehouse::addEmployee(Employee employee) {
    this->employees.push_back(employee);
}

//shelf is added to the shelves vector
void Warehouse::addShelf(Shelf shelf) {
    this->shelves.push_back(shelf);
}

//shelves are rearranged in a descending manner based on itemcount
bool Warehouse::rearrangeShelf(Shelf& shelf) {
    //searching for employee to rearrange shelf
    for (Employee employee : this->employees) {
        if (employee.getBusy() == 0 || employee.getForkLiftCertificate() == 1) {
            employee.setBusy(1);

            //shelves are rearranged using the swapPallet function
            //selection sort algorithm is used to minimize the amount of swaps

            std::vector<int> palletContent; //stores the number of items in each pallet
            //nested loop over all shelves and all pallets in these shelves
            for (Shelf& otherShelf : this->shelves) {
                palletContent.clear();
                for (Pallet pallet : otherShelf.pallets) {
                    palletContent.push_back(pallet.getItemCount());
                }
                //pallet contents are compared based on size
                int i, j, max_idx;
                for (i = 0; i < palletContent.size() - 1; i++) {
                    max_idx = i;
                    for (j = i + 1; j < palletContent.size(); j++) {
                        if (palletContent[j] > palletContent[max_idx]) {
                            max_idx = j;
                        }
                    }
                    if (max_idx != i) {
                        //if suffices, pallets are swapped and the palletContent vector is updated
                        otherShelf.swapPallet(max_idx, i);
                        int temp = palletContent[max_idx];
                        palletContent[max_idx] = palletContent[i];
                        palletContent[i] = temp;
                    }
                }
            }
        }
        return true;
    }
    return false;
}


//if available, items with a matching name are picked from the shelves
bool Warehouse::pickItems(std::string itemName, int itemCount) {
    //checks for availability
    int itemsAvailable = 0;
    for (Shelf shelf : this->shelves) {
        for (Pallet pallet : shelf.pallets) {
            if(itemName == pallet.getItemName()){
                itemsAvailable += pallet.getItemCount();
            }
        }
    }
    //loops over all shelves and takes items using the takeOne function
    if (itemsAvailable >= itemCount) {
        for (Shelf shelf : this->shelves) {
            for (Pallet pallet : shelf.pallets) {
                if(pallet.getItemName() == itemName) {
                    while (pallet.getItemCount() > 0 && itemCount > 0) {
                        pallet.takeOne();
                        itemCount -= 1;
                    }
                }
            }
        }
        return true;
    }
    return false;
}