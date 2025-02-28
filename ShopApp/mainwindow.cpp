#include "mainwindow.h"
#include "ui_mainwindow.h"

// Конструктор главного окна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers(); // Вывод списка доступных драйверов БД

    // Подключение к базе данных PostgreSQL
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName("postgres");
    db.setPassword("1234");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");

    // Проверка успешности подключения
    if (db.open()) {
        qDebug() << "Connected to database";
    } else {
        qDebug() << "Connected to database unsuccessfully";
    }

    // Создание объекта запроса SQL
    query = new QSqlQuery(db);

    // Создание таблицы пользователей
    query->exec("CREATE TABLE Users ("
                "user_id SERIAL PRIMARY KEY,"
                "first_name VARCHAR(50) NOT NULL,"
                "last_name VARCHAR(50) NOT NULL,"
                "email VARCHAR(100) UNIQUE NOT NULL,"
                "phone VARCHAR(15),"
                "adres TEXT"
                ");");

    // Создание таблицы продуктов
    query->exec("CREATE TABLE Products ("
                "product_id SERIAL PRIMARY KEY,"
                "name VARCHAR(100) NOT NULL,"
                "description TEXT,"
                "price DECIMAL(10, 2) NOT NULL,"
                "stock INT NOT NULL"
                ");");

    // Создание таблицы заказов
    query->exec("CREATE TABLE Orders ("
                "order_id SERIAL PRIMARY KEY,"
                "user_id INT NOT NULL,"
                "product_id INT NOT NULL,"
                "order_date DATE NOT NULL,"
                "status VARCHAR(20) NOT NULL,"
                "FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE,"
                "FOREIGN KEY (product_id) REFERENCES Products(product_id) ON DELETE CASCADE"
                ");");

    // Настройка модели данных для таблицы пользователей
    usersmodel = new QSqlTableModel(this, db);
    usersmodel->setTable("users");
    usersmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    usersmodel->select();
    ui->users_table->setModel(usersmodel);

    // Настройка модели данных для таблицы продуктов
    productsmodel = new QSqlTableModel(this, db);
    productsmodel->setTable("products");
    productsmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    productsmodel->select();
    ui->products_table->setModel(productsmodel);

    // Настройка модели данных для таблицы заказов
    ordersmodel = new QSqlTableModel(this, db);
    ordersmodel->setTable("orders");
    ordersmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    ordersmodel->select();
    ui->orders_table->setModel(ordersmodel);
}

// Деструктор главного окна
MainWindow::~MainWindow()
{
    delete ui; // Освобождение памяти, занятой интерфейсом
}

// Обработка кликов по таблицам
void MainWindow::on_table_clicked(QAbstractItemModel *model,
                                  const QModelIndex &index,
                                  QVector<QLabel *> labels)
{
    row = index.row();
    int column = index.column();
    qDebug() << "Row: " << row << ", Column: " << column;

    // Проверка на корректность индекса строки
    if (row < 0 || row >= model->rowCount()) {
        qDebug() << "Invalid row selected.";
        return;
    }

    // Обновление текста в соответствующих QLabel на основе данных из таблицы
    for (int i = 0; i < labels.size(); ++i) {
        QString data = model->data(model->index(row, i)).toString();
        labels[i]->setText(data);
    }
}

// Обработка клика по таблице пользователей
void MainWindow::on_users_table_clicked(const QModelIndex &index)
{
    on_table_clicked(usersmodel,
                     index,
                     {ui->user_id, ui->first_name, ui->last_name, ui->email, ui->phone, ui->adres});
}

// Добавление новой строки (пользователя) в таблицу
void MainWindow::on_add_row_user_clicked()
{
    if (!usersmodel->insertRow(usersmodel->rowCount())) {
        qDebug() << "Failed to insert row:" << usersmodel->lastError().text();
    }
    qDebug() << "New user row added.";
}

// Удаление выбранного пользователя
void MainWindow::on_remove_row_user_clicked()
{
    // Проверка, что строка выбрана корректно
    if (row < 0 || row >= usersmodel->rowCount()) {
        qDebug() << "Invalid row selected for deletion";
        return;
    }

    // Удаление строки и применение изменений
    if (!usersmodel->removeRow(row)) {
        qDebug() << "Failed to remove user:" << usersmodel->lastError().text();
    } else if (!usersmodel->submitAll()) {
        qDebug() << "Failed to submit changes:" << usersmodel->lastError().text();
    } else {
        qDebug() << "User removed successfully.";
    }
}

