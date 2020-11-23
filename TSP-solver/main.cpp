#include "mainwindow.h"
#include "Graph.hpp"

#include <QApplication>

tsp::Graph<double, std::vector> graph;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("TSP Solver");
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
