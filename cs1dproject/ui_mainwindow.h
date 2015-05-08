/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
    QLabel *label_shopTitle;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_searchLine2;
    QPushButton *button_search2;
    QPushButton *button_prev;
    QPushButton *button_mainMenu3;
    QPushButton *button_next;
    QPushButton *button_finish;
    QTableWidget *table_stadiumsToVisit;
    QGroupBox *groupBox_souvenirs;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_welcomeMessage;
    QPushButton *button_addToCart;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *page_stadiumList;
    QListWidget *listWidget_stadiumList0;
    QLabel *label_stadiumListTitle;
    QPushButton *button_back4;
    QPushButton *button_mainMenu4;
    QWidget *page_adminLogin0;
    QPushButton *button_login;
    QLabel *label_adminLoginTitle;
    QPushButton *button_mainMenu5;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QWidget *page_adminMainMenu;
    QPushButton *button_back_adminMainMenu;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_4;
    QPushButton *button_addStadium0;
    QPushButton *button_modifyStadium;
    QPushButton *button_addSouviner;
    QPushButton *button_modifySouviner;
    QWidget *page_addStadium;
    QFrame *frame_2;
    QLabel *label_titleAddStadium;
    QWidget *layoutWidget8;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_stadiumName;
    QLineEdit *lineEdit_teamName;
    QLineEdit *lineEdit_cityName;
    QLineEdit *lineEdit_stateName;
    QLineEdit *lineEdit_grassType;
    QWidget *layoutWidget9;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_stadiumLabel;
    QLabel *label_teamNameLabel;
    QLabel *label_cityLabel;
    QLabel *label_stateLabel;
    QLabel *label_grassTypeLabel;
    QFrame *frame_1;
    QListWidget *listWidget_currentStadiums;
    QLabel *label_currentStadiumList;
    QPushButton *button_continueAddStadium;
    QPushButton *button_backAddStadium;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

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
        stackedWidget_mainWidget->setGeometry(QRect(-60, 80, 721, 421));
        page_mainMenu = new QWidget();
        page_mainMenu->setObjectName(QStringLiteral("page_mainMenu"));
        layoutWidget = new QWidget(page_mainMenu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 80, 331, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
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
        label_titleMainMenu->setGeometry(QRect(130, 40, 291, 21));
        stackedWidget_mainWidget->addWidget(page_mainMenu);
        page_planATrip0 = new QWidget();
        page_planATrip0->setObjectName(QStringLiteral("page_planATrip0"));
        layoutWidget1 = new QWidget(page_planATrip0);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 80, 451, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
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
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
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
        layoutWidget3->setGeometry(QRect(380, 30, 121, 381));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
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
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
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
        label_shopTitle = new QLabel(page_shop0);
        label_shopTitle->setObjectName(QStringLiteral("label_shopTitle"));
        label_shopTitle->setGeometry(QRect(480, 20, 171, 21));
        layoutWidget5 = new QWidget(page_shop0);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(40, 50, 611, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_searchLine2 = new QLineEdit(layoutWidget5);
        lineEdit_searchLine2->setObjectName(QStringLiteral("lineEdit_searchLine2"));

        horizontalLayout_3->addWidget(lineEdit_searchLine2);

        button_search2 = new QPushButton(layoutWidget5);
        button_search2->setObjectName(QStringLiteral("button_search2"));

        horizontalLayout_3->addWidget(button_search2);

        button_prev = new QPushButton(page_shop0);
        button_prev->setObjectName(QStringLiteral("button_prev"));
        button_prev->setGeometry(QRect(80, 20, 75, 23));
        button_mainMenu3 = new QPushButton(page_shop0);
        button_mainMenu3->setObjectName(QStringLiteral("button_mainMenu3"));
        button_mainMenu3->setGeometry(QRect(10, 20, 75, 23));
        button_next = new QPushButton(page_shop0);
        button_next->setObjectName(QStringLiteral("button_next"));
        button_next->setGeometry(QRect(150, 20, 75, 23));
        button_finish = new QPushButton(page_shop0);
        button_finish->setObjectName(QStringLiteral("button_finish"));
        button_finish->setGeometry(QRect(220, 20, 75, 23));
        table_stadiumsToVisit = new QTableWidget(page_shop0);
        if (table_stadiumsToVisit->columnCount() < 2)
            table_stadiumsToVisit->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_stadiumsToVisit->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_stadiumsToVisit->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (table_stadiumsToVisit->rowCount() < 5)
            table_stadiumsToVisit->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_stadiumsToVisit->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_stadiumsToVisit->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_stadiumsToVisit->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_stadiumsToVisit->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_stadiumsToVisit->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(2, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(2, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(3, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(3, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(4, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_stadiumsToVisit->setItem(4, 1, __qtablewidgetitem16);
        table_stadiumsToVisit->setObjectName(QStringLiteral("table_stadiumsToVisit"));
        table_stadiumsToVisit->setGeometry(QRect(10, 120, 231, 241));
        groupBox_souvenirs = new QGroupBox(page_shop0);
        groupBox_souvenirs->setObjectName(QStringLiteral("groupBox_souvenirs"));
        groupBox_souvenirs->setGeometry(QRect(250, 200, 191, 111));
        checkBox = new QCheckBox(groupBox_souvenirs);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 20, 151, 17));
        checkBox_2 = new QCheckBox(groupBox_souvenirs);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 40, 151, 17));
        checkBox_3 = new QCheckBox(groupBox_souvenirs);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 60, 151, 17));
        checkBox_4 = new QCheckBox(groupBox_souvenirs);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 80, 171, 17));
        label_welcomeMessage = new QLabel(page_shop0);
        label_welcomeMessage->setObjectName(QStringLiteral("label_welcomeMessage"));
        label_welcomeMessage->setGeometry(QRect(260, 120, 161, 71));
        button_addToCart = new QPushButton(page_shop0);
        button_addToCart->setObjectName(QStringLiteral("button_addToCart"));
        button_addToCart->setGeometry(QRect(260, 310, 151, 23));
        tableWidget = new QTableWidget(page_shop0);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem38);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(430, 120, 291, 231));
        label = new QLabel(page_shop0);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 101, 16));
        label_2 = new QLabel(page_shop0);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(640, 370, 81, 16));
        stackedWidget_mainWidget->addWidget(page_shop0);
        page_stadiumList = new QWidget();
        page_stadiumList->setObjectName(QStringLiteral("page_stadiumList"));
        listWidget_stadiumList0 = new QListWidget(page_stadiumList);
        new QListWidgetItem(listWidget_stadiumList0);
        listWidget_stadiumList0->setObjectName(QStringLiteral("listWidget_stadiumList0"));
        listWidget_stadiumList0->setGeometry(QRect(40, 70, 651, 281));
        label_stadiumListTitle = new QLabel(page_stadiumList);
        label_stadiumListTitle->setObjectName(QStringLiteral("label_stadiumListTitle"));
        label_stadiumListTitle->setGeometry(QRect(250, 40, 291, 21));
        button_back4 = new QPushButton(page_stadiumList);
        button_back4->setObjectName(QStringLiteral("button_back4"));
        button_back4->setGeometry(QRect(50, 10, 75, 23));
        button_mainMenu4 = new QPushButton(page_stadiumList);
        button_mainMenu4->setObjectName(QStringLiteral("button_mainMenu4"));
        button_mainMenu4->setGeometry(QRect(120, 10, 75, 23));
        stackedWidget_mainWidget->addWidget(page_stadiumList);
        page_adminLogin0 = new QWidget();
        page_adminLogin0->setObjectName(QStringLiteral("page_adminLogin0"));
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
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(layoutWidget6);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        verticalLayout_7->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(layoutWidget6);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        verticalLayout_7->addWidget(lineEdit_password);

        stackedWidget_mainWidget->addWidget(page_adminLogin0);
        page_adminMainMenu = new QWidget();
        page_adminMainMenu->setObjectName(QStringLiteral("page_adminMainMenu"));
        button_back_adminMainMenu = new QPushButton(page_adminMainMenu);
        button_back_adminMainMenu->setObjectName(QStringLiteral("button_back_adminMainMenu"));
        button_back_adminMainMenu->setGeometry(QRect(30, 30, 75, 23));
        layoutWidget7 = new QWidget(page_adminMainMenu);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(250, 50, 261, 251));
        verticalLayout_4 = new QVBoxLayout(layoutWidget7);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        button_addStadium0 = new QPushButton(layoutWidget7);
        button_addStadium0->setObjectName(QStringLiteral("button_addStadium0"));

        verticalLayout_4->addWidget(button_addStadium0);

        button_modifyStadium = new QPushButton(layoutWidget7);
        button_modifyStadium->setObjectName(QStringLiteral("button_modifyStadium"));

        verticalLayout_4->addWidget(button_modifyStadium);

        button_addSouviner = new QPushButton(layoutWidget7);
        button_addSouviner->setObjectName(QStringLiteral("button_addSouviner"));

        verticalLayout_4->addWidget(button_addSouviner);

        button_modifySouviner = new QPushButton(layoutWidget7);
        button_modifySouviner->setObjectName(QStringLiteral("button_modifySouviner"));

        verticalLayout_4->addWidget(button_modifySouviner);

        stackedWidget_mainWidget->addWidget(page_adminMainMenu);
        page_addStadium = new QWidget();
        page_addStadium->setObjectName(QStringLiteral("page_addStadium"));
        frame_2 = new QFrame(page_addStadium);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(260, 60, 391, 291));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_titleAddStadium = new QLabel(frame_2);
        label_titleAddStadium->setObjectName(QStringLiteral("label_titleAddStadium"));
        label_titleAddStadium->setGeometry(QRect(80, 10, 251, 21));
        layoutWidget8 = new QWidget(frame_2);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(110, 40, 231, 241));
        verticalLayout_5 = new QVBoxLayout(layoutWidget8);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit_stadiumName = new QLineEdit(layoutWidget8);
        lineEdit_stadiumName->setObjectName(QStringLiteral("lineEdit_stadiumName"));

        verticalLayout_5->addWidget(lineEdit_stadiumName);

        lineEdit_teamName = new QLineEdit(layoutWidget8);
        lineEdit_teamName->setObjectName(QStringLiteral("lineEdit_teamName"));

        verticalLayout_5->addWidget(lineEdit_teamName);

        lineEdit_cityName = new QLineEdit(layoutWidget8);
        lineEdit_cityName->setObjectName(QStringLiteral("lineEdit_cityName"));

        verticalLayout_5->addWidget(lineEdit_cityName);

        lineEdit_stateName = new QLineEdit(layoutWidget8);
        lineEdit_stateName->setObjectName(QStringLiteral("lineEdit_stateName"));

        verticalLayout_5->addWidget(lineEdit_stateName);

        lineEdit_grassType = new QLineEdit(layoutWidget8);
        lineEdit_grassType->setObjectName(QStringLiteral("lineEdit_grassType"));

        verticalLayout_5->addWidget(lineEdit_grassType);

        layoutWidget9 = new QWidget(frame_2);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(21, 42, 91, 231));
        verticalLayout_6 = new QVBoxLayout(layoutWidget9);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_stadiumLabel = new QLabel(layoutWidget9);
        label_stadiumLabel->setObjectName(QStringLiteral("label_stadiumLabel"));

        verticalLayout_6->addWidget(label_stadiumLabel);

        label_teamNameLabel = new QLabel(layoutWidget9);
        label_teamNameLabel->setObjectName(QStringLiteral("label_teamNameLabel"));

        verticalLayout_6->addWidget(label_teamNameLabel);

        label_cityLabel = new QLabel(layoutWidget9);
        label_cityLabel->setObjectName(QStringLiteral("label_cityLabel"));

        verticalLayout_6->addWidget(label_cityLabel);

        label_stateLabel = new QLabel(layoutWidget9);
        label_stateLabel->setObjectName(QStringLiteral("label_stateLabel"));

        verticalLayout_6->addWidget(label_stateLabel);

        label_grassTypeLabel = new QLabel(layoutWidget9);
        label_grassTypeLabel->setObjectName(QStringLiteral("label_grassTypeLabel"));

        verticalLayout_6->addWidget(label_grassTypeLabel);

        frame_1 = new QFrame(page_addStadium);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setGeometry(QRect(10, 60, 231, 341));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        listWidget_currentStadiums = new QListWidget(frame_1);
        listWidget_currentStadiums->setObjectName(QStringLiteral("listWidget_currentStadiums"));
        listWidget_currentStadiums->setGeometry(QRect(10, 60, 211, 241));
        label_currentStadiumList = new QLabel(frame_1);
        label_currentStadiumList->setObjectName(QStringLiteral("label_currentStadiumList"));
        label_currentStadiumList->setGeometry(QRect(10, 10, 201, 31));
        button_continueAddStadium = new QPushButton(page_addStadium);
        button_continueAddStadium->setObjectName(QStringLiteral("button_continueAddStadium"));
        button_continueAddStadium->setGeometry(QRect(330, 360, 261, 31));
        button_backAddStadium = new QPushButton(page_addStadium);
        button_backAddStadium->setObjectName(QStringLiteral("button_backAddStadium"));
        button_backAddStadium->setGeometry(QRect(20, 20, 75, 23));
        stackedWidget_mainWidget->addWidget(page_addStadium);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 782, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget_mainWidget->setCurrentIndex(4);
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
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Temp - still thinking about what is going to go here</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_titleMainMenu->setText(QApplication::translate("MainWindow", "MLB Vacation Planer", 0));
        button_VisitAll0->setText(QApplication::translate("MainWindow", "visit all", 0));
        button_customTrip0->setText(QApplication::translate("MainWindow", "custom trip", 0));
        button_searchForStadiums1->setText(QApplication::translate("MainWindow", "search for a stadium", 0));
        textBrowser_5->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Temp - still thinking about what is going to go here</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        button_back0->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu0->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        label_planATripTitle->setText(QApplication::translate("MainWindow", "Plan A Trip", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Picture  of graph goes here</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">could be a stacked widget</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_outputMilageLabel->setText(QApplication::translate("MainWindow", "Total Mileage traveled (in miles): ", 0));
        button_shop1->setText(QApplication::translate("MainWindow", "shop", 0));
        button_searchForStadiums2->setText(QApplication::translate("MainWindow", "search for stadium", 0));
        button_help2->setText(QApplication::translate("MainWindow", "help (doesnt work yet)", 0));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Temp - Still thinking about what to do here</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        button_back1->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu1->setText(QApplication::translate("MainWindow", "Done", 0));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Temp - Still thinking about what to do here</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        button_back2->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu2->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        label_teamSearchTitle->setText(QApplication::translate("MainWindow", "Team Search", 0));
        button_search0->setText(QApplication::translate("MainWindow", "Search", 0));
        label_shopTitle->setText(QApplication::translate("MainWindow", "Shop", 0));
        button_search2->setText(QApplication::translate("MainWindow", "Search", 0));
        button_prev->setText(QApplication::translate("MainWindow", "Prev", 0));
        button_mainMenu3->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        button_next->setText(QApplication::translate("MainWindow", "Next", 0));
        button_finish->setText(QApplication::translate("MainWindow", "Finish", 0));
        QTableWidgetItem *___qtablewidgetitem = table_stadiumsToVisit->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Stadium", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_stadiumsToVisit->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Team", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_stadiumsToVisit->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_stadiumsToVisit->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_stadiumsToVisit->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_stadiumsToVisit->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_stadiumsToVisit->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "5", 0));

        const bool __sortingEnabled = table_stadiumsToVisit->isSortingEnabled();
        table_stadiumsToVisit->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = table_stadiumsToVisit->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Angels Stadium of Anaheim", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_stadiumsToVisit->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Los Angeles Angels of Anaheim", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_stadiumsToVisit->item(1, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Comeria Park", 0));
        QTableWidgetItem *___qtablewidgetitem10 = table_stadiumsToVisit->item(1, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Detroit Tigers", 0));
        QTableWidgetItem *___qtablewidgetitem11 = table_stadiumsToVisit->item(2, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Fenway Park", 0));
        QTableWidgetItem *___qtablewidgetitem12 = table_stadiumsToVisit->item(2, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Boston Red Sox", 0));
        QTableWidgetItem *___qtablewidgetitem13 = table_stadiumsToVisit->item(3, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Globe Life Park in Arlington", 0));
        QTableWidgetItem *___qtablewidgetitem14 = table_stadiumsToVisit->item(3, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Texas Rangers", 0));
        QTableWidgetItem *___qtablewidgetitem15 = table_stadiumsToVisit->item(4, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Kauffman Stadium", 0));
        QTableWidgetItem *___qtablewidgetitem16 = table_stadiumsToVisit->item(4, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Kansas City Royals", 0));
        table_stadiumsToVisit->setSortingEnabled(__sortingEnabled);

        groupBox_souvenirs->setTitle(QApplication::translate("MainWindow", "Souvenirs Avalilable for Purchase", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Baseball Cap: $25.99", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "Baseball Bat: $35.35", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "Team Pennant: $12.99", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "Autographed Baseball: $19.99", 0));
        label_welcomeMessage->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Welcome to Angels Stadium!</p><p>Home of the Los Angeles </p><p>Angels.</p></body></html>", 0));
        button_addToCart->setText(QApplication::translate("MainWindow", "Add to Cart", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Team", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Item", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Qty", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "5", 0));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(0, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Angels", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(0, 1);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Baseball Cap", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(0, 2);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "$25.99", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(0, 3);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(1, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Tigers", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(1, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Baseball Bat", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(1, 2);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "$35.35", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(1, 3);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(2, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Red Sox", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(2, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Team Pennant", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(2, 2);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "$12.99", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(2, 3);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "2", 0));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        label->setText(QApplication::translate("MainWindow", "Stadiums to Visit:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Total: $74.33", 0));

        const bool __sortingEnabled2 = listWidget_stadiumList0->isSortingEnabled();
        listWidget_stadiumList0->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_stadiumList0->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "This list will contain selectable stadiums", 0));
        listWidget_stadiumList0->setSortingEnabled(__sortingEnabled2);

        label_stadiumListTitle->setText(QApplication::translate("MainWindow", "List of All Stadiums", 0));
        button_back4->setText(QApplication::translate("MainWindow", "Back", 0));
        button_mainMenu4->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        button_login->setText(QApplication::translate("MainWindow", "Login", 0));
        label_adminLoginTitle->setText(QApplication::translate("MainWindow", "Admin Login", 0));
        button_mainMenu5->setText(QApplication::translate("MainWindow", "Main Menu", 0));
        button_back_adminMainMenu->setText(QApplication::translate("MainWindow", "Back", 0));
        button_addStadium0->setText(QApplication::translate("MainWindow", "Add Stadium", 0));
        button_modifyStadium->setText(QApplication::translate("MainWindow", "Modify Stadium", 0));
        button_addSouviner->setText(QApplication::translate("MainWindow", "Add Souviner", 0));
        button_modifySouviner->setText(QApplication::translate("MainWindow", "Modify Souviner", 0));
        label_titleAddStadium->setText(QApplication::translate("MainWindow", "Please enter the following information", 0));
        label_stadiumLabel->setText(QApplication::translate("MainWindow", "Stadium Name: ", 0));
        label_teamNameLabel->setText(QApplication::translate("MainWindow", "Team Name: ", 0));
        label_cityLabel->setText(QApplication::translate("MainWindow", "City Name: ", 0));
        label_stateLabel->setText(QApplication::translate("MainWindow", "State Name: ", 0));
        label_grassTypeLabel->setText(QApplication::translate("MainWindow", "Grass Type : ", 0));
        label_currentStadiumList->setText(QApplication::translate("MainWindow", "Current Stadium List", 0));
        button_continueAddStadium->setText(QApplication::translate("MainWindow", "Continue", 0));
        button_backAddStadium->setText(QApplication::translate("MainWindow", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
