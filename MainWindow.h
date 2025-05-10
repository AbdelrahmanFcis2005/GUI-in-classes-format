#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "LoginPageWidget.h"
#include "SignPageWidget.h"
#include "EditProfilePageWidget.h"
#include "HomePageWidget.h"
#include <QSize>
#include <QIcon>

class MainWindow : public QMainWindow {

public:
    MainWindow(QWidget* parent = nullptr);
	QVBoxLayout* mainLayout= new QVBoxLayout;
    QWidget* central;
private:
    QHBoxLayout* windowControlsLayout;
    QWidget* windowControlsWidget;
	QPushButton* backButton;
	QHBoxLayout* topBarLayout;
    QStackedWidget* pagesWidget;
    LoginPageWidget* loginPage;
	SignPageWidget* signPage;
	EditProfilePageWidget* editProfilePage;
    HomePageWidget* homePage;
    QPushButton* toggleModeButton;
    QPushButton* closeButton;
    QPushButton* maximizeButton;   
    QPushButton* minimizeButton;
    bool isDarkMode = false;
	void goBack();
	void updateBackButtonVisibility();
    void handleLogin();
	void handleSignIn();
    void toggleDarkMode();
};