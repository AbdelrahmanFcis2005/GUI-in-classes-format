#include "EditProfilePageWidget.h"
#include <QPixmap>

EditProfilePageWidget::EditProfilePageWidget(QWidget* parent) : QWidget(parent) {
    formLayout = new QFormLayout;

    logoButton = new QPushButton;
    logoButton->setIcon(QIcon("media/profile.svg"));
    logoButton->setStyleSheet("border:none; padding:0px");
    logoButton->setIconSize(QSize(100, 100));

    nameLineEdit = new QLineEdit(this);
    emailLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    saveButton = new QPushButton(this);
	saveButton->setText("Save");

    nameLineEdit->setPlaceholderText("Full Name");
    emailLineEdit->setPlaceholderText("Email");
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(emailLineEdit);
    formLayout->addWidget(passwordLineEdit);
    formLayout->addWidget(saveButton);

    formContainer = new QWidget(this);
    formContainer->setLayout(formLayout);
    formContainer->setStyleSheet("background-color: white;border: 1.4px solid black; border-radius: 12px; padding: 15px;");
    formContainer->setFixedWidth(500);
    formContainer->setFixedHeight(510);
    formContainer->setContentsMargins(10, 10, 10, 10);

    layout = new QVBoxLayout(this);
    layout->addWidget(logoButton, 0, Qt::AlignHCenter);
    layout->addSpacing(10);
    layout->addWidget(formContainer, 0, Qt::AlignHCenter);
    layout->addStretch();
    setLayout(layout);
    applyDarkMode(false);
}

QPushButton* EditProfilePageWidget::getSaveButton() const {
    return saveButton;
}

void EditProfilePageWidget::applyDarkMode(bool dark)
{
    if (dark) {
        setStyleSheet("background-color: #2c2c2c;");
        formContainer->setStyleSheet("background-color: #2c2c2c; border: 1.2px solid #0078D7; border-radius: 12px; padding: 25px;");
        nameLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        emailLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        passwordLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        saveButton->setStyleSheet("background-color: #0078D7; font:20px; color: white; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
    }
    else {
        setStyleSheet("background-color: white;");
        formContainer->setStyleSheet("background-color: white; border: 1.2px solid black; border-radius: 12px; padding: 25px;");
        nameLineEdit->setStyleSheet("border: 1.2px solid black; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        emailLineEdit->setStyleSheet("border: 1.2px solid black; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        passwordLineEdit->setStyleSheet("border: 1.2px solid black; border-radius: 4px; padding: 6px; height: 40px; margin:15px");
        saveButton->setStyleSheet("background-color: #0078D7; font:20px; color: white; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px;");
    }
}

