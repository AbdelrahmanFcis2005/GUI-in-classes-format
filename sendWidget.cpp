#include "sendWidget.h"

SendWidget::SendWidget(QWidget* parent)
	: QWidget(parent)
{
	QVBoxLayout* layout = new QVBoxLayout(this);

	titleLabel = new QLabel(this);
	titleLabel->setText("Request Money");
	titleLabel->setAlignment(Qt::AlignCenter);
	titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

	usernameInput = new QLineEdit(this);
	usernameInput->setPlaceholderText("Recipient's Username");
	usernameInput->setFixedWidth(250);
	usernameInput->setAlignment(Qt::AlignCenter);
	usernameInput->setStyleSheet(
		"QLineEdit {"
		"  font-size: 16px;"
		"  padding: 8px;"
		"  border: 2px solid #ccc;"
		"  border-radius: 10px;"
		"}"
		"QLineEdit:focus {"
		"  border-color: #7abaff;"
		"}"
	);

	amountInput = new QLineEdit(this);
	amountInput->setPlaceholderText("Amount");
	amountInput->setFixedWidth(250);
	amountInput->setAlignment(Qt::AlignCenter);
	amountInput->setStyleSheet(
		"QLineEdit {"
		"  font-size: 16px;"
		"  padding: 8px;"
		"  border: 2px solid #ccc;"
		"  border-radius: 10px;"
		"}"
		"QLineEdit:focus {"
		"  border-color: #7abaff;"
		"}"
	);

	sendButton = new QPushButton(this);
	sendButton->setText("Send");
	sendButton->setStyleSheet(
		"QPushButton {"
		"  font-size: 16px;"
		"  padding: 8px 16px;"
		"  border: none;"
		"  border-radius: 10px;"
		"  color: white;"
		"  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #74ebd5, stop:1 #9face6);"
		"}"
		"QPushButton:hover {"
		"  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f68000, stop:1 #ffcc00);"
		"}"
	);


	statusLabel = new QLabel(this);
	statusLabel->setText("");
	statusLabel->setAlignment(Qt::AlignCenter);
	statusLabel->setStyleSheet("font-size: 14px; color: green;");

	layout->addSpacing(30);
	layout->addWidget(titleLabel);
	layout->addSpacing(20);
	layout->addWidget(usernameInput, 0, Qt::AlignCenter);
	layout->addSpacing(10);
	layout->addWidget(amountInput, 0, Qt::AlignCenter);
	layout->addSpacing(20);
	layout->addWidget(sendButton, 0, Qt::AlignCenter);
	layout->addSpacing(10);
	layout->addWidget(statusLabel);
	layout->addStretch();
}

//void SendWidget::sendMoney(const QString& toUser, double amount) {
//	// Implement the logic to send money here
//	qDebug() << "Sending" << amount << "to" << toUser;
//}

void SendWidget::applyDarkMode(bool dark)
{
	if (dark) {
		setStyleSheet("background-color: #2c2c2c;");
		titleLabel->setStyleSheet("color: white; font-size: 24px; font-weight: bold;");
		usernameInput->setStyleSheet(
			"QLineEdit {"
			"  font-size: 16px;"
			"  padding: 8px;"
			"  border: 2px solid #ccc;"
			"  border-radius: 10px;"
			"color: white; "
			"}"
			"QLineEdit:focus {"
			"  border-color: #7abaff;"
			"}"
		);
		amountInput->setStyleSheet(
			"QLineEdit {"
			"  font-size: 16px;"
			"  padding: 8px;"
			"  border: 2px solid #ccc;"
			"  border-radius: 10px;"
			"color: white; "
			"}"
			"QLineEdit:focus {"
			"  border-color: #7abaff;"
			"}"
		);
		sendButton->setStyleSheet(
			"QPushButton {"
			"  font-size: 16px;"
			"  padding: 8px 16px;"
			"  border: none;"
			"  border-radius: 10px;"
			"  color: white;"
			"  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #74ebd5, stop:1 #9face6);"
			"}"
			"QPushButton:hover {"
			"  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f68000, stop:1 #ffcc00);"
			"}"
		);
	}
	else {
		setStyleSheet("background-color: white;");
		titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: black;");
		usernameInput->setStyleSheet(
			"QLineEdit {"
			"  font-size: 16px;"
			"  padding: 8px;"
			"  border: 2px solid #ccc;"
			"  border-radius: 10px;"
			"}"
			"QLineEdit:focus {"
			"  border-color: #7abaff;"
			"}"
		);
		amountInput->setStyleSheet(
			"QLineEdit {"
			"  font-size: 16px;"
			"  padding: 8px;"
			"  border: 2px solid #ccc;"
			"  border-radius: 10px;"
			"}"
			"QLineEdit:focus {"
			"  border-color: #7abaff;"
			"}"
		);
		sendButton->setStyleSheet(
			"QPushButton {"
			"  font-size: 16px;"
			"  padding: 8px 16px;"
			"  border: none;"
			"  border-radius: 10px;"
			"  color: #2c2c2c;"
			"  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #74ebd5, stop:1 #9face6);"
			"}"
			"QPushButton:hover {"
			"  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f68000, stop:1 #ffcc00);"
			"}"
		);

	}
}