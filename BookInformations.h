// author, category, number of pages and status
#include <iostream>
using namespace std;

class BookInformations {
    public:
        string author;
        string category;
        int numOfPages;
        string status;
        BookInformations();
        BookInformations(string author, string category, int numOfPages, string status);
        BookInformations(const BookInformations& other);
        BookInformations& operator=(const BookInformations& other);
        friend ostream& operator<<(ostream& os, const BookInformations& emp);
};