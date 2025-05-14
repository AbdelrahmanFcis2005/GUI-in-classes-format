#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>

class SendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SendWidget(QWidget* parent = nullptr);
    //void sendMoney(const QString& toUser, double amount);
	void applyDarkMode(bool dark);

private:
    QLineEdit* usernameInput;
	QLabel* titleLabel;
    QLineEdit* amountInput;
    QPushButton* sendButton;
	QLabel* statusLabel;

};
