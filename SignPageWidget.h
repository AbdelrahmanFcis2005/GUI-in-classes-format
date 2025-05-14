#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPixmap>
class SignPageWidget : public QWidget {

public:
    SignPageWidget(QWidget* parent = nullptr);
    void applyDarkMode(bool dark);
	QPushButton* getSignButton() const;

private:
    QFormLayout* formLayout;
    QWidget* formContainer;
	QPushButton* logoButton;
    QLineEdit* nameLineEdit;
    QLineEdit* emailLineEdit;
    QLineEdit* passwordLineEdit;
    QPushButton* signButton;
	QVBoxLayout* layout;
};

