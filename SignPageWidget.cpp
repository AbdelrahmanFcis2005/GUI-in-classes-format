#include "SignPageWidget.h"
#include <QPixmap>

SignPageWidget::SignPageWidget(QWidget* parent) : QWidget(parent) {
    formLayout = new QFormLayout;

    logoLabel = new QLabel;
    QPixmap logoPixmap("media/ASUPAL(1).png");
    logoPixmap = logoPixmap.scaledToWidth(190, Qt::SmoothTransformation);
    logoLabel->setPixmap(logoPixmap);
    logoLabel->setStyleSheet("padding:0px; margin:0px");

    nameLineEdit = new QLineEdit;
    emailLineEdit = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    signButton = new QPushButton("Sign Up");

    nameLineEdit->setPlaceholderText("Full Name");
    emailLineEdit->setPlaceholderText("Email");
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(emailLineEdit);
    formLayout->addWidget(passwordLineEdit);
    formLayout->addWidget(signButton);

    formContainer = new QWidget;
    formContainer->setLayout(formLayout);
    formContainer->setStyleSheet("background-color: white;border: 1.4px solid black; border-radius: 12px; padding: 15px;");
    formContainer->setFixedWidth(500);
    formContainer->setFixedHeight(510);
    formContainer->setContentsMargins(10, 10, 10, 10);

    layout = new QVBoxLayout;
    layout->addWidget(logoLabel, 0, Qt::AlignHCenter);
    layout->addSpacing(35);
    layout->addWidget(formContainer, 0, Qt::AlignHCenter);
    layout->addStretch();
    setLayout(layout);
    applyDarkMode(false);
}

QPushButton* SignPageWidget::getSignButton() const {
	return signButton;
}

void SignPageWidget::applyDarkMode(bool dark)
{
	if (dark) {
        setStyleSheet("background-color: #2c2c2c;");
        formContainer->setStyleSheet("background-color: #2c2c2c; border: 1.2px solid #0078D7; border-radius: 12px; padding: 25px;");
        nameLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        emailLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        passwordLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        signButton->setStyleSheet("background-color: #0078D7; font:20px; color: white; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
    }
	else {
        setStyleSheet("background-color: white;");
        formContainer->setStyleSheet("background-color: white; border: 1.2px solid black; border-radius: 12px; padding: 25px;");
        nameLineEdit->setStyleSheet("border: 1.2px solid black; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        emailLineEdit->setStyleSheet("border: 1.2px solid black; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        passwordLineEdit->setStyleSheet("border: 1.2px solid black; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        signButton->setStyleSheet("background-color: #0078D7; font:20px; color: white; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
    }
}

