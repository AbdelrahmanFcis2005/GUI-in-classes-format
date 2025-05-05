#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "LoginPageWidget.h"
#include "HomePageWidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    QVBoxLayout* mainLayout;
private:
    QStackedWidget* pagesWidget;
    LoginPageWidget* loginPage;
    HomePageWidget* homePage;
    QPushButton* toggleModeButton;
    bool isDarkMode = false;

private slots:
    void handleLogin();
    void toggleDarkMode();
};