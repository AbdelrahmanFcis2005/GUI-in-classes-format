#pragma once
#include "QWidget"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>

class ShowProfilePage : public QWidget {

public:
    explicit ShowProfilePage(QWidget* parent = nullptr);
    
    QPushButton* getEditProfileButton() const;
    void applyDarkMode(bool isDarkMode);

private:
    QVBoxLayout* mainLayout;
	QPushButton* logoButton;
	QLabel* emailLabel;
    QLabel* emailLabel1;
    QLabel* passwordLabel;
    QLabel* passwordLabel1;
    QLabel* fullNameLabel;
    QLabel* fullNameLabel1;
    QLabel* usernameLabel;
    QLabel* usernameLabel1;
    QLabel* balanceLabel;
    QLabel* balanceLabel1;

    QPushButton* editProfileButton;
};


