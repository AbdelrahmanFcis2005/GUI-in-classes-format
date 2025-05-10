#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPixmap>
class EditProfilePageWidget : public QWidget
{
public:
	EditProfilePageWidget(QWidget* parent = nullptr);
	void applyDarkMode(bool dark);
	QPushButton* getSaveButton() const;

private:
	QFormLayout* formLayout;
	QWidget* formContainer;
	QPushButton* logoButton;
	QLineEdit* nameLineEdit;
	QLineEdit* emailLineEdit;
	QLineEdit* passwordLineEdit;
	QPushButton* saveButton;
	QVBoxLayout* layout;
};

