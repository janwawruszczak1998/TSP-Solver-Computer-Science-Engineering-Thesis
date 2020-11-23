#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>

#include <vector>
#include "Graph.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent* event);

private:
    Ui::MainWindow *ui{nullptr};
    bool addition_vertex_required{false};
    bool removal_vertex_required{false};
    bool run_local_search{false};
    bool run_aco{false};
    bool run_pso{false};
    std::vector<QPoint> array_of_points{0};
    unsigned number_of_threads{};
    unsigned time_of_running{};

private slots:
    void click_add_vertex();
    void click_remove_vertex();
    void click_clear_graph();
    void run_algorithms();
};
#endif // MAINWINDOW_H
