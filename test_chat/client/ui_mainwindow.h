/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *connectButton;
    QPushButton *sendButton;
    QLineEdit *nameInput;
    QLineEdit *messageInput;
    QLabel *inputName;
    QTextBrowser *chatDisplay;
    QPushButton *clearAllButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(441, 642);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(300, 40, 121, 41));
        QFont font;
        font.setPointSize(12);
        connectButton->setFont(font);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(350, 490, 71, 31));
        nameInput = new QLineEdit(centralwidget);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(60, 50, 231, 21));
        messageInput = new QLineEdit(centralwidget);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(20, 490, 321, 31));
        messageInput->setCursorPosition(0);
        inputName = new QLabel(centralwidget);
        inputName->setObjectName("inputName");
        inputName->setGeometry(QRect(18, 50, 51, 21));
        inputName->setFont(font);
        chatDisplay = new QTextBrowser(centralwidget);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setGeometry(QRect(20, 91, 401, 381));
        clearAllButton = new QPushButton(centralwidget);
        clearAllButton->setObjectName("clearAllButton");
        clearAllButton->setGeometry(QRect(180, 560, 75, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 441, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        inputName->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        clearAllButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