// Сохранение данных пользователя в базу
void MainWindow::on_save_users_clicked()
{
    // Проходим по всем строкам таблицы пользователей
    for (int row = 0; row < usersmodel->rowCount(); ++row) {
        // Получаем данные из таблицы
        QString first_name = usersmodel->data(usersmodel->index(row, 1)).toString();
        QString last_name = usersmodel->data(usersmodel->index(row, 2)).toString();
        QString email = usersmodel->data(usersmodel->index(row, 3)).toString();
        QString phone = usersmodel->data(usersmodel->index(row, 4)).toString();
        QString adres = usersmodel->data(usersmodel->index(row, 5)).toString();

        // Проверяем, что все поля заполнены
        if (first_name.isEmpty() || last_name.isEmpty() || email.isEmpty() || phone.isEmpty()
            || adres.isEmpty()) {
            ui->label_saved_users->setText("Пожалуйста! Заполните все данные!");
            qDebug() << "Validation failed for row" << row << ". Not all data is filled.";
            return; // Прерываем выполнение, если данные не заполнены
        }

        // Проверка email
        if (!validateUsersDataEmail(email)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_users->setText("Неверный email! Разрешены только yandex.ru и gmail.com");
            return;
        }
        // Проверка номера телефона
        if (!validateUsersDataPhone(phone)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_users->setText("Неверный номер! Должен начинаться с 8 или +7 и содержать 11 цифр.");
            return;
        }
        // Проверка адреса
        if (!validateUsersDataAdres(adres)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_users->setText("Неверный адрес! Адрес не может состоять только из цифр!");
            return;
        }
    }

    // Попытка сохранения данных в базу
    if (!usersmodel->submitAll()) {
        qDebug() << "Failed to save client data:" << usersmodel->lastError().text();
    } else {
        ui->label_saved_users->setText("Сохранено!");
        qDebug() << "Client data saved successfully.";
    }
}

// Проверка введенных данных пользователя на адрес
bool MainWindow::validateUsersDataAdres(const QString &adres)
{
    qDebug() << "Checking Adres:" << adres;
    // Проверяем адрес: он должен содержать хотя бы одну букву
    QRegularExpression addressRegex(".*[a-zA-Zа-яА-ЯёЁ].*");
    if (!adres.isEmpty() && !addressRegex.match(adres).hasMatch()) {
        qDebug() << "Invalid address format. Must not consist only of numbers or spaces.";
        return false;
    }
    return true; // Адрес валиден
}

// Проверка номера телефона
bool MainWindow::validateUsersDataPhone(const QString &phone)
{
    qDebug() << "Checking Phone:" << phone;
    // Проверяем, что номер начинается с 8 или +7 и содержит 11 цифр
    QRegularExpression phoneRegex("^(\\+7|8)\\d{10}$");
    if (!phone.isEmpty() && !phoneRegex.match(phone).hasMatch()) {
        qDebug() << "Invalid phone format. Must start with '8' or '+7' and contain 11 digits.";
        return false;
    }
    return true; // Номер телефона валиден
}

// Проверка email
bool MainWindow::validateUsersDataEmail(const QString &email)
{
    qDebug() << "Checking Email:" << email;
    // Разрешенные домены: gmail.com и yandex.ru
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@(gmail\\.com|yandex\\.ru)$");
    if (!email.isEmpty() && !emailRegex.match(email).hasMatch()) {
        qDebug() << "Invalid email format. Must be from gmail.com or yandex.ru.";
        return false;
    }
    return true; // Email валиден
}

// Обработка клика по таблице товаров
void MainWindow::on_products_table_clicked(const QModelIndex &index)
{
    on_table_clicked(productsmodel, index, {ui->product_id, ui->name, ui->description, ui->price, ui->stock});
}

// Добавление нового товара
void MainWindow::on_add_row_products_clicked()
{
    if (!productsmodel->insertRow(productsmodel->rowCount())) {
        qDebug() << "Failed to insert row:" << productsmodel->lastError().text();
    } else {
        qDebug() << "Product added successfully.";
    }
}

// Удаление товара
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

