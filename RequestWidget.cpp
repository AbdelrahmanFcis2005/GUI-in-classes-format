#include "RequestWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

RequestWidget::RequestWidget(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    titleLabel = new QLabel(this);
	titleLabel->setText("Request Money");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Sender's Username");
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

    requestButton = new QPushButton(this);
	requestButton->setText("Request");
    requestButton->setStyleSheet(
        "QPushButton {"
        "  font-size: 16px;"
        "  padding: 8px 16px;"
        "  border: none;"
        "  border-radius: 10px;"
        "  color: white;"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f7971e, stop:1 #ffd200);"
        "}"
        "QPushButton:hover {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f68000, stop:1 #ffcc00);"
        "}"
    );

    connect(requestButton, &QPushButton::clicked, this, &RequestWidget::handleRequest);

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
    layout->addWidget(requestButton, 0, Qt::AlignCenter);
    layout->addSpacing(10);
    layout->addWidget(statusLabel);
    layout->addStretch();
}

void RequestWidget::handleRequest()
{
    QString username = usernameInput->text().trimmed();
    bool ok;
    double amount = amountInput->text().toDouble(&ok);

    if (username.isEmpty() || !ok || amount <= 0) {
        statusLabel->setText("Invalid username or amount.");
        statusLabel->setStyleSheet("color: red; font-size: 14px;");
        return;
    }

}

void RequestWidget::applyDarkMode(bool dark)
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
            "  border-color: #444;"
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
        "  border-color: #444;"
        "}"
    );
statusLabel->setStyleSheet("color: #0078D7;");
	}
	else {
		setStyleSheet("background-color: white;");
		titleLabel->setStyleSheet("color: black; font-size: 24px; font-weight: bold;");
        usernameInput->setStyleSheet(
            "QLineEdit {"
            "  font-size: 16px;"
            "  padding: 8px;"
            "  border: 2px solid #ccc;"
            "  border-radius: 10px;"
			"  color: black;"
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
			"  color: black;"
            "}"
            "QLineEdit:focus {"
            "  border-color: #7abaff;"
            "}"
        );
        statusLabel->setStyleSheet("color: green;");
	}
}