#include "MainWindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    loginPage = new LoginPageWidget;
    homePage = new HomePageWidget;
    signPage = new SignPageWidget;
    editProfilePage = new EditProfilePageWidget;

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(loginPage);
    pagesWidget->setCurrentWidget(loginPage);

    toggleModeButton = new QPushButton;
    toggleModeButton->setCheckable(true);
    toggleModeButton->setIcon(QIcon("media/light.svg"));
    toggleModeButton->setStyleSheet("background-color: white; border:none; padding:10px");
    toggleModeButton->setIconSize(QSize(30, 30));

    connect(toggleModeButton, &QPushButton::toggled, this, &MainWindow::toggleDarkMode);
    connect(loginPage->getLoginButton(), &QPushButton::clicked, this, &MainWindow::handleLogin);
    connect(loginPage->getSignButton(), &QPushButton::clicked, this, &MainWindow::handleSignIn);

    mainLayout = new QVBoxLayout;

    closeButton = new QPushButton("✕");
    minimizeButton = new QPushButton("—");
    maximizeButton = new QPushButton("▢");
    backButton = new QPushButton("←");

    QSize buttonSize(35, 35);
    QString buttonStyle = "QPushButton { border: none; background-color: transparent; font-size: 22px; padding:10px; }"
        "QPushButton:hover { background-color: #e0e0e0; }";

    closeButton->setFixedSize(buttonSize);
    minimizeButton->setFixedSize(buttonSize);
    maximizeButton->setFixedSize(buttonSize);
    backButton->setFixedSize(buttonSize);

    closeButton->setStyleSheet(buttonStyle + " QPushButton { color: white; background-color:red; }");
    minimizeButton->setStyleSheet(buttonStyle);
    maximizeButton->setStyleSheet(buttonStyle);
    backButton->setStyleSheet(buttonStyle + " QPushButton { color: black; font-weight:bold;  }");

    //backButton->hide(); // Hide by default on login page

    connect(closeButton, &QPushButton::clicked, this, &QMainWindow::close);
    connect(minimizeButton, &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(maximizeButton, &QPushButton::clicked, [this]() {
        if (isFullScreen()) {
            showNormal();
            resize(1280, 800);
            closeButton->hide();
            minimizeButton->hide();
            maximizeButton->hide();
        }
        else {
            showFullScreen();
            closeButton->show();
            minimizeButton->show();
            maximizeButton->show();
        }
        });
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goBack);

    windowControlsLayout = new QHBoxLayout;
    windowControlsLayout->addWidget(backButton);
	windowControlsLayout->addStretch();
    windowControlsLayout->addWidget(minimizeButton);
    windowControlsLayout->addWidget(maximizeButton);
    windowControlsLayout->addWidget(closeButton);
    windowControlsLayout->setContentsMargins(20, 0, 0, 10);

    windowControlsWidget = new QWidget;
    windowControlsWidget->setLayout(windowControlsLayout);
    windowControlsWidget->setFixedHeight(45);
    windowControlsWidget->setStyleSheet("background-color: white; padding:0px;");

    topBarLayout = new QHBoxLayout;
    topBarLayout->addWidget(toggleModeButton, 0, Qt::AlignHCenter);

    QWidget* topBarWidget = new QWidget;
    topBarWidget->setLayout(topBarLayout);

    mainLayout->addWidget(windowControlsWidget);
    mainLayout->addWidget(topBarWidget);
    mainLayout->addSpacing(5);
    mainLayout->addWidget(pagesWidget);
    mainLayout->addSpacing(80);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);

    setWindowIcon(QIcon("media/icon.png"));
    setWindowTitle("ASUPAY");

    showFullScreen();
    setStyleSheet("background-color: white;");
    updateBackButtonVisibility();
}

void MainWindow::goBack() {
    pagesWidget->setCurrentWidget(loginPage);
    updateBackButtonVisibility();
}

void MainWindow::updateBackButtonVisibility() {
    if (pagesWidget->currentWidget() == loginPage) {
        backButton->hide();
    }
    else {
        backButton->show();
    }
}

void MainWindow::handleLogin() {
    pagesWidget->addWidget(homePage);
    pagesWidget->setCurrentWidget(homePage);
    updateBackButtonVisibility();
}

void MainWindow::handleSignIn() {
	pagesWidget->addWidget(signPage);
    pagesWidget->setCurrentWidget(signPage);
    updateBackButtonVisibility();
}

void MainWindow::toggleDarkMode() {
    isDarkMode = !isDarkMode;

    windowControlsWidget->setStyleSheet(isDarkMode
        ? "background-color: #2c2c2c; padding:0px; border:none"
        : "background-color: white; padding:0px; border:none");


    toggleModeButton->setIcon(QIcon(isDarkMode ? "media/dark.svg" : "media/light.svg"));
    toggleModeButton->setStyleSheet(isDarkMode
        ? "background-color: #2c2c2c; padding:10px; border:none"
        : "background-color: white; padding:10px; border:none");
	setStyleSheet(isDarkMode
		? "background-color: #2c2c2c;"
		: "background-color: white;");

    loginPage->applyDarkMode(isDarkMode);
	signPage->applyDarkMode(isDarkMode);
    homePage->applyDarkMode(isDarkMode);
	editProfilePage->applyDarkMode(isDarkMode);
    
}
