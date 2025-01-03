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
		cout << "���� �뿩 �� �Դϴ�." << endl;
		return;
	}

	stock[title]--;
	cout << "�뿩 �Ϸ�" << endl;
}

void BorrowManager::returnBook(string title)
{
	if (stock[title] == MAX_STOCK)
	{
		cout << "�� �� ��� �뿩 ���� �ƴմϴ�.\n�ݳ��� ������ �����ϴ�." << endl;
		return;
	}

	stock[title]++;
	cout << "�ݳ� �Ϸ�" << endl;
}

void BorrowManager::displayStock()
{
	for (pair<string, int> p : stock)
	{  
		cout << "- " << p.first << " " << p.second << "��" << endl;
	}
}

void BorrowManager::displayStockWithVector(const vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << i+1 << ". " << books[i].title << " " << stock[books[i].title] << "��\n";
	}
}

void BorrowManager::displaySingleStock(string title)
{
	cout << "- " << title << " " << stock[title] << "��" << endl;
}
