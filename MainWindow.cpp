#include "MainWindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    loginPage = new LoginPageWidget;
    homePage = new HomePageWidget;
    signPage = new SignPageWidget;
    editProfilePage = new EditProfilePageWidget;
    showBalance = new ShowBalanceWidget;
	requestPage = new RequestWidget;
	sendPage = new SendWidget;
	viewTransactionsPage = new ViewTransactions;
    showProfilePage = new ShowProfilePage;


    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(loginPage);
    pagesWidget->setCurrentWidget(loginPage);

    toggleModeButton = new QPushButton;
    toggleModeButton->setCheckable(true);
    toggleModeButton->setIcon(QIcon("media/light.svg"));
    toggleModeButton->setStyleSheet("background-color: white; border:none; padding:10px");
    toggleModeButton->setIconSize(QSize(30, 30));

    connect(toggleModeButton, &QPushButton::toggled, this, &MainWindow::toggleDarkMode);
    connect(loginPage->getLoginButton(), &QPushButton::clicked, this, &MainWindow::showHome);
    connect(loginPage->getSignButton(), &QPushButton::clicked, this, &MainWindow::showSignUp);
	connect(homePage->getProfileButton(), &QPushButton::clicked, this, &MainWindow::showProfilePageWidget);
	connect(showProfilePage->getEditProfileButton(), &QPushButton::clicked, this, &MainWindow::showEditProfile);
	connect(homePage->getBalanceButton(), &QPushButton::clicked, this, &MainWindow::showShowBalance);
	connect(homePage->getLogoutButton(), &QPushButton::clicked, this, &MainWindow::showLoginPage);
	connect(homePage->getViewTransactionsButton(), &QPushButton::clicked, this, &MainWindow::showTransactions);
	connect(homePage->getRequestButton(), &QPushButton::clicked, this, &MainWindow::showRequest);
	connect(homePage->getSendButton(), &QPushButton::clicked, this, &MainWindow::showSendPage);
	connect(signPage->getSignButton(), &QPushButton::clicked, this, &MainWindow::showHome);



    mainLayout = new QVBoxLayout;

    closeButton = new QPushButton(this);
	closeButton->setText("✕");
    minimizeButton = new QPushButton(this);
	minimizeButton->setText("–");
    maximizeButton = new QPushButton(this);
	maximizeButton->setText("❏");
    backButton = new QPushButton(this);
	backButton->setText("<-");

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

    windowControlsLayout = new QHBoxLayout(this);
    windowControlsLayout->addWidget(backButton);
	windowControlsLayout->addStretch();
    windowControlsLayout->addWidget(minimizeButton);
    windowControlsLayout->addWidget(maximizeButton);
    windowControlsLayout->addWidget(closeButton);
    windowControlsLayout->setContentsMargins(20, 0, 0, 10);

    windowControlsWidget = new QWidget(this);
    windowControlsWidget->setLayout(windowControlsLayout);
    windowControlsWidget->setFixedHeight(45);
    windowControlsWidget->setStyleSheet("background-color: white; padding:0px;");

    topBarLayout = new QHBoxLayout(this);
    topBarLayout->addWidget(toggleModeButton, 0, Qt::AlignHCenter);

    QWidget* topBarWidget = new QWidget(this);
    topBarWidget->setLayout(topBarLayout);

    mainLayout->addWidget(windowControlsWidget);
    mainLayout->addWidget(topBarWidget);
    mainLayout->addSpacing(5);
    mainLayout->addWidget(pagesWidget);
    mainLayout->addSpacing(80);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    central = new QWidget(this);
    central->setLayout(mainLayout);
    setCentralWidget(central);

    setWindowIcon(QIcon("media/icon.png"));
    setWindowTitle("ASUPAY");

    showFullScreen();
    setStyleSheet("background-color: white;");
    updateBackButtonVisibility();
}

void MainWindow::goBack() {
		pagesWidget->removeWidget(pagesWidget->currentWidget());
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

void MainWindow::showLoginPage() {
	pagesWidget->addWidget(loginPage);
	pagesWidget->setCurrentWidget(loginPage);
	updateBackButtonVisibility();
}

void MainWindow::showShowBalance() {
	pagesWidget->addWidget(showBalance);
	pagesWidget->setCurrentWidget(showBalance);
	updateBackButtonVisibility();
}

void MainWindow::showHome() {
    pagesWidget->addWidget(homePage);
    pagesWidget->setCurrentWidget(homePage);
    updateBackButtonVisibility();
}

void MainWindow::showSignUp() {
	pagesWidget->addWidget(signPage);
    pagesWidget->setCurrentWidget(signPage);
    updateBackButtonVisibility();
}

void MainWindow::showEditProfile() {
	pagesWidget->addWidget(editProfilePage);
	pagesWidget->setCurrentWidget(editProfilePage);
	updateBackButtonVisibility();
}

void MainWindow::showRequest() {
	pagesWidget->addWidget(requestPage);
	pagesWidget->setCurrentWidget(requestPage);
	updateBackButtonVisibility();
}

void MainWindow::showSendPage() {
	pagesWidget->addWidget(sendPage);
	pagesWidget->setCurrentWidget(sendPage);
	updateBackButtonVisibility();
}

void MainWindow::showTransactions() {
	pagesWidget->addWidget(viewTransactionsPage);
	pagesWidget->setCurrentWidget(viewTransactionsPage);
	updateBackButtonVisibility();
}

void MainWindow::showProfilePageWidget() {
	pagesWidget->addWidget(showProfilePage);
	pagesWidget->setCurrentWidget(showProfilePage);
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

	backButton->setStyleSheet(isDarkMode
		? "QPushButton { color: white; border: none; background-color: transparent; font-size: 22px; padding:10px; }"
        "QPushButton:hover { background-color: #e0e0e0; }"
		: "QPushButton { color: black; border: none; background-color: transparent; font-size: 22px; padding:10px; }"
        "QPushButton:hover { background-color: #e0e0e0; }");

    loginPage->applyDarkMode(isDarkMode);
	signPage->applyDarkMode(isDarkMode);
    homePage->applyDarkMode(isDarkMode);
	editProfilePage->applyDarkMode(isDarkMode);
	showBalance->applyDarkMode(isDarkMode);
	requestPage->applyDarkMode(isDarkMode);
	sendPage->applyDarkMode(isDarkMode);
    viewTransactionsPage->applyDarkMode(isDarkMode);
	showProfilePage->applyDarkMode(isDarkMode);
}
