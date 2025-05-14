#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class RequestWidget : public QWidget
{

public:
    explicit RequestWidget(QWidget* parent = nullptr);
	void applyDarkMode(bool dark);
    void handleRequest();

private:
	QLabel* titleLabel;
    QLineEdit* usernameInput;
    QLineEdit* amountInput;
    QPushButton* requestButton;
    QLabel* statusLabel;
};