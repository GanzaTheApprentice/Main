#include "graphicus.h"

#include "mainwindow.h"
#include "ui_graphicus.h"

Graphicus::Graphicus(QWidget *parent) : QWidget(parent), ui(new Ui::Graphicus) {
  ui->setupUi(this);
}

Graphicus::~Graphicus() { delete ui; }

void Graphicus::slotus(QString msg) {
  ui->expLabel->setText(msg);
  x.clear();
  y.clear();
  ui->gWin->addGraph();
  ui->gWin->graph(0)->setData(x, y);
  ui->gWin->xAxis->setLabel("x");
  ui->gWin->yAxis->setLabel("y");
  ui->gWin->xAxis->setRange(0, 5);
  ui->gWin->yAxis->setRange(0, 5);
  ui->gWin->replot();
}

void Graphicus::on_pushButton_make_clicked() {
  bool isNum1, isNum2;
  QString qBeg = ui->fromArea->text(), qEnd = ui->toArea->text();

  xBegin = qBeg.toDouble(&isNum1);
  X = xBegin;
  xEnd = qEnd.toDouble(&isNum2);
  step = fabs(xBegin - xEnd) / 10000;

  if (isNum1 && isNum2 && xBegin < xEnd) {
    x.clear();
    y.clear();

    QString result, qLabel = ui->expLabel->text();
    std::string tmpArea = qLabel.toUtf8().data();
    char expChar[256] = "\0";
    strcpy(expChar, tmpArea.c_str());

    yBeg = 0;
    yEnd = 0;
    for (; xBegin < xEnd; xBegin += step) {
      char xBegChar[256] = "\0";
      std::cout << sprintf(xBegChar, "%.10f", xBegin);
      setlocale(LC_NUMERIC, "C");
      result = QString("%1").arg(calc(expChar, xBegChar));
      if (yBeg > result.toDouble()) {
        yBeg = result.toDouble();
      } else if (yEnd < result.toDouble()) {
        yEnd = result.toDouble();
      }
      y.push_back(result.toDouble());
      x.push_back(xBegin);
    }

    ui->gWin->addGraph();
    ui->gWin->graph(0)->setData(x, y);
    ui->gWin->xAxis->setLabel("x");
    ui->gWin->yAxis->setLabel("y");
    ui->gWin->xAxis->setRange(X, xEnd);
    ui->gWin->yAxis->setRange(yBeg, yEnd);
    ui->gWin->replot();
    ui->fromArea->clear();
    ui->toArea->clear();
  } else {
    QMessageBox *error = new QMessageBox;
    error->setWindowTitle("Ошибка!");
    error->setText("Одна ошибка и ты ошибся!\n(Некорректный ввод)");
    error->show();
  }
}
