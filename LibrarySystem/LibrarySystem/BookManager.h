#pragma once
class Book;

class BookManager : public Singleton<BookManager>
{
    friend class Singleton;

    BookManager() {}
    ~BookManager() = default;
public:
    Book addBook(const string& title, const string& author);
    void displayAllBooks() const;
    void searchByTitle(const string& title, vector<Book>& result);
    void searchByAuthor(const string& author, vector<Book>& result);
private:
    vector<Book> books;
};
