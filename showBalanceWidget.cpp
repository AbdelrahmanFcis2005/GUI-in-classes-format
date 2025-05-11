#include "ShowBalanceWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QDebug>
#include <cmath>

ShowBalanceWidget::ShowBalanceWidget(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Current Balance");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    balanceLabel = new QLabel("$ 0.00");
    balanceLabel->setAlignment(Qt::AlignCenter);
    balanceLabel->setFixedSize(300, 80);
    balanceLabel->setStyleSheet(
        "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #4facfe, stop:1 #00f2fe);"
        "border-radius: 20px;"
        "font-size: 30px;"
        "font-weight: bold;"
        "color: white;"
        "padding: 15px;"
    );

    balanceInput = new QLineEdit;
    balanceInput->setPlaceholderText("Enter new balance...");
    balanceInput->setFixedWidth(200);
    balanceInput->setAlignment(Qt::AlignCenter);
    balanceInput->setStyleSheet(
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

    setBalanceButton = new QPushButton("Set Balance");
    setBalanceButton->setStyleSheet(
        "QPushButton {"
        "  font-size: 16px;"
        "  padding: 8px 16px;"
        "  border: none;"
        "  border-radius: 10px;"
        "  color: white;"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #667eea, stop:1 #764ba2);"
        "}"
        "QPushButton:hover {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #5a67d8, stop:1 #6b46c1);"
        "}"
    );

    connect(setBalanceButton, &QPushButton::clicked, this, &ShowBalanceWidget::updateBalanceFromInput);

    QHBoxLayout* inputLayout = new QHBoxLayout;
    inputLayout->addStretch();
    inputLayout->addWidget(balanceInput);
    inputLayout->addSpacing(10);
    inputLayout->addWidget(setBalanceButton);
    inputLayout->addStretch();

    layout->addSpacing(40);
    layout->addWidget(titleLabel);
    layout->addSpacing(20);
    layout->addWidget(balanceLabel, 0, Qt::AlignCenter);
    layout->addSpacing(30);
    layout->addLayout(inputLayout);
    layout->addStretch();

    // Timer setup
    balanceAnimationTimer = new QTimer(this);
    balanceAnimationTimer->setInterval(15); // ~60 fps
    connect(balanceAnimationTimer, &QTimer::timeout, [=]() {
        double diff = targetBalance - currentBalance;
        if (std::abs(diff) < 0.01) {
            currentBalance = targetBalance;
            balanceLabel->setText(QString("$ %1").arg(currentBalance, 0, 'f', 2));
            balanceAnimationTimer->stop();
            return;
        }
        currentBalance += diff * 0.1; // ease animation
        balanceLabel->setText(QString("$ %1").arg(currentBalance, 0, 'f', 2));
        });
}

void ShowBalanceWidget::setBalance(double amount) {
    targetBalance = amount;
    balanceAnimationTimer->start();
}

void ShowBalanceWidget::updateBalanceFromInput() {
    bool ok;
    double value = balanceInput->text().toDouble(&ok);
    if (ok) {
        setBalance(value);
    }
    else {
        balanceLabel->setText("Invalid input!");
    }
}
