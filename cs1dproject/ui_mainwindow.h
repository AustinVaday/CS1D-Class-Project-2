/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QStackedWidget *stackedWidget_mainWidget;
    QWidget *page_mainMenu;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *button_planATrip0;
    QPushButton *button_searchForStadiums0;
    QPushButton *button_viewStadiums;
    QPushButton *button_shop0;
    QPushButton *button_adminAccess0;
    QStackedWidget *stackedWidget_mainMenu0;
    QWidget *page_7;
    QTextBrowser *textBrowser_4;
    QWidget *page_8;
    QLabel *label_titleMainMenu;
    QWidget *page_planATrip0;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_VisitAll0;
    QPushButton *button_customTrip0;
    QPushButton *button_searchForStadiums1;
    QStackedWidget *stackedWidget_planATrip0;
    QWidget *page_9;
    QTextBrowser *textBrowser_5;
    QWidget *page_takeATrip0;
    QPushButton *button_back0;
    QPushButton *button_mainMenu0;
    QLabel *label_planATripTitle;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *page_planATrip1;
    QTextBrowser *textBrowser;
    QLabel *label_outputMilageLabel;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *button_shop1;
    QPushButton *button_searchForStadiums2;
    QPushButton *button_help2;
    QLineEdit *lineEdit;
    QStackedWidget *stackedWidget_takeATrip1;
    QWidget *page_3;
    QTextBrowser *textBrowser_2;
    QWidget *page_4;
    QPushButton *button_back1;
    QPushButton *button_mainMenu1;
    QWidget *page_searchForStadium0;
    QStackedWidget *stackedWidget_searchForStadium0;
    QWidget *page_searchForStadium;
    QTextBrowser *textBrowser_3;
    QWidget *page_6;
    QListWidget *listWidget_searchResults0;
    QPushButton *button_back2;
    QPushButton *button_mainMenu2;
    QLabel *label_teamSearchTitle;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_searchLine0;
    QPushButton *button_search0;
    QWidget *page_shop0;
    QListWidget *listWidget_searchResults1;
    QLabel *label_shopTitle;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_searchLine2;
    QPushButton *button_search2;
    QPushButton *button_mainMenu3;
    QPushButton *button_back3;
    QWidget *page_adminLogin0;
    QPushButton *button_login;
    QLabel *label_adminLoginTitle;
    QPushButton *button_mainMenu5;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QPushButton *button_back4;
    QWidget *page_stadiumList;
    QListWidget *listWidget_stadiumList0;
    QLabel *label_stadiumListTitle;
    QPushButton *button_mainMenu4;
    QWidget *layoutWidget7;
    QPushButton *button_back31;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(782, 539);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 20, 0, 0));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        stackedWidget_mainWidget = new QStackedWidget(centralWidget);
        stackedWidget_mainWidget->setObjectName(QStringLiteral("stackedWidget_mainWidget"));
        stackedWidget_mainWidget->setGeometry(QRect(30, 60, 731, 421));
        page_mainMenu = new QWidget();
        page_mainMenu->setObjectName(QStringLiteral("page_mainMenu"));
        layoutWidget = new QWidget(page_mainMenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 80, 331, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_planATrip0 = new QPushButton(layoutWidget);
        button_planATrip0->setObjectName(QStringLiteral("button_planATrip0"));

        verticalLayout->addWidget(button_planATrip0);

        button_searchForStadiums0 = new QPushButton(layoutWidget);
        button_searchForStadiums0->setObjectName(QStringLiteral("button_searchForStadiums0"));

        verticalLayout->addWidget(button_searchForStadiums0);

        button_viewStadiums = new QPushButton(layoutWidget);
        button_viewStadiums->setObjectName(QStringLiteral("button_viewStadiums"));

        verticalLayout->addWidget(button_viewStadiums);

        button_shop0 = new QPushButton(layoutWidget);
        button_shop0->setObjectName(QStringLiteral("button_shop0"));

        verticalLayout->addWidget(button_shop0);

        button_adminAccess0 = new QPushButton(layoutWidget);
        button_adminAccess0->setObjectName(QStringLiteral("button_adminAccess0"));

        verticalLayout->addWidget(button_adminAccess0);

        stackedWidget_mainMenu0 = new QStackedWidget(page_mainMenu);
        stackedWidget_mainMenu0->setObjectName(QStringLiteral("stackedWidget_mainMenu0"));
        stackedWidget_mainMenu0->setGeometry(QRect(450, 40, 251, 331));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        textBrowser_4 = new QTextBrowser(page_7);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(20, 20, 211, 291));
        stackedWidget_mainMenu0->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        stackedWidget_mainMenu0->addWidget(page_8);
        label_titleMainMenu = new QLabel(page_mainMenu);
        label_titleMainMenu->setObjectName(QStringLiteral("label_titleMainMenu"));
        label_titleMainMenu->setGeometry(QRect(100, 40, 361, 31));
        stackedWidget_mainWidget->addWidget(page_mainMenu);
        page_planATrip0 = new QWidget();
        page_planATrip0->setObjectName(QStringLiteral("page_planATrip0"));
        layoutWidget1 = new QWidget(page_planATrip0);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 80, 451, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_VisitAll0 = new QPushButton(layoutWidget1);
        button_VisitAll0->setObjectName(QStringLiteral("button_VisitAll0"));

        verticalLayout_2->addWidget(button_VisitAll0);

        button_customTrip0 = new QPushButton(layoutWidget1);
        button_customTrip0->setObjectName(QStringLiteral("button_customTrip0"));

        verticalLayout_2->addWidget(button_customTrip0);

        button_searchForStadiums1 = new QPushButton(layoutWidget1);
        button_searchForStadiums1->setObjectName(QStringLiteral("button_searchForStadiums1"));

        verticalLayout_2->addWidget(button_searchForStadiums1);

        stackedWidget_planATrip0 = new QStackedWidget(page_planATrip0);
        stackedWidget_planATrip0->setObjectName(QStringLiteral("stackedWidget_planATrip0"));
        stackedWidget_planATrip0->setGeometry(QRect(500, 20, 211, 371));
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        textBrowser_5 = new QTextBrowser(page_9);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(30, 30, 141, 271));
        stackedWidget_planATrip0->addWidget(page_9);
        page_takeATrip0 = new QWidget();
        page_takeATrip0->setObjectName(QStringLiteral("page_takeATrip0"));
        stackedWidget_planATrip0->addWidget(page_takeATrip0);
        button_back0 = new QPushButton(page_planATrip0);
        button_back0->setObjectName(QStringLiteral("button_back0"));
        button_back0->setGeometry(QRect(30, 10, 75, 23));
        button_mainMenu0 = new QPushButton(page_planATrip0);
        button_mainMenu0->setObjectName(QStringLiteral("button_mainMenu0"));
        button_mainMenu0->setGeometry(QRect(100, 10, 75, 23));
        label_planATripTitle = new QLabel(page_planATrip0);
        label_planATripTitle->setObjectName(QStringLiteral("label_planATripTitle"));
        label_planATripTitle->setGeometry(QRect(190, 50, 111, 16));
        layoutWidget2 = new QWidget(page_planATrip0);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(31, 371, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget_mainWidget->addWidget(page_planATrip0);
        page_planATrip1 = new QWidget();
        page_planATrip1->setObjectName(QStringLiteral("page_planATrip1"));
        textBrowser = new QTextBrowser(page_planATrip1);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 30, 361, 301));
        label_outputMilageLabel = new QLabel(page_planATrip1);
        label_outputMilageLabel->setObjectName(QStringLiteral("label_outputMilageLabel"));
        label_outputMilageLabel->setGeometry(QRect(210, 310, 161, 20));
        layoutWidget3 = new QWidget(page_planATrip1);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(380, 30, 179, 381));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        button_shop1 = new QPushButton(layoutWidget3);
        button_shop1->setObjectName(QStringLiteral("button_shop1"));

        verticalLayout_3->addWidget(button_shop1);

        button_searchForStadiums2 = new QPushButton(layoutWidget3);
        button_searchForStadiums2->setObjectName(QStringLiteral("button_searchForStadiums2"));

        verticalLayout_3->addWidget(button_searchForStadiums2);

        button_help2 = new QPushButton(layoutWidget3);
        button_help2->setObjectName(QStringLiteral("button_help2"));

        verticalLayout_3->addWidget(button_help2);

        lineEdit = new QLineEdit(layoutWidget3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        stackedWidget_takeATrip1 = new QStackedWidget(page_planATrip1);
        stackedWidget_takeATrip1->setObjectName(QStringLiteral("stackedWidget_takeATrip1"));
        stackedWidget_takeATrip1->setGeometry(QRect(520, 10, 201, 381));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        textBrowser_2 = new QTextBrowser(page_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(30, 20, 141, 301));
        stackedWidget_takeATrip1->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget_takeATrip1->addWidget(page_4);
        button_back1 = new QPushButton(page_planATrip1);
        button_back1->setObjectName(QStringLiteral("button_back1"));
        button_back1->setGeometry(QRect(20, 0, 75, 23));
        button_mainMenu1 = new QPushButton(page_planATrip1);
        button_mainMenu1->setObjectName(QStringLiteral("button_mainMenu1"));
        button_mainMenu1->setGeometry(QRect(90, 0, 75, 23));
        stackedWidget_mainWidget->addWidget(page_planATrip1);
        page_searchForStadium0 = new QWidget();
        page_searchForStadium0->setObjectName(QStringLiteral("page_searchForStadium0"));
        stackedWidget_searchForStadium0 = new QStackedWidget(page_searchForStadium0);
        stackedWidget_searchForStadium0->setObjectName(QStringLiteral("stackedWidget_searchForStadium0"));
        stackedWidget_searchForStadium0->setGeometry(QRect(510, 90, 191, 271));
        page_searchForStadium = new QWidget();
        page_searchForStadium->setObjectName(QStringLiteral("page_searchForStadium"));
        textBrowser_3 = new QTextBrowser(page_searchForStadium);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(20, 50, 141, 151));
        stackedWidget_searchForStadium0->addWidget(page_searchForStadium);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget_searchForStadium0->addWidget(page_6);
        listWidget_searchResults0 = new QListWidget(page_searchForStadium0);
        listWidget_searchResults0->setObjectName(QStringLiteral("listWidget_searchResults0"));
        listWidget_searchResults0->setGeometry(QRect(20, 90, 491, 271));
        button_back2 = new QPushButton(page_searchForStadium0);
        button_back2->setObjectName(QStringLiteral("button_back2"));
        button_back2->setGeometry(QRect(20, 20, 75, 23));
        button_mainMenu2 = new QPushButton(page_searchForStadium0);
        button_mainMenu2->setObjectName(QStringLiteral("button_mainMenu2"));
        button_mainMenu2->setGeometry(QRect(90, 20, 75, 23));
        label_teamSearchTitle = new QLabel(page_searchForStadium0);
        label_teamSearchTitle->setObjectName(QStringLiteral("label_teamSearchTitle"));
        label_teamSearchTitle->setGeometry(QRect(200, 30, 361, 16));
        layoutWidget4 = new QWidget(page_searchForStadium0);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 50, 491, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_searchLine0 = new QLineEdit(layoutWidget4);
        lineEdit_searchLine0->setObjectName(QStringLiteral("lineEdit_searchLine0"));

        horizontalLayout->addWidget(lineEdit_searchLine0);

        button_search0 = new QPushButton(layoutWidget4);
        button_search0->setObjectName(QStringLiteral("button_search0"));

        horizontalLayout->addWidget(button_search0);

        stackedWidget_mainWidget->addWidget(page_searchForStadium0);
        page_shop0 = new QWidget();
        page_shop0->setObjectName(QStringLiteral("page_shop0"));
        listWidget_searchResults1 = new QListWidget(page_shop0);
        new QListWidgetItem(listWidget_searchResults1);
        listWidget_searchResults1->setObjectName(QStringLiteral("listWidget_searchResults1"));
        listWidget_searchResults1->setGeometry(QRect(40, 90, 611, 291));
        label_shopTitle = new QLabel(page_shop0);
        label_shopTitle->setObjectName(QStringLiteral("label_shopTitle"));
        label_shopTitle->setGeometry(QRect(240, 20, 171, 21));
        layoutWidget5 = new QWidget(page_shop0);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(40, 50, 611, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_searchLine2 = new QLineEdit(layoutWidget5);
        lineEdit_searchLine2->setObjectName(QStringLiteral("lineEdit_searchLine2"));

        horizontalLayout_3->addWidget(lineEdit_searchLine2);

        button_search2 = new QPushButton(layoutWidget5);
        button_search2->setObjectName(QStringLiteral("button_search2"));

        horizontalLayout_3->addWidget(button_search2);

        button_mainMenu3 = new QPushButton(page_shop0);
        button_mainMenu3->setObjectName(QStringLiteral("button_mainMenu3"));
        button_mainMenu3->setGeometry(QRect(110, 20, 75, 23));
        button_back3 = new QPushButton(page_shop0);
        button_back3->setObjectName(QStringLiteral("button_back3"));
        button_back3->setGeometry(QRect(0, 0, 100, 30));
        page_adminLogin0 = new QWidget(page_shop0);
        page_adminLogin0->setObjectName(QStringLiteral("page_adminLogin0"));
        page_adminLogin0->setGeometry(QRect(220, 10, 100, 30));
        button_login = new QPushButton(page_adminLogin0);
        button_login->setObjectName(QStringLiteral("button_login"));
        button_login->setGeometry(QRect(190, 200, 75, 23));
        label_adminLoginTitle = new QLabel(page_adminLogin0);
        label_adminLoginTitle->setObjectName(QStringLiteral("label_adminLoginTitle"));
        label_adminLoginTitle->setGeometry(QRect(290, 70, 241, 41));
        button_mainMenu5 = new QPushButton(page_adminLogin0);
        button_mainMenu5->setObjectName(QStringLiteral("button_mainMenu5"));
        button_mainMenu5->setGeometry(QRect(70, 50, 75, 23));
        layoutWidget6 = new QWidget(page_adminLogin0);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(290, 150, 251, 141));
        verticalLayout_7 = new QVBoxLayout(layoutWidget6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(layoutWidget6);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        verticalLayout_7->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(layoutWidget6);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        verticalLayout_7->addWidget(lineEdit_password);

        stackedWidget_mainWidget->addWidget(page_shop0);
        mainToolBar = new QToolBar();
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        stackedWidget_mainWidget->addWidget(mainToolBar);
        statusBar = new QStatusBar();
        statusBar->setObjectName(QStringLiteral("statusBar"));
        stackedWidget_mainWidget->addWidget(statusBar);
        button_back4 = new QPushButton(centralWidget);
        button_back4->setObjectName(QStringLiteral("button_back4"));
        button_back4->setGeometry(QRect(80, 30, 75, 23));
        page_stadiumList = new QWidget(centralWidget);
        page_stadiumList->setObjectName(QStringLiteral("page_stadiumList"));
        page_stadiumList->setGeometry(QRect(200, 30, 100, 30));
        listWidget_stadiumList0 = new QListWidget(page_stadiumList);
        new QListWidgetItem(listWidget_stadiumList0);
        listWidget_stadiumList0->setObjectName(QStringLiteral("listWidget_stadiumList0"));
        listWidget_stadiumList0->setGeometry(QRect(40, 70, 651, 281));
        label_stadiumListTitle = new QLabel(page_stadiumList);
        label_stadiumListTitle->setObjectName(QStringLiteral("label_stadiumListTitle"));
        label_stadiumListTitle->setGeometry(QRect(250, 40, 291, 21));
        button_mainMenu4 = new QPushButton(page_stadiumList);
        button_mainMenu4->setObjectName(QStringLiteral("button_mainMenu4"));
        button_mainMenu4->setGeometry(QRect(120, 10, 75, 23));
        layoutWidget7 = new QWidget(page_stadiumList);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(-60, -10, 100, 30));
        button_back31 = new QPushButton(layoutWidget7);
        button_back31->setObjectName(QStringLiteral("button_back31"));
        button_back31->setGeometry(QRect(40, 20, 75, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget_mainWidget->setCurrentIndex(6);
        stackedWidget_mainMenu0->setCurrentIndex(0);
        stackedWidget_planATrip0->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        button_planATrip0->setText(QApplication::translate("MainWindow", "plan a trip", 0));
        button_searchForStadiums0->setText(QApplication::translate("MainWindow", "search for stadium", 0));
        button_viewStadiums->setText(QApplication::translate("MainWindow", "View stadiums", 0));
        button_shop0->setText(QApplication::translate("MainWindow", "shop", 0));
        button_adminAccess0->setText(QApplication::translate("MainWindow", "Admin", 0));
        textBrowser_4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Temp - still thinking about what is going to go here</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        label_titleMainMenu->setText(QApplication::translate("MainWindow", "MLB Vacation Planer", 0));
        button_VisitAll0->setText(QApplication::translate("MainWindow", "visit all", 0));
        button_customTrip0->setText(QApplication::translate("MainWindow", "custom trip", 0));
        button_searchForStadiums1->setText(QApplication::translate("MainWindow", "search for a stadium", 0));
        textBrowser_5->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Temp - still thinking about what is going to go here</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        button_back0->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu0->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        label_planATripTitle->setText(QApplication::translate("MainWindow", "Plan A Trip", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Picture  of graph goes here</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">could be a stacked widget</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-t"
                        "ype:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        label_outputMilageLabel->setText(QApplication::translate("MainWindow", "Total Mileage traveled (in miles): ", 0));
        button_shop1->setText(QApplication::translate("MainWindow", "shop", 0));
        button_searchForStadiums2->setText(QApplication::translate("MainWindow", "search for stadium", 0));
        button_help2->setText(QApplication::translate("MainWindow", "help (doesnt work yet)", 0));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Temp - Still thinking about what to do here</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        button_back1->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu1->setText(QApplication::translate("MainWindow", "Done", 0));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Temp - Still thinking about what to do here</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        button_back2->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu2->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        label_teamSearchTitle->setText(QApplication::translate("MainWindow", "Team Search", 0));
        button_search0->setText(QApplication::translate("MainWindow", "Search", 0));

        const bool __sortingEnabled = listWidget_searchResults1->isSortingEnabled();
        listWidget_searchResults1->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_searchResults1->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "On selecting an element, it will launch the team info page which will have a shop functionality", 0));
        listWidget_searchResults1->setSortingEnabled(__sortingEnabled);

        label_shopTitle->setText(QApplication::translate("MainWindow", "Shop", 0));
        button_search2->setText(QApplication::translate("MainWindow", "Search", 0));
        button_mainMenu3->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        button_login->setText(QApplication::translate("MainWindow", "Login", 0));
        label_adminLoginTitle->setText(QApplication::translate("MainWindow", "Admin Login", 0));
        button_mainMenu5->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        button_back4->setText(QApplication::translate("MainWindow", "Back", 0));

        const bool __sortingEnabled1 = listWidget_stadiumList0->isSortingEnabled();
        listWidget_stadiumList0->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_stadiumList0->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "This list will contain selectable stadiums", 0));
        listWidget_stadiumList0->setSortingEnabled(__sortingEnabled1);

        label_stadiumListTitle->setText(QApplication::translate("MainWindow", "List of All Stadiums", 0));
        button_mainMenu4->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        button_back31->setText(QApplication::translate("MainWindow", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
