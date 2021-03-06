#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot()
{
//    demoName = "Scatter Style Demo";
    ui->customPlot->legend->setVisible(false);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->legend->setRowSpacing(-2);
    QVector<QCPScatterStyle::ScatterShape> shapes;

    shapes << QCPScatterStyle::ssDisc;

    QPen pen;
    // add graphs with different scatter styles:
    for (int i=0; i<shapes.size(); ++i)
    {
        ui->customPlot->addGraph();
        pen.setColor(QColor(Qt::blue));
        // generate data:
        QVector<double> x(10), y(10);
        for (int k=0; k<10; ++k)
        {
            x[k] = k/10.0 * 4*3.14 + 0.01;
            y[k] = 7*qSin(x[k])/x[k] + (shapes.size()-i)*5;
        }
        ui->customPlot->graph()->setData(x, y);
        ui->customPlot->graph()->rescaleAxes(true);
        ui->customPlot->graph()->setPen(pen);
        ui->customPlot->graph()->setName(QCPScatterStyle::staticMetaObject.enumerator(QCPScatterStyle::staticMetaObject.indexOfEnumerator("ScatterShape")).valueToKey(shapes.at(i)));
//      ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
        // set scatter style:
        if (shapes.at(i) != QCPScatterStyle::ssCustom)
        {
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(i), 10));
        }
        else
        {
            QPainterPath customScatterPath;
            for (int i=0; i<3; ++i)
                customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::red, 0), QColor(40, 70, 255, 50), 10));
        }
   }
    // set blank axis lines:
    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setTicks(true);
    ui->customPlot->yAxis->setTicks(true);
    ui->customPlot->xAxis->setTickLabels(true);
    ui->customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    ui->customPlot->axisRect()->setupFullAxesBox();
}
