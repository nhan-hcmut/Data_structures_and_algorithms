#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
        */
        this->title = this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
        */
        this->title = new char[sizeof(title)];
        strcpy(this->title, title);

        this->authors = new char[sizeof(authors)];
        strcpy(this->authors, authors);

        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
        */
        this->title = new char[sizeof(book.getTitle())];
        strcpy(this->title, book.getTitle());

        this->authors = new char[sizeof(book.getAuthors())];
        strcpy(this->authors, book.getAuthors());

        this->publishingYear = book.getPublishingYear();
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
        */
        this->title = new char[sizeof(title)];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
        */
        this->authors = new char[sizeof(authors)];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
        */
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
        */
        return this->title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
        */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
        */
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
        */
        delete[] this->title;
        delete[] this->authors;

        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main() {

    // Test 1
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    book1.printBook();
    // Result:
    // Giai tich 1
    // Nguyen Dinh Huy
    // 2000

    /* Test 2
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    Book book2 = book1;
    book2.printBook();
    // Result:
    // Giai tich 1
    // Nguyen Dinh Huy
    // 2000
    */
    
    return 0;
}
