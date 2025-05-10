#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPixmap>


class LoginPageWidget : public QWidget {

public:
    LoginPageWidget(QWidget* parent = nullptr);
    void applyDarkMode(bool dark);
    QPushButton* getLoginButton() const;
	QPushButton* getSignButton() const;

private:
	QFormLayout* formLayout;
    QWidget* formContainer;
    QPushButton* logoButton;
    QLineEdit* nameLineEdit;
    QLineEdit* emailLineEdit;
    QLineEdit* passwordLineEdit;
    QPushButton* loginButton;
    QPushButton* signButton;
    QLabel* orLabel;
	QVBoxLayout* layout;
};
