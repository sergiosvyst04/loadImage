#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->download, &QPushButton::clicked, this, &MainWindow::displayImage);
}

void MainWindow::displayImage()
{


//    ui->verticalLayout->addWidget(ui->label);
    ui->label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    if(pixmap.load(ui->lineEdit->text()))
    {
        pixmap.scaled(ui->label->size(),Qt::KeepAspectRatio);
        ui->label->setPixmap(pixmap);
        ui->label->setScaledContents(true);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
