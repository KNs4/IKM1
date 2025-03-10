#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();

    // подключение к бд
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName("postgres");
    db.setPassword("2601");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");
    if (db.open()) {
        qDebug() << "Connected to database";
    } else {
        qDebug() << "Connected to database unsuccesfuly";
    }
    query = new QSqlQuery(db);

    query->exec("CREATE TABLE Users ("
                "user_id SERIAL PRIMARY KEY,"
                "first_name VARCHAR(50) NOT NULL,"
                "last_name VARCHAR(50) NOT NULL,"
                "email VARCHAR(100) UNIQUE NOT NULL,"
                "phone VARCHAR(15),"
                "adres TEXT"
                ");");

    query->exec("CREATE TABLE Products ("
                "product_id SERIAL PRIMARY KEY,"
                "name VARCHAR(100) NOT NULL,"
                "description TEXT,"
                "price DECIMAL(10, 2) NOT NULL,"
                "stock INT NOT NULL"
                ");");

    query->exec("CREATE TABLE Orders ("
                "order_id SERIAL PRIMARY KEY,"
                "user_id INT NOT NULL,"
                "product_id INT NOT NULL,"
                "order_date DATE NOT NULL,"
                "status VARCHAR(20) NOT NULL,"
                "FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE,"
                "FOREIGN KEY (product_id) REFERENCES Products(product_id) ON DELETE CASCADE"
                ");");

    // Настройка моделей(!)
    usersmodel = new QSqlTableModel(this, db);
    usersmodel->setTable("users");
    usersmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    usersmodel->select();
    ui->users_table->setModel(usersmodel);

    productsmodel = new QSqlTableModel(this, db);
    productsmodel->setTable("products");
    productsmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    productsmodel->select();
    ui->products_table->setModel(productsmodel);

    ordersmodel = new QSqlTableModel(this, db);
    ordersmodel->setTable("orders");
    ordersmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    ordersmodel->select();
    ui->orders_table->setModel(ordersmodel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Обработка кликов по таблицам
void MainWindow::on_table_clicked(QAbstractItemModel *model,
                                  const QModelIndex &index,
                                  QVector<QLabel *> labels)
{
    row = index.row();
    int column = index.column();
    qDebug() << "Row: " << row << ", Column: " << column;

    if (row < 0 || row >= model->rowCount()) {
        qDebug() << "Invalid row selected.";
        return;
    }

    for (int i = 0; i < labels.size(); ++i) {
        QString data = model->data(model->index(row, i)).toString();
        labels[i]->setText(data);
    }
}

//Использование таблицы пользователей
void MainWindow::on_users_table_clicked(const QModelIndex &index)
{
    on_table_clicked(usersmodel,
                     index,
                     {ui->user_id, ui->first_name, ui->last_name, ui->email, ui->phone, ui->adres});
}

//Метод добавления пользователя
void MainWindow::on_add_row_user_clicked()
{
    if (!usersmodel->insertRow(usersmodel->rowCount())) {
        qDebug() << "Failed to insert row:" << usersmodel->lastError().text();
    }
    qDebug() << "New user row added.";
}

//Удаление пользователя
void MainWindow::on_remove_row_user_clicked()
{
    if (row < 0 || row >= usersmodel->rowCount()) {
        qDebug() << "Invalid row selected for deletion";
        return;
    }
    if (!usersmodel->removeRow(row)) {
        qDebug() << "Failed to remove user:" << usersmodel->lastError().text();
    } else if (!usersmodel->submitAll()) {
        qDebug() << "Failed to submit changes:" << usersmodel->lastError().text();
    } else {
        qDebug() << "User removed successfully.";
    }
}

//Сохранение данных пользователя в базу
void MainWindow::on_save_users_clicked()
{
    for (int row = 0; row < usersmodel->rowCount(); ++row) {
        QString first_name = usersmodel->data(usersmodel->index(row, 1)).toString();
        QString last_name = usersmodel->data(usersmodel->index(row, 2)).toString();
        QString email = usersmodel->data(usersmodel->index(row, 3)).toString();
        QString phone = usersmodel->data(usersmodel->index(row, 4)).toString();
        QString adres = usersmodel->data(usersmodel->index(row, 5)).toString();

        if (first_name.isEmpty() || last_name.isEmpty() || email.isEmpty() || phone.isEmpty()
            || adres.isEmpty()) {
            ui->label_saved_users->setText("Пожалуйста! Заполните все данные!");
            qDebug() << "Validation failed for row" << row << ". Not all data is filled.";
            return; // Прерываем выполнение, если данные не заполнены
        }

        if (!validateUsersDataEmail(email)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_users->setText("Неверный email! Пожалуйста! Используйте только email с разрешенными доменами (yandex.ru или gmail.com)");
            return;
        }
        if (!validateUsersDataPhone(phone)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_users->setText("Неверный номер телефона! Номер должен начинать на 8 или +7 и иметь 11 цифр");
            return;
        }
        if (!validateUsersDataAdres(adres)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_users->setText("Неверный адрес! Адрес не может быть только из цифр!");
            return;
        }
    }

    if (!usersmodel->submitAll()) {
        qDebug() << "Failed to save client data:" << usersmodel->lastError().text();

    } else {
        ui->label_saved_users->setText("Сохранено!");
        qDebug() << "Client data saved successfully.";
    }
}

//Проверка введенных данных пользователя на адрес
bool MainWindow::validateUsersDataAdres(const QString &adres)
{
    qDebug() << "Checking Adres:" << adres;
    //Проверяем адрес: не должен состоять только из цифр и пробелов
    QRegularExpression addressRegex(".*[a-zA-Zа-яА-ЯёЁ].*"); //Проверяет наличие хотя бы одной буквы
    if (!adres.isEmpty() && !addressRegex.match(adres).hasMatch()) {
        qDebug() << "Invalid address format. Must not consist only of numbers or spaces.";
        return false;
    }

    return true; // Адрес валиден
}

//Проверка введенных данных пользователя на номер телефона
bool MainWindow::validateUsersDataPhone(const QString &phone)
{
    qDebug() << "Checking Phone:" << phone;
    // Проверяем телефон: должен состоять из 11 цифр, первая цифра — 8
    QRegularExpression phoneRegex("^(\\+7||8)\\d{10}$");
    if (!phone.isEmpty() && !phoneRegex.match(phone).hasMatch()) {
        qDebug() << "Invalid phone format. Must start with '8' or '+7' and contain 11 digits.";
        return false;
    }

    return true; // Номер телефона валиден
}

//Проверка введенных данных пользователя на почту
bool MainWindow::validateUsersDataEmail(const QString &email)
{
    qDebug() << "Checking Email:" << email;
    // Регулярное выражение для проверки email с ограничением на домен
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@(gmail\\.com|yandex\\.ru)$");

    // Проверяем email
    if (!email.isEmpty() && !emailRegex.match(email).hasMatch()) {
        qDebug() << "Invalid email format. Must be from gmail.com or yandex.ru.";
        return false;
    }

    return true; // Email валиден
}

//Использование таблицы товаров
void MainWindow::on_products_table_clicked(const QModelIndex &index)
{
    on_table_clicked(productsmodel,
                     index,
                     {ui->product_id, ui->name, ui->description, ui->price, ui->stock});
}

//Добавление товара
void MainWindow::on_add_row_products_clicked()
{
    if (!productsmodel->insertRow(productsmodel->rowCount())) {
        qDebug() << "Failed to insert row:" << productsmodel->lastError().text();
    } else {
        qDebug() << "Product added successfully.";
    }
}

//Удаление товара
void MainWindow::on_remove_row_products_clicked()
{
    if (row < 0 || row >= productsmodel->rowCount()) {
        qDebug() << "Invalid row selected for deletion.";
        return;
    }

    if (!productsmodel->removeRow(row)) {
        qDebug() << "Failed to remove row:" << productsmodel->lastError().text();
    } else if (!productsmodel->submitAll()) {
        qDebug() << "Failed to submit changes:" << productsmodel->lastError().text();
    } else {
        qDebug() << "Product removed successfully.";
    }
}

//Кнопка сохранения товара
void MainWindow::on_save_products_clicked()
{
    for (int row = 0; row < productsmodel->rowCount(); ++row) {
        QString name = productsmodel->data(productsmodel->index(row, 1)).toString();
        QString description = productsmodel->data(productsmodel->index(row, 2)).toString();
        QString price = productsmodel->data(productsmodel->index(row, 3)).toString();
        QString stock = productsmodel->data(productsmodel->index(row, 4)).toString();

        if (name.isEmpty() || description.isEmpty() || price.isEmpty() || stock.isEmpty()) {
            ui->label_saved_product->setText("Пожалуйста! Заполните все данные!");
            qDebug() << "Validation failed for row" << row << ". Not all data is filled.";
            return; // Прерываем выполнение, если данные не заполнены
        }

        if (!validateProductsDataPrice(price)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_product->setText("Неверно указана цена! Цена не может быть отрицательным числом!");
            return;
        }

        if (!validateProductsDataStock(stock)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_product->setText("Неверно указано количество товаров! Количество не может быть отрицательным!");
            return;
        }
    }

    if (!productsmodel->submitAll()) {
        qDebug() << "Failed to save product:" << productsmodel->lastError().text();
    } else {
        qDebug() << "Product data saved successfully.";
        ui->label_saved_product->setText("Сохранено!");
    }
}

//Проверка на правильную цену товара
bool MainWindow::validateProductsDataPrice(const QString &price)
{
    // Проверяем, что строка содержит только числа и, возможно, точку для дробных чисел
    bool isNumeric;
    double priceValue = price.toDouble(&isNumeric);

    // Цена должна быть числом, не меньше нуля
    if (!isNumeric || priceValue < 0) {
        qDebug() << "Invalid price:" << price;
        return false;
    }

    return true;
}

//Проверка на правильной количество товара
bool MainWindow::validateProductsDataStock(const QString &stock)
{
    // Проверяем, что строка содержит только целые числа
    bool isNumeric;
    int stockValue = stock.toInt(&isNumeric);

    // Количество должно быть числом, не меньше нуля
    if (!isNumeric || stockValue < 0) {
        qDebug() << "Invalid stock:" << stock;
        return false;
    }

    return true;
}

//Добавление заказа
void MainWindow::on_add_row_orders_clicked()
{
    if (!ordersmodel->insertRow(ordersmodel->rowCount())) {
        qDebug() << "Failed to insert row:" << ordersmodel->lastError().text();
    } else {
        qDebug() << "Order added successfully.";
    }
}

void MainWindow::on_remove_row_orders_clicked()
{
    // Ensure 'row' is defined and points to a valid index
    if (row < 0 || row >= ordersmodel->rowCount()) {
        qDebug() << "Invalid row selected for deletion.";
        return;
    }

    // Attempt to remove the row
    if (!ordersmodel->removeRow(row)) {
        qDebug() << "Failed to remove row:" << ordersmodel->lastError().text();
        return; // Exit if removal fails
    }

    // Check if there are any changes to submit
    if (!ordersmodel->submitAll()) {
        qDebug() << "Failed to submit changes:" << ordersmodel->lastError().text();
    } else {
        qDebug() << "Order removed successfully.";
    }
}

//Сохранение заказа
void MainWindow::on_save_orders_clicked()
{
    for (int row = 0; row < productsmodel->rowCount(); ++row) {
        QString order_id = productsmodel->data(productsmodel->index(row, 0)).toString();
        QString user_id = productsmodel->data(productsmodel->index(row, 1)).toString();
        QString product_id = productsmodel->data(productsmodel->index(row, 2)).toString();
        QString order_data = productsmodel->data(productsmodel->index(row, 3)).toString();
        QString status = productsmodel->data(productsmodel->index(row, 4)).toString();

        if (order_id.isEmpty() || user_id.isEmpty() || product_id.isEmpty() || order_data.isEmpty()
            || status.isEmpty()) {
            ui->label_saved_orders->setText("Пожалуйста! Заполните все данные!");
            qDebug() << "Validation failed for row" << row << ". Not all data is filled.";
            return; // Прерываем выполнение, если данные не заполнены
        }
    }

    if (!ordersmodel->submitAll()) {
        qDebug() << "Failed to save order:" << ordersmodel->lastError().text();
    } else {
        qDebug() << "Order data saved successfully.";
        ui->label_saved_orders->setText("Сохранено!");
    }
}

void MainWindow::on_orders_table_clicked(const QModelIndex &index)
{
    on_table_clicked(ordersmodel,
                     index,
                     {ui->order_id, ui->user_id_2, ui->product_id_2, ui->order_date, ui->status});
}
