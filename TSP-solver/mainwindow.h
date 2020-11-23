#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    Ui::MainWindow *ui;
    bool adding_vertex_required = false;
    bool removing_vertex_required = false;

private slots:
    void click_add_vertex();
    void click_remove_vertex();
    void click_clear_graph();
};
#endif // MAINWINDOW_H
