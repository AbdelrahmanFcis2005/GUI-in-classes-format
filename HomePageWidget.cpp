#include "HomePageWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

HomePageWidget::HomePageWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout* tabLayout = new QHBoxLayout;
    QPushButton* RequestMoneyButton = new QPushButton("Request Money");
    QPushButton* sendMoneyButton = new QPushButton("Send Money");

    RequestMoneyButton->setStyleSheet(R"(
    QPushButton {
        background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #26D0CE, stop:1 #1A2980); text-align:left; color: white; font-weight: 90;font-size: 29px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
    }
    QPushButton:hover {
        font-size: 35px;
        padding-bottom: 140px;
 padding-left: 30px;
    }
)");
    sendMoneyButton->setStyleSheet(R"(
    QPushButton {
background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FF4B2B, stop:1 #FF416C); color: white; text-align:left; font-weight: 90; font-size: 29px; padding-left:25px; padding-bottom: 150px; border-radius: 12px;
    }
    QPushButton:hover {
        font-size: 35px;
        padding-bottom: 140px;
 padding-left: 30px;    
}
)");
    RequestMoneyButton->setFixedSize(500, 220);
    sendMoneyButton->setFixedSize(500, 220);

    tabLayout->addWidget(RequestMoneyButton);
    tabLayout->addWidget(sendMoneyButton);

    QPushButton* centerButton = new QPushButton("€");
    centerButton->setFixedSize(135, 120);
    centerButton->setStyleSheet(R"(
    QPushButton {
background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.5, stop:0 #FFF8DC, stop:0.4 #FFD700, stop:0.7 #FFC300, stop:1 #B8860B); color:  #2c2c2c; border-radius: 55px; font-size: 40px;    }
    QPushButton:hover {
        font-size: 50px;
        padding-bottom: 35px;
    }
)");

    mainLayout->addSpacing(70);
    mainLayout->addWidget(centerButton, 0, Qt::AlignCenter);
    mainLayout->addSpacing(40);
    mainLayout->addLayout(tabLayout);

    bottomNav = new QFrame;
    bottomNav->setStyleSheet(
        "background-color:white;"
        "border-top: 2px solid #888;"
    );
    bottomNav->setFixedHeight(100);

    QHBoxLayout* navLayout = new QHBoxLayout(bottomNav);
    navLayout->setContentsMargins(0, 0, 0, 0);
    navLayout->setSpacing(0);

    labels = { "👤\nMy Profile", "💰\nMy Balance", "💬\nFeedbacks", "🚪\nLog Out" };
    

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
