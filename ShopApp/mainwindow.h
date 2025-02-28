#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractItemModel>
#include <QApplication>
#include <QDebug>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_add_row_user_clicked();
    void on_remove_row_user_clicked();
    void on_save_users_clicked();
    void on_users_table_clicked(const QModelIndex &index);

    void on_add_row_products_clicked();
    void on_remove_row_products_clicked();
    void on_save_products_clicked();
    void on_products_table_clicked(const QModelIndex &index);

    void on_add_row_orders_clicked();
    void on_remove_row_orders_clicked();
    void on_save_orders_clicked();
    void on_orders_table_clicked(const QModelIndex &index);

    void on_table_clicked(QAbstractItemModel *model,
                          const QModelIndex &index,
                          QVector<QLabel *> labels);

    bool validateProductsDataPrice(const QString &price);
    bool validateProductsDataStock(const QString &stock);

    bool validateUsersDataAdres(const QString &adres);
    bool validateUsersDataPhone(const QString &phone);
    bool validateUsersDataEmail(const QString &email);

    void on_tabWidget_windowIconChanged(const QIcon &icon);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *usersmodel;
    QSqlTableModel *productsmodel;
    QSqlTableModel *ordersmodel;
    QAbstractItemModel *model;

    int row;
};

#endif // MAINWINDOW_H
