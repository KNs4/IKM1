/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *users_tab;
    QTableView *users_table;
    QPushButton *add_row_user;
    QPushButton *remove_row_user;
    QLabel *client_info;
    QLabel *user_id;
    QLabel *first_name;
    QLabel *last_name;
    QLabel *email;
    QLabel *phone;
    QLabel *adres;
    QPushButton *save_users;
    QLabel *label_saved_users;
    QLabel *info_label;
    QLabel *info_label_2;
    QLabel *info_label_3;
    QLabel *info_label_4;
    QLabel *info_label_5;
    QLabel *info_label_6;
    QWidget *products_tab;
    QTableView *products_table;
    QLabel *credit_info;
    QPushButton *add_row_products;
    QPushButton *remove_row_products;
    QLabel *product_id;
    QLabel *name;
    QLabel *description;
    QLabel *price;
    QLabel *stock;
    QLabel *label_saved_product;
    QPushButton *save_products;
    QLabel *info_label_7;
    QLabel *info_label_8;
    QLabel *info_label_9;
    QLabel *info_label_10;
    QLabel *info_label_11;
    QWidget *orders_tab;
    QTableView *orders_table;
    QLabel *payment_info;
    QPushButton *add_row_orders;
    QPushButton *remove_row_orders;
    QLabel *order_date;
    QLabel *status;
    QLabel *user_id_2;
    QLabel *order_id;
    QPushButton *save_orders;
    QLabel *label_saved_orders;
    QLabel *info_label_12;
    QLabel *info_label_13;
    QLabel *info_label_14;
    QLabel *info_label_15;
    QLabel *info_label_16;
    QLabel *product_id_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(880, 500));
        MainWindow->setMaximumSize(QSize(1000, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"    left: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background:  rgb(255, 255, 255);\n"
"    border: 2px solid #FFFFFF;\n"
"    min-width: 100px;\n"
"        min-height: 30px;\n"
"    padding: 3px 3px;\n"
"    margin-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #FFFFFF;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 3px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setMinimumSize(QSize(1300, 600));
        tabWidget->setMaximumSize(QSize(1300, 600));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        users_tab = new QWidget();
        users_tab->setObjectName("users_tab");
        users_table = new QTableView(users_tab);
        users_table->setObjectName("users_table");
        users_table->setGeometry(QRect(10, 10, 971, 261));
        users_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"qproperty-alignment: AlignCenter; "));
        add_row_user = new QPushButton(users_tab);
        add_row_user->setObjectName("add_row_user");
        add_row_user->setGeometry(QRect(500, 440, 231, 61));
        add_row_user->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        remove_row_user = new QPushButton(users_tab);
        remove_row_user->setObjectName("remove_row_user");
        remove_row_user->setGeometry(QRect(740, 440, 241, 61));
        remove_row_user->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        client_info = new QLabel(users_tab);
        client_info->setObjectName("client_info");
        client_info->setGeometry(QRect(10, 280, 271, 61));
        client_info->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        user_id = new QLabel(users_tab);
        user_id->setObjectName("user_id");
        user_id->setGeometry(QRect(10, 370, 150, 50));
        user_id->setMinimumSize(QSize(150, 50));
        user_id->setMaximumSize(QSize(150, 50));
        user_id->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        first_name = new QLabel(users_tab);
        first_name->setObjectName("first_name");
        first_name->setGeometry(QRect(170, 370, 150, 50));
        first_name->setMinimumSize(QSize(150, 50));
        first_name->setMaximumSize(QSize(150, 50));
        first_name->setStyleSheet(QString::fromUtf8("border: 2px solid white; /* \320\242\320\276\320\275\320\272\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; \n"
"background-color: rgb(255, 255, 255);"));
        last_name = new QLabel(users_tab);
        last_name->setObjectName("last_name");
        last_name->setGeometry(QRect(10, 450, 150, 50));
        last_name->setMinimumSize(QSize(150, 50));
        last_name->setMaximumSize(QSize(150, 50));
        last_name->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; \n"
"background-color: rgb(255, 255, 255);"));
        email = new QLabel(users_tab);
        email->setObjectName("email");
        email->setGeometry(QRect(170, 450, 150, 50));
        email->setMinimumSize(QSize(150, 50));
        email->setMaximumSize(QSize(150, 50));
        email->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; \n"
"background-color: rgb(255, 255, 255);"));
        phone = new QLabel(users_tab);
        phone->setObjectName("phone");
        phone->setGeometry(QRect(330, 370, 150, 50));
        phone->setMinimumSize(QSize(150, 50));
        phone->setMaximumSize(QSize(150, 50));
        phone->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; \n"
