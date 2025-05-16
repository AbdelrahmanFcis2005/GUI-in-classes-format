#include "ShowProfilePage.h"

ShowProfilePage::ShowProfilePage(QWidget* parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    mainLayout->setSpacing(15);

    logoButton = new QPushButton(this);
    logoButton->setIcon(QIcon("media/profile.svg"));
    logoButton->setStyleSheet("border:none; padding:0px");
    logoButton->setIconSize(QSize(90, 90));
	mainLayout->addWidget(logoButton, 0, Qt::AlignHCenter);

	emailLabel1 = new QLabel("Email", this);
	emailLabel1->setStyleSheet("font-size: 15px; color: black; padding:0px;");
    emailLabel = new QLabel(this);
	passwordLabel1 = new QLabel("Password", this);
	passwordLabel1->setStyleSheet("font-size: 15px; color: black; padding:0px;");
    passwordLabel = new QLabel(this);
	fullNameLabel1 = new QLabel("Full Name", this);
	fullNameLabel1->setStyleSheet("font-size: 15px; color: black; padding:0px;");
    fullNameLabel = new QLabel(this);
	usernameLabel1 = new QLabel("Username", this);
	usernameLabel1->setStyleSheet("font-size: 15px; color: black; padding:0px;");
    usernameLabel = new QLabel(this);
	balanceLabel1 = new QLabel("Balance", this);
	balanceLabel1->setStyleSheet("font-size: 15px; color: black; padding:0px;");
    balanceLabel = new QLabel(this);

    
    QList<QLabel*> labels = { fullNameLabel, usernameLabel, emailLabel, passwordLabel, balanceLabel };
    for (QLabel* label : labels) {
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(
            "QLabel {"
            "  font-size: 18px;"
            "  padding: 8px 20px;"
            "  border: 2px solid #ccc;"
            "  border-radius: 12px;"
            "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #f0f0f0, stop:1 #dcdcdc);"
            "  min-width: 300px;"
            "}"
        );
		if (label == emailLabel) {
			mainLayout->addWidget(emailLabel1, 0, Qt::AlignHCenter);
		}
		else if (label == passwordLabel) {
			mainLayout->addWidget(passwordLabel1, 0, Qt::AlignHCenter);
		}
		else if (label == fullNameLabel) {
			mainLayout->addWidget(fullNameLabel1, 0, Qt::AlignHCenter);
		}
		else if (label == usernameLabel) {
			mainLayout->addWidget(usernameLabel1, 0, Qt::AlignHCenter);
		}
		else if (label == balanceLabel) {
			mainLayout->addWidget(balanceLabel1, 0, Qt::AlignHCenter);
		}
        mainLayout->addWidget(label);
    }

    editProfileButton = new QPushButton("Edit Profile", this);
    editProfileButton->setFixedWidth(200);
    editProfileButton->setStyleSheet(
        "QPushButton {"
        "  font-size: 16px;"
        "  padding: 10px 20px;"
        "  border-radius: 10px;"
        "  color: white;"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #6a11cb, stop:1 #2575fc);"
        "}"
        "QPushButton:hover {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #5b0eaf, stop:1 #1e60d4);"
        "}"
    );

    mainLayout->addSpacing(10);
    mainLayout->addWidget(editProfileButton, 0, Qt::AlignCenter);
}

QPushButton* ShowProfilePage::getEditProfileButton() const
{
    return editProfileButton;
}

void ShowProfilePage::applyDarkMode(bool isDarkMode)
{
    if (isDarkMode) {
        setStyleSheet("background-color: #2c2c2c;");
		for (QLabel* label : { emailLabel, passwordLabel, fullNameLabel, usernameLabel, balanceLabel }) {
			label->setStyleSheet(
				"QLabel {"
				"  font-size: 18px;"
				"  padding: 8px 20px;"
				"  border: 2px solid #0078D7;"
				"  border-radius: 12px;"
				"  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #3a3a3a, stop:1 #4a4a4a);"
				"  min-width: 300px;"
				"}"
			);
		}

		for (QLabel* label : { emailLabel1, passwordLabel1, fullNameLabel1, usernameLabel1, balanceLabel1 }) {
			label->setStyleSheet("color: white; font-size: 15px; padding:0px;");
		}
    }
    else {
        setStyleSheet("background-color: white;");
        for (QLabel* label : { emailLabel, passwordLabel, fullNameLabel, usernameLabel, balanceLabel }) {
			label->setStyleSheet(
				"QLabel {"
				"  font-size: 18px;"
				"  padding: 8px 20px;"
				"  border: 2px solid #ccc;"
				"  border-radius: 12px;"
				"  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #f0f0f0, stop:1 #dcdcdc);"
				"  min-width: 300px;"
				"}"
			);
        
        }
		for (QLabel* label : { emailLabel1, passwordLabel1, fullNameLabel1, usernameLabel1, balanceLabel1 }) {
			label->setStyleSheet("color: black; font-size: 15px; padding:0px;");
		}

    }
}