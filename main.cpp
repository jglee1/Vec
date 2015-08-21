#include <QCoreApplication>
#include <iostream>

using namespace std;

struct Entry {
    string name;
    int number;
};

template<typename T>
class Vec : public std::vector<T> {
public:
//    using vector<T>::vector;   // use the constructors from vector (under the name Vec)

    T& operator[](int i)        // range check
    { return vector<T>::at(i); }

    const T& operator[](int i) const    // range check const objects
    { return vector<T>::at(i); }

};

void silly(Vec<Entry>& book)
{
    int i = book[book.size()].number;   // book.size() is out of range
}

void checked(Vec<Entry>& book)
{
    try {
        book[book.size()].name = "Joe";
        book[book.size()].number = 99999;
          // will trhow an exception
        // ...
    }
    catch (out_of_range) {
        cerr<<"range error\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vec<Entry> book1;
    book1[0].name="Karl";
    book1[0].number=23456;

    checked(book1);
//    silly(book1);

    return a.exec();
}
