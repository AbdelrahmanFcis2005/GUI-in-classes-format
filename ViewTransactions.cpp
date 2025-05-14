#include "ViewTransactions.h"
ViewTransactions::ViewTransactions(QWidget* parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    titleLabel = new QLabel("Transaction History", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    mainLayout->addWidget(titleLabel);

    noTransactionLabel = new QLabel("You have not made any transactions yet.", this);
    noTransactionLabel->setAlignment(Qt::AlignCenter);
    noTransactionLabel->setStyleSheet("font-size: 16px; color: gray;");
    mainLayout->addWidget(noTransactionLabel);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    transactionListWidget = new QWidget(this);
    transactionListLayout = new QVBoxLayout(transactionListWidget);
    transactionListLayout->setAlignment(Qt::AlignTop);

    scrollArea->setWidget(transactionListWidget);
    mainLayout->addWidget(scrollArea);
}

//void ViewTransactions::setTransactions(const std::vector<Transaction>& transactions)
//{
    //// Clear previous
    //QLayoutItem* item;
    //while ((item = transactionListLayout->takeAt(0)) != nullptr) {
    //    delete item->widget();
    //    delete item;
    //}

    //if (transactions.empty()) {
    //    noTransactionLabel->show();
    //    return;
    //}

    //noTransactionLabel->hide();

    //for (const Transaction& t : transactions) {
    //    QString details = QString("From: %1\nTo: %2\nAmount: $%3\nType: %4\nID: %5")
    //        .arg(t.sender)
    //        .arg(t.receiver)
    //        .arg(t.amount, 0, 'f', 2)
    //        .arg(t.transtype)
    //        .arg(t.transcount);

    //    QLabel* transLabel = new QLabel(details);
    //    transLabel->setStyleSheet(
    //        "QLabel {"
    //        " background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
    //        " stop:0 #e0eafc, stop:1 #cfdef3);"
    //        " border-radius: 12px;"
    //        " padding: 12px;"
    //        " margin: 8px;"
    //        " font-size: 14px;"
    //        " }"
    //    );
    //    transactionListLayout->addWidget(transLabel);
    //}
//}

void ViewTransactions::applyDarkMode(bool dark)
{
	if (dark) {
		setStyleSheet("background-color: #2c2c2c;");
		titleLabel->setStyleSheet("color: white; font-size: 24px; font-weight: bold;");
		noTransactionLabel->setStyleSheet("color: #ccc; font-size: 16px;");
	}
	else {
		setStyleSheet("background-color: white;");
		titleLabel->setStyleSheet("color: black; font-size: 24px; font-weight: bold;");
		noTransactionLabel->setStyleSheet("color: gray; font-size: 16px;");
	}
}