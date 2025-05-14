#pragma once
#include "QWidget"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QFrame>
#include <QString>
#include <vector>
struct Transaction {
    QString sender;
    QString receiver;
    double amount;
    QString transtype;
    int transcount;
};
class ViewTransactions : public QWidget
{
public:
    explicit ViewTransactions(QWidget* parent = nullptr);
    //void setTransactions(const std::vector<Transaction>& transactions);
	void applyDarkMode(bool dark);
	
private:
    QVBoxLayout* mainLayout;
    QLabel* titleLabel;
    QLabel* noTransactionLabel;
    QWidget* transactionListWidget;
    QVBoxLayout* transactionListLayout;
};

