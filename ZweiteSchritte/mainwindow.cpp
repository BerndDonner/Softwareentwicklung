#include "mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set up a layout for the central widget
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create a QPushButton and add it to the layout
    QPushButton *button = new QPushButton("Click Me", centralWidget);
    layout->addWidget(button);

}

MainWindow::~MainWindow() {}
