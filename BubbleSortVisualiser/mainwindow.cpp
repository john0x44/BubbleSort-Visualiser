/*
    Name: mainwindow
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Bubble sort visually implemented
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <ctime>
#include <iostream>
#include <vector>
#include <QCoreApplication>
#include "RectangeClass.h"

// Create a vector to store Rect objects
std::vector<Rect> rectVector;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("BubbleSortVisual");
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(Qt::black);
    srand(time(0));
    int squareSize = 12;
    int sceneWidth = static_cast<int>(this->width());
    int sceneHeight = static_cast<int>(this->height());
    int numSquares = sceneWidth / squareSize;

    // Calculate a random square height
    int yPosition = (sceneHeight - squareSize) / 2;
    for (int i = 0; i < numSquares; i++) {
        QGraphicsRectItem* rectItem = new QGraphicsRectItem(0, sceneHeight / 2, squareSize, -(rand() % 550 + 1));
        rectItem->setBrush(Qt::red);
        scene->addItem(rectItem);
        rectItem->setPos(i * squareSize, yPosition);
        Rect newRect(rectItem);
        rectVector.push_back(newRect);
    }
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// BubbleSort on Rectangle vector
void BubbleSort(QGraphicsView* view)
{
    std::vector<Rect>& thisVector = rectVector;
    int size = thisVector.size();
    bool swap;
    int temp;
    do {
        swap = false;
        for (int i = 0; i < (size - 1); i++) {
            if (thisVector[i].getYH() > thisVector[i + 1].getYH()) {
                // Swap the positions of the Rect objects
                int x1 = thisVector[i].getX();
                int y1 = thisVector[i].getY();
                int x2 = thisVector[i + 1].getX();
                int y2 = thisVector[i + 1].getY();
                thisVector[i].setPos(x2, y2);
                thisVector[i + 1].setPos(x1, y1);
                view->scene()->update();
                QCoreApplication::processEvents();
                std::swap(thisVector[i], thisVector[i + 1]);
                swap = true;
            }
        }
    } while (swap);
}

// Handle client button press
void MainWindow::on_sortButton_clicked()
{
    BubbleSort(ui->graphicsView);
}
