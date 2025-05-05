#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    loginPage = new LoginPageWidget;
    homePage = new HomePageWidget;

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(loginPage);
    pagesWidget->addWidget(homePage);
    pagesWidget->setCurrentWidget(loginPage);

    toggleModeButton = new QPushButton;
    toggleModeButton->setCheckable(true);
    toggleModeButton->setIcon(QIcon("media/light.svg"));
    toggleModeButton->setStyleSheet("background-color: white; border:none; padding:10px");
    toggleModeButton->setIconSize(QSize(25, 25));

    connect(toggleModeButton, &QPushButton::toggled, this, &MainWindow::toggleDarkMode);
    connect(loginPage->getLoginButton(), &QPushButton::clicked, this, &MainWindow::handleLogin);

    QHBoxLayout* topBarLayout = new QHBoxLayout;
    topBarLayout->addWidget(toggleModeButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topBarLayout, Qt::AlignHCenter);
    mainLayout->addWidget(pagesWidget);
	mainLayout->addSpacing(30);
    QWidget* central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);
	setWindowIcon(QIcon("media/icon.png"));
	setWindowTitle("ASUPAL");
    showFullScreen();
	setStyleSheet("background-color: white;");


}

void MainWindow::handleLogin() {
    pagesWidget->setCurrentWidget(homePage);

  }

void MainWindow::toggleDarkMode() {
    isDarkMode = !isDarkMode;

    // Update toggle button
    toggleModeButton->setIcon(QIcon(isDarkMode ? "media/dark.svg" : "media/light.svg"));
    toggleModeButton->setStyleSheet(isDarkMode
        ? "background-color: #2c2c2c; padding:10px; border:none"
        : "background-color: white; padding:10px; border:none");
	// Update main window style
	setStyleSheet(isDarkMode
		? "background-color: #2c2c2c;"
		: "background-color: white;");

    // Propagate dark mode change
    loginPage->applyDarkMode(isDarkMode);
    homePage->applyDarkMode(isDarkMode);
}
