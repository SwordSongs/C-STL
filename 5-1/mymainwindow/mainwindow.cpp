#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QMenu>
//#include <QAction>
//#include <QIcon>
//#include <QKeySequence>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加编辑菜单
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction *action_Open = editMenu->addAction(QIcon(":/image/images/1033.png"), tr("Open(&O)"));

    action_Open->setShortcut(QKeySequence("Ctrl + O"));
    ui->mainToolBar->addAction(action_Open);
}

MainWindow::~MainWindow()
{
    delete ui;
}
