#ifndef TSPSolver_H
#define TSPSolver_H

#include <QMainWindow>
#include <QPoint>
#include <QSlider>
#include <QGuiApplication>
#include <QScreen>

#include <vector>
#include "graph.hpp"
#include "strategy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TSPSolver; }
QT_END_NAMESPACE


class TSPSolver : public QMainWindow {
    Q_OBJECT

public:
    TSPSolver(tsp::Graph<double, std::vector> &, QWidget * = nullptr);

    ~TSPSolver();

    void print_route(std::vector<unsigned> = {});

    void mousePressEvent(QMouseEvent * = nullptr);

private:

    // variables and consts
    tsp::Graph<double, std::vector> &graph;
    Ui::TSPSolver *ui{nullptr};
    bool addition_vertex_required{false};
    bool removal_vertex_required{false};
    bool run_local_search{false};
    bool run_aco{false};
    bool run_pso{false};
    std::vector <std::unique_ptr<Strategy>> algorithms;
    std::vector <QPoint> array_of_points{0};
    unsigned number_of_threads{1};
    unsigned time_of_running{3};
    unsigned time_of_travel{0};

private
    slots:
            void click_add_vertex();

    void click_remove_vertex();

    void click_clear_graph();

    void run_algorithms();

    void set_time_of_running();

    void set_number_of_threads();
};
#endif // TSPSolver_H
