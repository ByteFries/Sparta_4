#pragma once
#include <unordered_map>
class Book;
#define MAX_STOCK 3
class BorrowManager : public Singleton<BorrowManager>
{
	friend class Singleton;
public:
	BorrowManager() = default;
	~BorrowManager() = default;

	void initializeStock(Book book, int quantity = MAX_STOCK);
	void borrowBook(string title);
	void returnBook(string title);
	void displayStock();
	void displayStockWithVector(const vector<Book>& books);
	void displaySingleStock(string title);
private:
	unordered_map<string, int> stock;
};