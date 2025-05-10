#include "LoginPageWidget.h"
#include <QPixmap>

LoginPageWidget::LoginPageWidget(QWidget* parent) : QWidget(parent) {
    formLayout = new QFormLayout;

    logoButton = new QPushButton;
    logoButton->setIcon(QIcon("media/ASU-PAY.svg"));
    logoButton->setStyleSheet("border:none; padding:0px");
    logoButton->setIconSize(QSize(110, 110));

    nameLineEdit = new QLineEdit;
    emailLineEdit = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    loginButton = new QPushButton("Log In");
    signButton = new QPushButton("Sign Up");
    orLabel = new QLabel("-----------------( or )-----------------");

    nameLineEdit->setPlaceholderText("Full Name");
    nameLineEdit->setStyleSheet("border: 1.2px solid gray; border-radius: 4px; padding: 16px; height: 40px; margin:15px");
    emailLineEdit->setPlaceholderText("Email");
    emailLineEdit->setStyleSheet("border: 1.2px solid gray; border-radius: 4px; padding: 16px; height: 40px; margin:15px");
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setStyleSheet("border: 1.2px solid gray; border-radius: 4px; padding: 16px; height: 40px; margin:15px");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(emailLineEdit);
    formLayout->addWidget(passwordLineEdit);
    formLayout->addWidget(loginButton);
    formLayout->addWidget(orLabel);
    formLayout->addWidget(signButton);

    formContainer = new QWidget;
    formContainer->setLayout(formLayout);
    formContainer->setStyleSheet("background-color: white;border: 0.9px solid gray; border-radius: 12px; padding: 15px;");
	formContainer->setFixedWidth(500);
	formContainer->setFixedHeight(510);
	formContainer->setContentsMargins(10, 10, 10, 10);

    layout = new QVBoxLayout;
    layout->addWidget(logoButton, 0, Qt::AlignHCenter);
	layout->addSpacing(5);
    layout->addWidget(formContainer, 0, Qt::AlignHCenter);
    layout->addStretch();
    setLayout(layout);
    applyDarkMode(false);
}

QPushButton* LoginPageWidget::getLoginButton() const {
    return loginButton;
}

QPushButton* LoginPageWidget::getSignButton() const {
	return signButton;
}

void LoginPageWidget::applyDarkMode(bool dark) {
    if (dark) {
        setStyleSheet("background-color: #2c2c2c;");
        formContainer->setStyleSheet("background-color: #2c2c2c; border: 1.2px solid #0078D7; border-radius: 12px; padding: 25px;");
        nameLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        emailLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        passwordLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        loginButton->setStyleSheet("background-color: #0078D7; font:20px; color: white; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
        signButton->setStyleSheet("background-color: #2c2c2c; font:20px; color: #0078D7; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
        orLabel->setStyleSheet("color: #ccc; font-size: 26px; border:none;");
    }
    else {
        setStyleSheet("background-color: white;");
        formContainer->setStyleSheet("background-color: white; border: 1.2px solid gray; border-radius: 12px; padding: 25px;");
        nameLineEdit->setStyleSheet("border: 1.2px solid gray; border-radius: 4px; padding: 16px; height: 40px; margin:15px");
        emailLineEdit->setStyleSheet("border: 1.2px solid gray; border-radius: 4px; padding: 16px; height: 40px; margin:15px");
        passwordLineEdit->setStyleSheet("border: 1.2px solid gray; border-radius: 4px; padding: 16px; height: 40px; margin:15px");
        loginButton->setStyleSheet("background-color: #0078D7; font:20px; color: white; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
        signButton->setStyleSheet("background-color: white; font:20px; color: #0078D7; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
        orLabel->setStyleSheet("color: black; font-size: 26px; border:none;");
    }
}