"background-color: rgb(255, 255, 255);"));
        adres = new QLabel(users_tab);
        adres->setObjectName("adres");
        adres->setGeometry(QRect(330, 450, 150, 50));
        adres->setMinimumSize(QSize(150, 50));
        adres->setMaximumSize(QSize(150, 50));
        adres->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; \n"
"background-color: rgb(255, 255, 255);"));
        save_users = new QPushButton(users_tab);
        save_users->setObjectName("save_users");
        save_users->setGeometry(QRect(500, 350, 481, 81));
        save_users->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        label_saved_users = new QLabel(users_tab);
        label_saved_users->setObjectName("label_saved_users");
        label_saved_users->setGeometry(QRect(290, 280, 691, 61));
        label_saved_users->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 190, 190);"));
        info_label = new QLabel(users_tab);
        info_label->setObjectName("info_label");
        info_label->setGeometry(QRect(30, 350, 100, 19));
        info_label->setMinimumSize(QSize(100, 19));
        info_label->setMaximumSize(QSize(100, 10));
        info_label->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_2 = new QLabel(users_tab);
        info_label_2->setObjectName("info_label_2");
        info_label_2->setGeometry(QRect(190, 350, 100, 19));
        info_label_2->setMinimumSize(QSize(100, 19));
        info_label_2->setMaximumSize(QSize(100, 10));
        info_label_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_3 = new QLabel(users_tab);
        info_label_3->setObjectName("info_label_3");
        info_label_3->setGeometry(QRect(30, 430, 100, 19));
        info_label_3->setMinimumSize(QSize(100, 19));
        info_label_3->setMaximumSize(QSize(100, 10));
        info_label_3->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_4 = new QLabel(users_tab);
        info_label_4->setObjectName("info_label_4");
        info_label_4->setGeometry(QRect(190, 430, 100, 19));
        info_label_4->setMinimumSize(QSize(100, 19));
        info_label_4->setMaximumSize(QSize(100, 10));
        info_label_4->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_5 = new QLabel(users_tab);
        info_label_5->setObjectName("info_label_5");
        info_label_5->setGeometry(QRect(350, 350, 100, 19));
        info_label_5->setMinimumSize(QSize(100, 19));
        info_label_5->setMaximumSize(QSize(100, 10));
        info_label_5->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_6 = new QLabel(users_tab);
        info_label_6->setObjectName("info_label_6");
        info_label_6->setGeometry(QRect(350, 430, 100, 19));
        info_label_6->setMinimumSize(QSize(100, 19));
        info_label_6->setMaximumSize(QSize(100, 10));
        info_label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 0px solid white;\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        tabWidget->addTab(users_tab, QString());
        products_tab = new QWidget();
        products_tab->setObjectName("products_tab");
        products_table = new QTableView(products_tab);
        products_table->setObjectName("products_table");
        products_table->setGeometry(QRect(10, 10, 971, 261));
        products_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        credit_info = new QLabel(products_tab);
        credit_info->setObjectName("credit_info");
        credit_info->setGeometry(QRect(10, 280, 271, 61));
        credit_info->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        add_row_products = new QPushButton(products_tab);
        add_row_products->setObjectName("add_row_products");
        add_row_products->setGeometry(QRect(500, 440, 231, 61));
        add_row_products->setMinimumSize(QSize(0, 0));
        add_row_products->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        remove_row_products = new QPushButton(products_tab);
        remove_row_products->setObjectName("remove_row_products");
        remove_row_products->setGeometry(QRect(740, 440, 241, 61));
        remove_row_products->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        product_id = new QLabel(products_tab);
        product_id->setObjectName("product_id");
        product_id->setGeometry(QRect(10, 370, 150, 50));
        product_id->setMinimumSize(QSize(150, 50));
        product_id->setMaximumSize(QSize(150, 50));
        product_id->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        name = new QLabel(products_tab);
        name->setObjectName("name");
        name->setGeometry(QRect(170, 370, 150, 50));
        name->setMinimumSize(QSize(150, 50));
        name->setMaximumSize(QSize(150, 50));
        name->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        description = new QLabel(products_tab);
        description->setObjectName("description");
        description->setGeometry(QRect(10, 450, 150, 50));
        description->setMinimumSize(QSize(150, 50));
        description->setMaximumSize(QSize(150, 50));
        description->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        price = new QLabel(products_tab);
        price->setObjectName("price");
        price->setGeometry(QRect(330, 410, 150, 50));
        price->setMinimumSize(QSize(150, 50));
        price->setMaximumSize(QSize(150, 50));
        price->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        stock = new QLabel(products_tab);
        stock->setObjectName("stock");
        stock->setGeometry(QRect(170, 450, 150, 50));
        stock->setMinimumSize(QSize(150, 50));
        stock->setMaximumSize(QSize(150, 50));
        stock->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        label_saved_product = new QLabel(products_tab);
        label_saved_product->setObjectName("label_saved_product");
        label_saved_product->setGeometry(QRect(290, 280, 691, 61));
        label_saved_product->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 190, 190);"));
        save_products = new QPushButton(products_tab);
        save_products->setObjectName("save_products");
        save_products->setGeometry(QRect(500, 350, 481, 81));
        save_products->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_7 = new QLabel(products_tab);
        info_label_7->setObjectName("info_label_7");
        info_label_7->setGeometry(QRect(190, 430, 100, 19));
        info_label_7->setMinimumSize(QSize(100, 19));
        info_label_7->setMaximumSize(QSize(100, 10));
        info_label_7->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_8 = new QLabel(products_tab);
        info_label_8->setObjectName("info_label_8");
        info_label_8->setGeometry(QRect(30, 430, 100, 19));
        info_label_8->setMinimumSize(QSize(100, 19));
        info_label_8->setMaximumSize(QSize(100, 10));
        info_label_8->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_9 = new QLabel(products_tab);
        info_label_9->setObjectName("info_label_9");
        info_label_9->setGeometry(QRect(350, 390, 100, 19));
        info_label_9->setMinimumSize(QSize(100, 19));
        info_label_9->setMaximumSize(QSize(100, 10));
        info_label_9->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_10 = new QLabel(products_tab);
        info_label_10->setObjectName("info_label_10");
        info_label_10->setGeometry(QRect(30, 350, 100, 19));
        info_label_10->setMinimumSize(QSize(100, 19));
        info_label_10->setMaximumSize(QSize(100, 10));
        info_label_10->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_11 = new QLabel(products_tab);
        info_label_11->setObjectName("info_label_11");
        info_label_11->setGeometry(QRect(190, 350, 100, 19));
        info_label_11->setMinimumSize(QSize(100, 19));
        info_label_11->setMaximumSize(QSize(100, 10));
        info_label_11->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        tabWidget->addTab(products_tab, QString());
        orders_tab = new QWidget();
        orders_tab->setObjectName("orders_tab");
        orders_table = new QTableView(orders_tab);
        orders_table->setObjectName("orders_table");
        orders_table->setGeometry(QRect(10, 10, 971, 261));
        orders_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        payment_info = new QLabel(orders_tab);
        payment_info->setObjectName("payment_info");
        payment_info->setGeometry(QRect(10, 280, 271, 61));
        payment_info->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        add_row_orders = new QPushButton(orders_tab);
        add_row_orders->setObjectName("add_row_orders");
        add_row_orders->setGeometry(QRect(500, 440, 231, 61));
        add_row_orders->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        remove_row_orders = new QPushButton(orders_tab);
        remove_row_orders->setObjectName("remove_row_orders");
        remove_row_orders->setGeometry(QRect(740, 440, 241, 61));
        remove_row_orders->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        order_date = new QLabel(orders_tab);
        order_date->setObjectName("order_date");
        order_date->setGeometry(QRect(330, 410, 150, 50));
        order_date->setMinimumSize(QSize(150, 50));
        order_date->setMaximumSize(QSize(150, 50));
        order_date->setStyleSheet(QString::fromUtf8("border: 2px solid white; /* \320\242\320\276\320\275\320\272\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        status = new QLabel(orders_tab);
        status->setObjectName("status");
        status->setGeometry(QRect(170, 370, 150, 50));
        status->setMinimumSize(QSize(150, 50));
        status->setMaximumSize(QSize(150, 50));
        status->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        user_id_2 = new QLabel(orders_tab);
        user_id_2->setObjectName("user_id_2");
        user_id_2->setGeometry(QRect(10, 450, 150, 50));
        user_id_2->setMinimumSize(QSize(150, 50));
        user_id_2->setMaximumSize(QSize(150, 50));
        user_id_2->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        order_id = new QLabel(orders_tab);
        order_id->setObjectName("order_id");
        order_id->setGeometry(QRect(10, 370, 150, 50));
        order_id->setMinimumSize(QSize(150, 50));
        order_id->setMaximumSize(QSize(150, 50));
        order_id->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        save_orders = new QPushButton(orders_tab);
        save_orders->setObjectName("save_orders");
        save_orders->setGeometry(QRect(500, 350, 481, 81));
        save_orders->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        label_saved_orders = new QLabel(orders_tab);
        label_saved_orders->setObjectName("label_saved_orders");
        label_saved_orders->setGeometry(QRect(290, 280, 691, 61));
        label_saved_orders->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 190, 190);"));
        info_label_12 = new QLabel(orders_tab);
        info_label_12->setObjectName("info_label_12");
        info_label_12->setGeometry(QRect(30, 350, 100, 19));
        info_label_12->setMinimumSize(QSize(100, 19));
        info_label_12->setMaximumSize(QSize(100, 10));
        info_label_12->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_13 = new QLabel(orders_tab);
        info_label_13->setObjectName("info_label_13");
        info_label_13->setGeometry(QRect(30, 430, 100, 19));
        info_label_13->setMinimumSize(QSize(100, 19));
        info_label_13->setMaximumSize(QSize(100, 10));
        info_label_13->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_14 = new QLabel(orders_tab);
        info_label_14->setObjectName("info_label_14");
        info_label_14->setGeometry(QRect(190, 430, 100, 19));
        info_label_14->setMinimumSize(QSize(100, 19));
        info_label_14->setMaximumSize(QSize(100, 10));
        info_label_14->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_15 = new QLabel(orders_tab);
        info_label_15->setObjectName("info_label_15");
        info_label_15->setGeometry(QRect(190, 350, 100, 19));
        info_label_15->setMinimumSize(QSize(100, 19));
        info_label_15->setMaximumSize(QSize(100, 10));
        info_label_15->setStyleSheet(QString::fromUtf8("border: 0px solid white; /* \320\242\320\276\320\275\320\272\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        info_label_16 = new QLabel(orders_tab);
        info_label_16->setObjectName("info_label_16");
        info_label_16->setGeometry(QRect(350, 390, 100, 19));
        info_label_16->setMinimumSize(QSize(100, 19));
        info_label_16->setMaximumSize(QSize(100, 10));
        info_label_16->setStyleSheet(QString::fromUtf8("border: 0px solid white; /* \320\242\320\276\320\275\320\272\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        product_id_2 = new QLabel(orders_tab);
        product_id_2->setObjectName("product_id_2");
        product_id_2->setGeometry(QRect(170, 450, 150, 50));
        product_id_2->setMinimumSize(QSize(150, 50));
        product_id_2->setMaximumSize(QSize(150, 50));
        product_id_2->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"font-size: 16px;\n"
"qproperty-alignment: AlignCenter; "));
        tabWidget->addTab(orders_tab, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(users_table, add_row_user);
        QWidget::setTabOrder(add_row_user, remove_row_user);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\236\320\275\320\273\320\260\320\271\320\275 \320\234\320\260\320\263\320\260\320\267\320\270\320\275", nullptr));
        add_row_user->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        remove_row_user->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        client_info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265", nullptr));
        user_id->setText(QCoreApplication::translate("MainWindow", "user_id", nullptr));
        first_name->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 ", nullptr));
        last_name->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217 ", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        phone->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        adres->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        save_users->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
#if QT_CONFIG(tooltip)
        label_saved_users->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\236\320\272\320\275\320\276 \320\276\321\210\320\270\320\261\320\276\320\272. \320\242\321\203\321\202 \320\262\321\213\321\205\320\276\320\264\321\217\321\202 \320\276\321\210\320\270\320\261\320\272\320\270 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\260\320\274\320\270</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_saved_users->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        info_label->setText(QCoreApplication::translate("MainWindow", "id ", nullptr));
        info_label_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        info_label_3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        info_label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        info_label_5->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        info_label_6->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(users_tab), QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        credit_info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\202\320\276\320\262\320\260\321\200\320\265", nullptr));
        add_row_products->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        remove_row_products->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        product_id->setText(QCoreApplication::translate("MainWindow", "product_id", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        description->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        price->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260 \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        stock->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        label_saved_product->setText(QString());
        save_products->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        info_label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273.\321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        info_label_8->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        info_label_9->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260", nullptr));
        info_label_10->setText(QCoreApplication::translate("MainWindow", "id ", nullptr));
        info_label_11->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(products_tab), QCoreApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\321\213", nullptr));
        payment_info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\267\320\260\320\272\320\260\320\267\320\260\321\205", nullptr));
        add_row_orders->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        remove_row_orders->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        order_date->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        status->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        user_id_2->setText(QCoreApplication::translate("MainWindow", "user_id ", nullptr));
        order_id->setText(QCoreApplication::translate("MainWindow", "order_id ", nullptr));
        save_orders->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label_saved_orders->setText(QString());
        info_label_12->setText(QCoreApplication::translate("MainWindow", "ID \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        info_label_13->setText(QCoreApplication::translate("MainWindow", "ID user", nullptr));
        info_label_14->setText(QCoreApplication::translate("MainWindow", "ID \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        info_label_15->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        info_label_16->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        product_id_2->setText(QCoreApplication::translate("MainWindow", "ID \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(orders_tab), QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\275\320\273\320\260\320\271\320\275\320\234\320\260\320\263\320\260\320\267\320\270\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
