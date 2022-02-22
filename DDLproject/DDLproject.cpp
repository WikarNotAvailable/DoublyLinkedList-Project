#include <iostream>
#include "DoublyLinkedList.h"
#include "functions.h"
#include "Library.h"
using namespace std;
int main(int argc, char* argv[])
{

    string input1 = "";
    string input2 = "";
    string input3 = "";
    string output = "";

    if (load_arguments(argc, argv, input1, input2, input3, output)) {

        Library my_library{ input1,input2,input3 }; // creating library which contains 3 lists filled with objected created with information from text files
        // the constructor tested push_back and push_front functions (front for people list and back for the other lists)

        my_library.print_library(); // showing content of lists
        my_library.size_library(); // size of each list before popping

        my_library.erase_in_library(2); // erasing third item in each list
        my_library.pop_front_library(); // popping front from each list
        my_library.pop_back_library(); // popping back from each list

        cout << "AFTER POPPING AND ERASING THE 3RD ITEM IN EACH LIST" << endl;
        cout << endl;
        my_library.print_library(); // showing content of lists after popping front and back
        my_library.size_library(); // size of each list after popping

        cout << "AFTER SORTING IN DESCENDING ORDER" << endl;
        cout << endl;
        my_library.sort_library(); // sorting each list using function sort implemented in the list class
        my_library.print_library();

        cout << "AFTER SORTING IN ASCENDING ORDER" << endl;
        cout << endl;
        my_library.reverse_sort_library(); // sorting each list using reversed order using function reverse sort implemented in the list class
        my_library.print_library();

        my_library.make_output_file(output); // making an output file out of all data stored in library

        cout << "TESTING OPERATORS" << endl;
        cout << "using copying operator on booklist and move operators on borrowinglist and peoplelist" << endl;

        DoublyLinkedList<Book> booklist{};
        DoublyLinkedList<Borrowing>  borrowinglist{};
        DoublyLinkedList<Person> peoplelist{};
        my_library.test_operators(booklist, borrowinglist, peoplelist); // using copying operator on booklist and move operators on borrowinglist and peoplelist

        cout << "My library after using copying and moving operators on new lists using content of lists in library:" << endl;
        cout << endl;
        my_library.print_library();

        cout << "New lists that should be filled with objects of the library:" << endl;
        cout << endl;
        booklist.print();
        cout << endl;
        borrowinglist.print();
        cout << endl;
        peoplelist.print();
        cout << endl;

        cout << "TESTING CONSTRUCTORS: " << endl;
        cout << "using copying constructor of booklist and move constructor of borrowinglist and peoplelist" << endl;

        DoublyLinkedList<Book> booklist2{ booklist }; //copying
        DoublyLinkedList<Borrowing>  borrowinglist2(move(borrowinglist)); //moving
        DoublyLinkedList<Person> peoplelist2(move(peoplelist)); //moving

        cout << "Previous lists:" << endl;
        cout << endl;
        booklist.print();
        borrowinglist.print();
        peoplelist.print();


        cout << "New lists:" << endl;
        cout << endl;
        booklist2.print();
        cout << endl;
        borrowinglist2.print();
        cout << endl;
        peoplelist2.print();
        cout << endl;

        cout << "CHECKING IF BINARY SERIALIZATION AND DESERIALIZATION DO WORK" << endl;
        cout << "New list should have the content of the previous booklist" << endl;

        booklist.save_binary("binbooklist.bin"); //new binary file based on booklist list will be created 
        DoublyLinkedList<Book> booklist3{};
        booklist3.read_binary("binbooklist.bin"); //new list will be filled of objects taken from binary file created in the save_binary function's invoke
        cout << endl;
        booklist3.print();

        cout << "CHECKING IF SEARCHING IMPLEMENTED IN THE LIST WORKS" << endl;
        cout << endl;

        int ID = 10;
        string title = "Droga";
        string author = "Cormac_McCarthy";
        int year_of_release = 2006;
        int number_of_pages = 408;
        string type = "Powiesc";

        Book book_to_search{ ID,title,author,year_of_release,number_of_pages,type }; //creating object of Book class
        cout << "Our searched book has index: (should be 1 ) " << booklist2.search(book_to_search) << endl;

        string PESEL = "09321939199";
        int IDb = 2;
        string surname = "Rybalski";
        string date_l = "5.02.2021";
        string date_r = "10.02.2021";

        Borrowing borrowing_to_search{ PESEL, IDb, surname, date_l, date_r }; //creating object of Borrowing class
        cout << "Our searched borrowing has index: (should be 1) " << borrowinglist2.search(borrowing_to_search) << endl;

        string PESELp = "12390321991";
        string name = "Anna";
        string surnamep = "Barela";
        string date_of_birth = "29.03.2002";
        string street = "Gryfia";
        string number_of_flat = "16";
        string city = "Sosnowiec";

        Person person_to_search{ PESELp, name, surnamep, date_of_birth, street, number_of_flat, city }; //creating object of Person class
        cout << "Our searched person has index: (should be 1) " << peoplelist2.search(person_to_search) << endl;
    }
    return 0;
}
