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

private slots:
    void updateBalanceFromInput();

private:
    QLabel* balanceLabel;
    QLineEdit* balanceInput;
    QPushButton* setBalanceButton;
    double currentBalance = 0.0;
    double targetBalance = 0.0;
    QTimer* balanceAnimationTimer;
};