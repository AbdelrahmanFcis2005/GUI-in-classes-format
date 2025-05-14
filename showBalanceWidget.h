#pragma once
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class ShowBalanceWidget : public QWidget {

public:
    explicit ShowBalanceWidget(QWidget* parent = nullptr);
    void setBalance(double amount);
	void applyDarkMode(bool dark);

private:
    void updateBalanceFromInput();


private:
    QLabel* balanceLabel;
    QLineEdit* balanceInput;
    QPushButton* setBalanceButton;
	QLabel* titleLabel;
    double currentBalance = 0.0;
    double targetBalance = 0.0;
    QTimer* balanceAnimationTimer;
};