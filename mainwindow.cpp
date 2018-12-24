#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define ROW_ONLY 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if ROW_ONLY
    initRowGroup();
#else
    initColumnGroup();
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initRowGroup()
{
    QButtonGroup* row_1 = new QButtonGroup;
    row_1->addButton(ui->checkBox, COLUMN_1);
    row_1->addButton(ui->checkBox_2, COLUMN_2);
    connect(row_1, SIGNAL(buttonClicked(int)), this, SLOT(on_clickedRow(int)));
    this->rowGroups[ROW_1] = row_1;

    QButtonGroup* row_2 = new QButtonGroup;
    row_2->addButton(ui->checkBox_3, COLUMN_1);
    row_2->addButton(ui->checkBox_4, COLUMN_2);
    connect(row_2, SIGNAL(buttonClicked(int)), this, SLOT(on_clickedRow(int)));
    this->rowGroups[ROW_2] = row_2;
}

void MainWindow::on_clickedRow(int columnId)
{
    this->clickedColumn = columnId;
    qDebug() << "clicked column: " << QString::fromStdString(to_string(this->clickedColumn));
}

void MainWindow::initColumnGroup()
{
    QButtonGroup* column_1 = new QButtonGroup;
    column_1->addButton(ui->checkBox, ROW_1);
    column_1->addButton(ui->checkBox_3, ROW_2);
    connect(column_1, SIGNAL(buttonClicked(int)), this, SLOT(on_clickedColumn(int)));
    this->columnGroups[COLUMN_1] = column_1;

    QButtonGroup* column_2 = new QButtonGroup;
    column_2->addButton(ui->checkBox_2, ROW_1);
    column_2->addButton(ui->checkBox_4, ROW_2);
    connect(column_2, SIGNAL(buttonClicked(int)), this, SLOT(on_clickedColumn(int)));
    this->columnGroups[COLUMN_2] = column_2;
}

void MainWindow::on_clickedColumn(int rowId)
{
    this->clickedRow = rowId;
    qDebug() << "clicked row: " << QString::fromStdString(to_string(this->clickedRow));
}
