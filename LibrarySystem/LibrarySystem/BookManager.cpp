#include "framework.h"
#include "BookManager.h"
#include "Book.h"

Book BookManager::addBook(const string& title, const string& author)
{
    Book book(title, author);
    books.push_back(book);
    cout << "\n책이 추가되었습니다: " << title << " by " << author << endl;
    return book;
}

void BookManager::displayAllBooks() const
{
    if (books.empty()) 
    {
        cout << "\n현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "\n현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) 
    {
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

void BookManager::searchByTitle(const string& title, vector<Book>& result)
{
    auto iter = books.begin();

    while ((iter = find_if(iter, books.end(), [&title](const Book& b){ return b.title == title;})) != books.end())
    {
        result.push_back(*iter);
        iter++;
    }
}

void BookManager::searchByAuthor(const string& author, vector<Book>& result)
{    
    auto iter = books.begin();

    while ((iter = find_if(iter, books.end(), [&author](const Book& b) { return b.author == author;})) != books.end())
    {
        result.push_back(*iter);
        iter++;
    }
}