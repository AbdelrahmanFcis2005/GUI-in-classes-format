#include "HomePageWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

HomePageWidget::HomePageWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout* tabLayout = new QHBoxLayout(this);
    RequestButton = new QPushButton(this);
	RequestButton->setText("Request Money");
    SendButton = new QPushButton(this);
	SendButton->setText("Send Money");

    RequestButton->setStyleSheet(R"(
    QPushButton {
        background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #26D0CE, stop:1 #1A2980); text-align:left; color: white; font-size: 35px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
    }
    QPushButton:hover {
        font-size: 40px;
        padding-bottom: 140px;
 padding-left: 30px;
    }
)");
    SendButton->setStyleSheet(R"(
    QPushButton {
background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FF4B2B, stop:1 #FF416C); color: white; text-align:left; font-size: 35px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
    }
    QPushButton:hover {
        font-size: 40px;
        padding-bottom: 140px;
 padding-left: 30px;    
}
)");
    RequestButton->setFixedSize(450, 250);
    SendButton->setFixedSize(450, 250);

    tabLayout->addWidget(RequestButton);
    tabLayout->addWidget(SendButton);

    centerButton = new QPushButton(this);
	centerButton->setText("Welcome");
    centerButton->setFixedSize(300, 100);
    centerButton->setStyleSheet(R"(
    QPushButton {
background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FFF8DC, stop:0.4 #FFD700, stop:0.7 #FFC300, stop:1 #B8860B); color:  #2c2c2c; border-radius: 8px; font-size: 40px;    }
    QPushButton:hover {
        font-size: 50px;
        padding-bottom: 35px;
    }
)");

    mainLayout->addSpacing(70);
    mainLayout->addWidget(centerButton, 0, Qt::AlignCenter);
    mainLayout->addSpacing(40);
    mainLayout->addLayout(tabLayout);

    bottomNav = new QFrame(this);
    bottomNav->setStyleSheet(
        "background-color:white;"
        "border-top: 2px solid #888;"
    );
    bottomNav->setFixedHeight(100);

    QHBoxLayout* navLayout = new QHBoxLayout(bottomNav);
    navLayout->setContentsMargins(0, 0, 0, 0);
    navLayout->setSpacing(0);

    labels = { "👤\nMy Profile", "💰\nMy Balance", "💱\nMy Transactions", "🚪\nLog Out" };
    

    for (const QString& label : labels) {
        QPushButton* btn = new QPushButton(label);
        btn->setStyleSheet(R"(
    QPushButton {
        color: black;
        font-weight: bold;
        font-size: 30px;
        padding: 8px;
        border: none;
        background-color: white;
    }
    QPushButton:hover {
        font-size: 32px;
        padding: 10px;
    }
)");

        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        navLayout->addWidget(btn);
        navButtons.append(btn);
    }

    mainLayout->addStretch();
    mainLayout->addWidget(bottomNav);


    applyDarkMode(false); 
}

void HomePageWidget::applyDarkMode(bool dark) {
    if (dark) {
        setStyleSheet("background-color: #2c2c2c;");
		centerButton->setStyleSheet(R"(
            QPushButton {
                background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FFF8DC, stop:0.4 #FFD700, stop:0.7 #FFC300, stop:1 #B8860B); color:  white; border-radius: 8px; font-size: 40px;
            }
            QPushButton:hover {
                font-size: 50px;
                padding-bottom: 35px;
            }
        )");
		RequestButton->setStyleSheet(R"(
            QPushButton {
                background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #26D0CE, stop:1 #1A2980); text-align:left; color: white; font-weight: 90;font-size: 35px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
            }
            QPushButton:hover {
                font-size: 40px;
                padding-bottom: 140px;
                padding-left: 30px;
            }
        )");
		SendButton->setStyleSheet(R"(
            QPushButton {
                background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FF4B2B, stop:1 #FF416C); color: white; text-align:left; font-weight: 90; font-size: 35px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
            }
            QPushButton:hover {
                font-size: 40px;
                padding-bottom: 140px;
                padding-left: 30px;
            }
        )");
        for (QPushButton* btn : navButtons) {
                btn->setStyleSheet(R"(
                QPushButton {
                    color: white;
                    font-weight: bold;
                    font-size: 30px;
                    padding: 8px;
                    border: none;
                    background-color: #2c2c2c;
                }
                QPushButton:hover {
                    font-size: 32px;
                    padding: 10px;
                }
            )");
            }
        bottomNav->setStyleSheet("background-color: #222; border-top: 2px solid #0078D7;");
    }
    else {
        setStyleSheet("background-color: white;");
		centerButton->setStyleSheet(R"(
            QPushButton {
                background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FFF8DC, stop:0.4 #FFD700, stop:0.7 #FFC300, stop:1 #B8860B); color:  #2c2c2c; border-radius: 8px; font-size: 40px;
            }
            QPushButton:hover {
                font-size: 50px;
                padding-bottom: 35px;
            }
        )");
		RequestButton->setStyleSheet(R"(
            QPushButton {
                background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #26D0CE, stop:1 #1A2980); color: #2c2c2c; text-align:left; font-size: 35px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
            }
            QPushButton:hover {
                font-size: 40px;
                padding-bottom: 140px;
                padding-left: 30px;
            }
        )");
		SendButton->setStyleSheet(R"(
            QPushButton {
                background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FF4B2B, stop:1 #FF416C); color: #2c2c2c; text-align:left; font-size: 35px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
            }
            QPushButton:hover {
                font-size: 40px;
                padding-bottom: 140px;
                padding-left: 30px;
            }
        )");
        for (QPushButton* btn : navButtons) {
            btn->setStyleSheet(R"(
                QPushButton {
                    color: black;
                    font-weight: bold;
                    font-size: 30px;
                    padding: 8px;
                    border: none;
                    background-color: white;
                }
                QPushButton:hover {
                    font-size: 32px;
                    padding: 10px;
                }
            )");
        }
        bottomNav->setStyleSheet("background-color: white; border-top: 2px solid #888;");
    }
}

QPushButton* HomePageWidget::getProfileButton() const {
	return navButtons[0];
}

QPushButton* HomePageWidget::getBalanceButton() const {
	return navButtons[1];
}

QPushButton* HomePageWidget::getViewTransactionsButton() const {
	return navButtons[2];
}

QPushButton* HomePageWidget::getLogoutButton() const {
	return navButtons[3];
}

QPushButton* HomePageWidget::getRequestButton() const {
	return RequestButton;
}

QPushButton* HomePageWidget::getSendButton() const {
	return SendButton;
}