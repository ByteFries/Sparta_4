#include "framework.h"
#include "BookManager.h"
#include "BorrowManager.h"
#include "Book.h"

#define BOOK_MANAGER BookManager::GetInstance()
#define BORROW_MANAGER BorrowManager::GetInstance()

void AddBook()
{
    string title, author;
    cout << "\n책 제목: ";
    cin.ignore();
    getline(cin, title);
    cout << "책 저자: ";
    getline(cin, author);
    BORROW_MANAGER->initializeStock(BOOK_MANAGER->addBook(title, author), 3);
}

void DisplayAll()
{
    BOOK_MANAGER->displayAllBooks();
}

void SearchBookByTitle()
{
    string title;
    cout << "\n도서명: ";
    cin.ignore();
    getline(cin, title);

    vector<Book> searchResult;
    BOOK_MANAGER->searchByTitle(title, searchResult);

    int size = searchResult.size();

    if (size == 0)
    {
        cout << "이름이 동일한 도서 목록이 없습니다." << endl;
        return;
    }

    cout << "이름이 동일한 도서 목록: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << searchResult[i].title << " by " << searchResult[i].author << endl;
    }
}

void SearchBookByAuthor()
{
    string author;
    cout << "\n저자명: ";
    cin.ignore();
    getline(cin, author);

    vector<Book> searchResult;
    BOOK_MANAGER->searchByAuthor(author, searchResult);

    int size = searchResult.size();

    if (size == 0)
    {
        cout << "해당 저자의 도서 목록이 없습니다." << endl;
        return;
    }

    cout << "- 해당 저자의 도서 목록 " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << searchResult[i].title << " by " << searchResult[i].author << "\n";
    }
}

Book SelectBook(const vector<Book>& books)
{
    int input;
    int size = books.size();

    while (true)
    {
        cin >> input;

        if (input > 0 && input <= size) break;
    }

    return books[input - 1];
}

void BorrowBook()
{
    int input;
    string sInput;

    vector<Book> results;
    while (true)
    {
        cout << "\n검색 방법\n1. 도서명\n2. 저자명\n선택: ";
        cin >> input;

        if (input == 1)
        {
            cout << "도서명: ";
            while (getline(cin, sInput))
            {
                if (sInput.empty()) continue;
                BOOK_MANAGER->searchByTitle(sInput, results);
                break;
            }
            break;
        }
        else if (input == 2)
        {
            cout << "저자명: ";
            while (getline(cin, sInput))
            { 
                if (sInput.empty()) continue;
                BOOK_MANAGER->searchByAuthor(sInput, results);
                break;
            }
            break;
        }
        else cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
    }

    int size = results.size();

    if (size == 0)
    {
        cout << "검색 결과와 일치한 도서가 없습니다." << endl;
        return;
    }

    cout << "- 검색 결과와 일치한 도서들\n";

    BORROW_MANAGER->displayStockWithVector(results);

    cout << "\n- 대여할 책의 번호를 입력하세요: ";
    
    BORROW_MANAGER->borrowBook(SelectBook(results).title);
}

void ReturnBook()
{
    cout << "\n반납할 도서명 : ";
    string title;
    vector<Book> results;
    while (getline(cin, title))
    {
        if (title.empty()) continue;
        
        BOOK_MANAGER->searchByTitle(title, results);
        
        if (results.empty())
        {
            cout << "해당 도서는 존재하지 않습니다.\n";
            continue;
        }

        break;
    }

    if (results.size() == 1)
    {
        BORROW_MANAGER->returnBook(title);
    }
    else
    {
        cout << "반납할 책 선택\n";
        BORROW_MANAGER->returnBook(SelectBook(results).title);
    }
}

int main() 
{
    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true)
    {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 책 이름으로 검색" << endl;
        cout << "4. 저자명으로 검색" << endl;
        cout << "5. 도서 대여" << endl;
        cout << "6. 도서 반납" << endl;
        cout << "7. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            AddBook();
        }
        else if (choice == 2)
        {
            DisplayAll();
        }
        else if (choice == 3)
        {
            SearchBookByTitle();
        }
        else if (choice == 4)
        {
            SearchBookByAuthor();
        }
        else if (choice == 5)
        {
            BorrowBook();
        }
        else if (choice == 6)
        {
            ReturnBook();
        }
        else if (choice == 7) 
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else 
        {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}