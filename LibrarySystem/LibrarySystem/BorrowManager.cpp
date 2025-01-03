#include "framework.h"
#include "BorrowManager.h"
#include <unordered_map>
#include "Book.h"


void BorrowManager::initializeStock(Book book, int quantity)
{
	stock[book.title] = quantity;
}

void BorrowManager::borrowBook(string title)
{
	if (stock[title] == 0)
	{
		cout << "전부 대여 중 입니다." << endl;
		return;
	}

	stock[title]--;
	cout << "대여 완료" << endl;
}

void BorrowManager::returnBook(string title)
{
	if (stock[title] == MAX_STOCK)
	{
		cout << "전 권 모두 대여 중이 아닙니다.\n반납할 도서가 없습니다." << endl;
		return;
	}

	stock[title]++;
	cout << "반납 완료" << endl;
}

void BorrowManager::displayStock()
{
	for (pair<string, int> p : stock)
	{  
		cout << "- " << p.first << " " << p.second << "권" << endl;
	}
}

void BorrowManager::displayStockWithVector(const vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << i+1 << ". " << books[i].title << " " << stock[books[i].title] << "권\n";
	}
}

void BorrowManager::displaySingleStock(string title)
{
	cout << "- " << title << " " << stock[title] << "권" << endl;
}
