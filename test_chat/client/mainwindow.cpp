#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectedToHost = false;
    ui->messageInput->setDisabled(true);
    ui->sendButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if (!connectedToHost)
    {
        // создаем сокет и подключаем его к серверу 127.0.0.1 к порту 8801
        socket = new QTcpSocket();
        // подключаем сигналы.
        connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
        if(ui->nameInput->text().isEmpty())
        {
            ui->chatDisplay->append("Введите имя!");
        }
        else
        {
            ui->messageInput->setDisabled(false);
            ui->sendButton->setDisabled(false);
            ui->nameInput->setDisabled(true);
            socket->connectToHost("127.0.0.1", 8001);
        }
    }
    else
    {
        QString name = ui->nameInput->text();
        socket->write("<font color=\"Orange\">" + name.toUtf8() + " покинул чат.</font>");
        ui->messageInput->setDisabled(true);
        ui->sendButton->setDisabled(true);
        ui->nameInput->setDisabled(false);
        socket->disconnectFromHost();
    }

}

void MainWindow::socketConnected()
{
    qDebug() << "Connected to server.";
    printMessage("<font color=\"Green\">Вы в чате.</font>");
    QString name = ui->nameInput->text();
    socket->write("<font color=\"Purple\">" + name.toUtf8() + " присоединился к чату.</font>");
    ui->connectButton->setText("Отключиться");
    connectedToHost = true;
}

void MainWindow::socketDisconnected()
{
    qDebug() << "Disconnected.";
    printMessage("<font color=\"Red\">Вы отключились от чата.</font>");
    ui->connectButton->setText("Подключиться");
    connectedToHost = false;
}

void MainWindow::socketReadyRead()
{
    ui->chatDisplay->append(socket->readAll());
}

void MainWindow::printMessage(QString message)
{
    ui->chatDisplay->append(message);
}

void MainWindow::on_sendButton_clicked()
{
    QString name = ui->nameInput->text();
    QString message = ui->messageInput->text();
    if(message.isEmpty())
    {
        ui->chatDisplay->append("Вы не можете отправить пустое сообщение!");
    }
    else
    {
        socket->write("<font color=\"Blue\">" + name.toUtf8() + "</font>: " + message.toUtf8());
        ui->messageInput->clear();
    }
}

void MainWindow::on_messageInput_returnPressed()
{
    QString name = ui->nameInput->text();
    QString message = ui->messageInput->text();
    if(message.isEmpty())
    {
        ui->chatDisplay->append("Вы не можете отправить пустое сообщение!");
    }
    else
    {
        socket->write("<font color=\"Blue\">" + name.toUtf8() + "</font>: " + message.toUtf8());
        ui->messageInput->clear();
    }
}

void MainWindow::on_clearAllButton_clicked()
{
    ui->chatDisplay->clear();
}

