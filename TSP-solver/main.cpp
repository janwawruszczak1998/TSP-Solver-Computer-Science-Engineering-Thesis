#include "tspsolver.h"
#include "graph.hpp"

#include <QApplication>
#include <QScreen>
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    tsp::Graph<double, std::vector> graph{};
    TSPSolver w(graph);
    w.setWindowTitle("TSP Solver");
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
