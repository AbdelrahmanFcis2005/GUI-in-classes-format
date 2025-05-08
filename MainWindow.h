#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "LoginPageWidget.h"
#include "SignPageWidget.h"
#include "EditProfilePageWidget.h"
#include "HomePageWidget.h"

class MainWindow : public QMainWindow {

public:
    MainWindow(QWidget* parent = nullptr);
	QVBoxLayout* mainLayout= new QVBoxLayout;
    QWidget* central;
private:
	QHBoxLayout* topBarLayout;
    QStackedWidget* pagesWidget;
    LoginPageWidget* loginPage;
	SignPageWidget* signPage;
	EditProfilePageWidget* editProfilePage;
    HomePageWidget* homePage;
    QPushButton* toggleModeButton;
    bool isDarkMode = false;
    void handleLogin();
	void handleSignIn();
    void toggleDarkMode();
};