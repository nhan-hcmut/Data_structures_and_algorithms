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
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
        */
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);

        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);

        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
        */
        this->title = new char[strlen(book.title) + 1];
        strcpy(this->title, book.title);

        this->authors = new char[strlen(book.authors) + 1];
        strcpy(this->authors, book.authors);

        this->publishingYear = book.getPublishingYear();
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
        */
        if (this->title != nullptr) delete[] this->title;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
        */
        if (this->authors != nullptr) delete[] this->authors;
        this->authors = new char[strlen(authors) + 1];
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
    friend bool checkAuthor(Book book, const char* author)
    {
        /*
         * STUDENT ANSWER
         * TODO: returns true if the author is on the book's authors list, otherwise it returns false
        */
        if (book.authors == nullptr || author == nullptr) return false;
        
        char* _authors = new char[strlen(book.authors) + 1];
        strcpy(_authors, book.authors);

        char* oneAuthor = strtok(_authors, ",");

        while (oneAuthor != nullptr) {

            if (oneAuthor[0] == ' ') oneAuthor++;

            char* last = oneAuthor + strlen(oneAuthor) - 1;

            while (last > oneAuthor && (*last) == ' ') last--;

            *(last+1) = '\0';

            if (strcmp(oneAuthor, author) == 0) {
                delete[] _authors;
                return true;
            }
            oneAuthor = strtok(nullptr, ",");
        }
        delete[] _authors;
        return false;
    }
    friend class Printer;
};

class Printer
{
public:
    static void printBook(const Book book)
    {
        /*
         * STUDENT ANSWER
        */
        cout << book.title << endl;

        char* tempAuthors = new char[strlen(book.authors) + 1];
        strcpy(tempAuthors, book.authors);
        char* oneAuthor = strtok(tempAuthors, ",");

        while (oneAuthor != nullptr) {
            if (oneAuthor[0] == ' ') oneAuthor++;
            cout << oneAuthor << endl;
            oneAuthor = strtok(nullptr, ",");
        }
        delete[] tempAuthors;
        cout << book.publishingYear;
    }
};

int main() {

    // Test 1
    Book book1("Giai tich 1", "Nguyen Dinh Huy, Nguyen Thi Xuan Anh", 2000);
    Printer::printBook(book1);
    cout << endl <<endl;
    /* Result:
    Giai tich 1
    Nguyen Dinh Huy
    Nguyen Thi Xuan Anh
    2000
    */

    // Test 2
    Book book2("Introduction to Algorithms", "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein", 1990);
    Printer::printBook(book2);
    
    /* Result:
    Introduction to Algorithms
    Thomas H. Cormen
    Charles E. Leiserson
    Ronald L. Rivest
    Clifford Stein
    1990
    */
    return 0;
}