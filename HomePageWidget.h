#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QStackedWidget>
#include <QList>
#include <QStringList>
#include <QWidget>
#include <QPushButton>
#include <QFrame>

class HomePageWidget : public QWidget {

public:
    HomePageWidget(QWidget* parent = nullptr);
    void applyDarkMode(bool dark);
	QPushButton* getProfileButton() const;
	QPushButton* getBalanceButton() const;
	QPushButton* getFeedbackButton() const;
	QPushButton* getLogoutButton() const;

private:
    QFrame* bottomNav;
	QStringList labels;
    QList<QPushButton*> navButtons;
};