#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "LoginPageWidget.h"
#include "SignPageWidget.h"
#include "EditProfilePageWidget.h"
#include "HomePageWidget.h" 
#include "ShowBalanceWidget.h"
#include "RequestWidget.h"
#include "sendWidget.h"
#include "ViewTransactions.h"
#include "ShowProfilePage.h"
#include <QSize>
#include <QIcon>

class MainWindow : public QMainWindow {

public:
    MainWindow(QWidget* parent = nullptr);
	QVBoxLayout* mainLayout= new QVBoxLayout;
    QWidget* central;
    void toggleDarkMode();

private:
    QHBoxLayout* windowControlsLayout;
    QWidget* windowControlsWidget;
	QPushButton* backButton;
	QHBoxLayout* topBarLayout;
    QStackedWidget* pagesWidget;
    LoginPageWidget* loginPage;
	SignPageWidget* signPage;
    ShowBalanceWidget* showBalance;
	RequestWidget* requestPage;
	ShowProfilePage* showProfilePage;
	EditProfilePageWidget* editProfilePage;
    HomePageWidget* homePage;
	SendWidget* sendPage;
	ViewTransactions* viewTransactionsPage;
    QPushButton* toggleModeButton;
    QPushButton* closeButton;
    QPushButton* maximizeButton;   
    QPushButton* minimizeButton;
    bool isDarkMode = false;
	void goBack();
	void updateBackButtonVisibility();
    void showEditProfile();
    void showShowBalance();
    void showHome();
	void showSignUp();
	void showRequest();
	void showLoginPage();
	void showSendPage();
	void showTransactions();
	void showProfilePageWidget();
};