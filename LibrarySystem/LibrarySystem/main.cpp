#include "framework.h"
#include "BookManager.h"
#include "BorrowManager.h"
#include "Book.h"

#define BOOK_MANAGER BookManager::GetInstance()
#define BORROW_MANAGER BorrowManager::GetInstance()

void AddBook()
{
    string title, author;
    cout << "\nå ����: ";
    cin.ignore();
    getline(cin, title);
    cout << "å ����: ";
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
    cout << "\n������: ";
    cin.ignore();
    getline(cin, title);

    vector<Book> searchResult;
    BOOK_MANAGER->searchByTitle(title, searchResult);

    int size = searchResult.size();

    if (size == 0)
    {
        cout << "�̸��� ������ ���� ����� �����ϴ�." << endl;
        return;
    }

    cout << "�̸��� ������ ���� ���: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << searchResult[i].title << " by " << searchResult[i].author << endl;
    }
}

void SearchBookByAuthor()
{
    string author;
    cout << "\n���ڸ�: ";
    cin.ignore();
    getline(cin, author);

    vector<Book> searchResult;
    BOOK_MANAGER->searchByAuthor(author, searchResult);

    int size = searchResult.size();

    if (size == 0)
    {
        cout << "�ش� ������ ���� ����� �����ϴ�." << endl;
        return;
    }

    cout << "- �ش� ������ ���� ��� " << endl;
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
        cout << "\n�˻� ���\n1. ������\n2. ���ڸ�\n����: ";
        cin >> input;

        if (input == 1)
        {
            cout << "������: ";
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
            cout << "���ڸ�: ";
            while (getline(cin, sInput))
            { 
                if (sInput.empty()) continue;
                BOOK_MANAGER->searchByAuthor(sInput, results);
                break;
            }
            break;
        }
        else cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
    }

    int size = results.size();

    if (size == 0)
    {
        cout << "�˻� ����� ��ġ�� ������ �����ϴ�." << endl;
        return;
    }

    cout << "- �˻� ����� ��ġ�� ������\n";

    BORROW_MANAGER->displayStockWithVector(results);

    cout << "\n- �뿩�� å�� ��ȣ�� �Է��ϼ���: ";
    
    BORROW_MANAGER->borrowBook(SelectBook(results).title);
}

void ReturnBook()
{
    cout << "\n�ݳ��� ������ : ";
    string title;
    vector<Book> results;
    while (getline(cin, title))
    {
        if (title.empty()) continue;
        
        BOOK_MANAGER->searchByTitle(title, results);
        
        if (results.empty())
        {
            cout << "�ش� ������ �������� �ʽ��ϴ�.\n";
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
        cout << "�ݳ��� å ����\n";
        BORROW_MANAGER->returnBook(SelectBook(results).title);
    }
}

int main() 
{
    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true)
    {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ���" << endl;
        cout << "3. å �̸����� �˻�" << endl;
        cout << "4. ���ڸ����� �˻�" << endl;
        cout << "5. ���� �뿩" << endl;
        cout << "6. ���� �ݳ�" << endl;
        cout << "7. ����" << endl;
        cout << "����: ";

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
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else 
        {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}