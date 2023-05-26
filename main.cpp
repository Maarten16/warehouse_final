#include <iostream>
#include <functional>
#include "src/include/Employee.hpp"
#include "src/include/Shelf.hpp"
#include "src/include/Warehouse.hpp"
#include "src/include/instructions.hpp"


int main() {

    Warehouse warehouse1 = Warehouse();
    Warehouse warehouse2 = Warehouse();

    Pallet pallet1 = Pallet("books", 100, 20);
    Pallet pallet2 = Pallet("pencils", 100, 40);
    Pallet pallet3 = Pallet("markers", 100, 30);
    Pallet pallet4 = Pallet("books", 100, 10);

    Pallet pallet5 = Pallet("books", 100, 20);
    Pallet pallet6 = Pallet("pencils", 100, 40);
    Pallet pallet7 = Pallet("markers", 100, 30);
    Pallet pallet8 = Pallet("rulers", 100, 10);

    Pallet pallet9 = Pallet("books", 100, 20);
    Pallet pallet10 = Pallet("pencils", 100, 40);
    Pallet pallet11 = Pallet("markers", 100, 30);
    Pallet pallet12 = Pallet("books", 100, 10);

    Shelf shelf2 = Shelf();
    Shelf shelf3 = Shelf();
    Shelf shelf4 = Shelf();

    Employee employee1 = Employee("John", true);
    Employee employee2 = Employee("Jane", false);
    Employee employee3 = Employee("Jack", true);
    Employee employee4 = Employee("Jill", false);
    Employee employee5 = Employee("James", false);
    Employee employee6 = Employee("Jenny", false);
    Employee employee7 = Employee("Jasper", true);
    Employee employee8 = Employee("Jade", true);

    shelf2.pallets = {pallet1, pallet2, pallet3, pallet4};
    shelf3.pallets = {pallet5, pallet6, pallet7, pallet8};
    shelf4.pallets = {pallet9, pallet10, pallet11, pallet12};

    warehouse1.addShelf(shelf2);
    warehouse1.addShelf(shelf3);
    warehouse2.addShelf(shelf4);

    warehouse1.addEmployee(employee1);
    warehouse1.addEmployee(employee2);
    warehouse1.addEmployee(employee3);
    warehouse1.addEmployee(employee4);
    warehouse2.addEmployee(employee5);
    warehouse2.addEmployee(employee6);
    warehouse2.addEmployee(employee7);
    warehouse2.addEmployee(employee8);

    printEmployees(warehouse1);
    std::cout << "\n\n";
    printEmployees(warehouse2);
    std::cout << "\n\n";

    employee1.setForkLiftCertificate(0);
    employee2.setForkLiftCertificate(0);
    employee3.setForkLiftCertificate(1);
    employee4.setForkLiftCertificate(1);
    employee5.setForkLiftCertificate(0);
    employee6.setForkLiftCertificate(0);
    employee7.setForkLiftCertificate(1);
    employee8.setForkLiftCertificate(1);

    employee1.setBusy(true);
    employee2.setBusy(false);
    employee3.setBusy(true);
    employee4.setBusy(false);
    employee5.setBusy(true);
    employee6.setBusy(false);
    employee7.setBusy(true);
    employee8.setBusy(false);

    printEmployees(warehouse1);
    std::cout << "\n\n";
    printEmployees(warehouse2);
    std::cout << "\n\n";

    printItems(warehouse1);
    std::cout << "\n\n";
    printItems(warehouse2);
    std::cout << "\n\n";

    warehouse1.rearrangeShelf(shelf2);
    warehouse1.rearrangeShelf(shelf3);
    warehouse2.rearrangeShelf(shelf4);

    printItems(warehouse1);
    std::cout << "\n\n";
    printItems(warehouse2);
    std::cout << "\n\n";

    std::cout << warehouse1.pickItems("books", 10) << "\n";
    std::cout << warehouse1.pickItems("books", 10000) << "\n";
    std::cout << warehouse1.pickItems("pencils", 10) << "\n";
    std::cout << warehouse1.pickItems("pencils", 10000) << "\n";

    std::cout << "\n";

    std::cout << warehouse2.shelves[0].pallets[0].getItemName() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].getItemCount() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].getRemainingSpace() << "\n";
    std::cout << warehouse1.shelves[1].pallets[1].getItemName() << "\n";
    std::cout << warehouse1.shelves[1].pallets[1].getItemCount() << "\n";
    std::cout << warehouse1.shelves[1].pallets[1].getRemainingSpace() << "\n";

    std::cout << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].getItemCount() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].takeOne() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].takeOne() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].getItemCount() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].putOne() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].putOne() << "\n";
    std::cout << warehouse2.shelves[0].pallets[0].getItemCount() << "\n";

    std::cout << warehouse1.shelves[0].pallets[0].getItemName() << "\n";
    std::cout << warehouse1.shelves[0].pallets[1].getItemName() << "\n";
    warehouse1.shelves[0].swapPallet(0,1);
    std::cout << warehouse1.shelves[0].pallets[0].getItemName() << "\n";
    std::cout << warehouse1.shelves[0].pallets[1].getItemName() << "\n";





}
