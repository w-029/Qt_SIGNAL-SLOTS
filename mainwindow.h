#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

typedef enum eRowIndex
{
    ROW_1 = 0x00,
    ROW_2 = 0x01,
} eRowIndex;

typedef enum eColumnIndex
{
    COLUMN_1 = 0x00,
    COLUMN_2 = 0x01,
} eLineIndex;

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void on_clickedRow(int columnId);
    void on_clickedColumn(int rowId);

private:
    void initRowGroup();
    void initColumnGroup();

private:
    Ui::MainWindow *ui;
    map<int, QButtonGroup*> rowGroups;
    map<int, QButtonGroup*> columnGroups;
    int clickedRow = -1;
    int clickedColumn = -1;
};

#endif // MAINWINDOW_H
