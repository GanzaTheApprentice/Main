#ifndef SRC_GRAPHICUS_H_
#define SRC_GRAPHICUS_H_

#include <QVector>
#include <QWidget>
#include <iostream>

namespace Ui {
class Graphicus;
}

class Graphicus : public QWidget {
  Q_OBJECT

 public:
  explicit Graphicus(QWidget *parent = nullptr);
  ~Graphicus();

 private:
  Ui::Graphicus *ui;
  double xBegin, xEnd, step, X, yBeg, yEnd;
  QVector<double> x, y;

 public slots:
  void slotus(QString msg);

 private slots:
  void on_pushButton_make_clicked();
};

#endif  // SRC_GRAPHICUS_H_