// Сохранение данных о товарах в базу
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
            return;
        }
        if (!validateProductsDataPrice(price)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_product->setText("Неверная цена! Цена не может быть отрицательной!");
            return;
        }
        if (!validateProductsDataStock(stock)) {
            qDebug() << "Validation failed for row" << row << ". Data will not be saved.";
            ui->label_saved_product->setText("Неверное количество! Не может быть отрицательным!");
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

/// Проверка на правильную цену товара
bool MainWindow::validateProductsDataPrice(const QString &price)
{
    // Проверяем, что строка содержит только числа и, возможно, точку для дробных чисел
    bool isNumeric;
    double priceValue = price.toDouble(&isNumeric);

    // Цена должна быть числом и не может быть отрицательной
    if (!isNumeric || priceValue < 0) {
        qDebug() << "Invalid price:" << price;
        return false; // Возвращаем false, если цена некорректная
    }

    return true; // Цена валидна
}

// Проверка на правильное количество товара
bool MainWindow::validateProductsDataStock(const QString &stock)
{
    // Проверяем, что строка содержит только целые числа
    bool isNumeric;
    int stockValue = stock.toInt(&isNumeric);

    // Количество товара должно быть целым числом и не может быть отрицательным
    if (!isNumeric || stockValue < 0) {
        qDebug() << "Invalid stock:" << stock;
        return false; // Возвращаем false, если количество некорректное
    }

    return true; // Количество валидно
}

// Добавление нового заказа
void MainWindow::on_add_row_orders_clicked()
{
    // Пытаемся добавить новую строку (заказ) в таблицу
    if (!ordersmodel->insertRow(ordersmodel->rowCount())) {
        qDebug() << "Failed to insert row:" << ordersmodel->lastError().text();
    } else {
        qDebug() << "Order added successfully."; // Успешное добавление заказа
    }
}

// Удаление заказа
void MainWindow::on_remove_row_orders_clicked()
{
    // Проверяем, что переменная row содержит корректное значение
    if (row < 0 || row >= ordersmodel->rowCount()) {
        qDebug() << "Invalid row selected for deletion.";
        return; // Прерываем выполнение, если строка некорректна
    }

    // Пытаемся удалить строку заказа
    if (!ordersmodel->removeRow(row)) {
        qDebug() << "Failed to remove row:" << ordersmodel->lastError().text();
        return; // Выход из функции, если удаление не удалось
    }

    // Проверяем, можно ли сохранить изменения в базе данных
    if (!ordersmodel->submitAll()) {
        qDebug() << "Failed to submit changes:" << ordersmodel->lastError().text();
    } else {
        qDebug() << "Order removed successfully."; // Успешное удаление заказа
    }
}

// Сохранение заказов в базу данных
void MainWindow::on_save_orders_clicked()
{
    for (int row = 0; row < ordersmodel->rowCount(); ++row) {
        // Получаем данные заказа из модели
        QString order_id = ordersmodel->data(ordersmodel->index(row, 0)).toString();
        QString user_id = ordersmodel->data(ordersmodel->index(row, 1)).toString();
        QString product_id = ordersmodel->data(ordersmodel->index(row, 2)).toString();
        QString order_data = ordersmodel->data(ordersmodel->index(row, 3)).toString();
        QString status = ordersmodel->data(ordersmodel->index(row, 4)).toString();

        // Проверяем, что все обязательные поля заполнены
        if (order_id.isEmpty() || user_id.isEmpty() || product_id.isEmpty() || order_data.isEmpty()
            || status.isEmpty()) {
            ui->label_saved_orders->setText("Пожалуйста! Заполните все данные!");
            qDebug() << "Validation failed for row" << row << ". Not all data is filled.";
            return; // Прерываем выполнение, если данные не заполнены
        }
    }

    // Пытаемся сохранить данные в базе
    if (!ordersmodel->submitAll()) {
        qDebug() << "Failed to save order:" << ordersmodel->lastError().text();
    } else {
        qDebug() << "Order data saved successfully."; // Успешное сохранение заказа
        ui->label_saved_orders->setText("Сохранено!");
    }
}

// Обработка клика по таблице заказов
void MainWindow::on_orders_table_clicked(const QModelIndex &index)
{
    // Вызываем функцию обработки клика, передавая данные о заказе
    on_table_clicked(ordersmodel,
                     index,
                     {ui->order_id, ui->user_id_2, ui->product_id_2, ui->order_date, ui->status});
}

// Обработчик изменения иконки окна (пока не используется)
void MainWindow::on_tabWidget_windowIconChanged(const QIcon &icon)
{

}
