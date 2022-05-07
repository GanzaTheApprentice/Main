#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  creditCalcWin = new CreditCalc;
  graphicWin = new Graphicus;
  connect(this, &MainWindow::signalus, graphicWin, &Graphicus::slotus);
  connect(this, &MainWindow::cleanSig, creditCalcWin, &CreditCalc::cleaning);

  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_LB, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_RB, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->pushButton_er, SIGNAL(clicked()), this, SLOT(digits()));
  connect(ui->xArea, SIGNAL(selectionChanged()), this, SLOT(xAreaDigs()));
  connect(ui->expArea, SIGNAL(selectionChanged()), this, SLOT(AreaDigs()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::AreaDigs() {
  QString expAr = ui->expArea->text();
  if (expAr.contains("x")) {
    ui->pushButton_ques->setEnabled(true);
  } else {
    ui->pushButton_ques->setEnabled(false);
  }
  if (expAreas == 0) {
    expAreas = 1;
  }
  if (xAreas == 1) {
    xAreas = 0;
  }
}

void MainWindow::xAreaDigs() {
  if (xAreas == 0) {
    xAreas = 1;
  }
  if (expAreas == 1) {
    expAreas = 0;
  }
}

void MainWindow::digits() {
  QPushButton *button = (QPushButton *)sender();
  QString textArea;
  QString textXArea;

  if (expAreas && !xAreas) {
    if (button->text() == "×") {
      textArea = ui->expArea->text() + "*";
    } else if (button->text() == "÷") {
      textArea = ui->expArea->text() + "/";
    } else if (button->text() == "X") {
      textArea = ui->expArea->text() + "x";
      ui->pushButton_ques->setEnabled(true);
    } else if (button->text() == "acos") {
      textArea = ui->expArea->text() + "acos(";
    } else if (button->text() == "asin") {
      textArea = ui->expArea->text() + "asin(";
    } else if (button->text() == "atan") {
      textArea = ui->expArea->text() + "atan(";
    } else if (button->text() == "cos") {
      textArea = ui->expArea->text() + "cos(";
    } else if (button->text() == "sin") {
      textArea = ui->expArea->text() + "sin(";
    } else if (button->text() == "tan") {
      textArea = ui->expArea->text() + "tan(";
    } else if (button->text() == "sqrt") {
      textArea = ui->expArea->text() + "sqrt(";
    } else if (button->text() == "ln") {
      textArea = ui->expArea->text() + "ln(";
    } else if (button->text() == "log") {
      textArea = ui->expArea->text() + "log(";
    } else if (button->text() == "⌫") {
      textArea = ui->expArea->text();
      if (textArea.endsWith("acos") || textArea.endsWith("asin") ||
          textArea.endsWith("atan") || textArea.endsWith("sqrt")) {
        textArea.chop(4);
      } else if (textArea.endsWith("cos") || textArea.endsWith("sin") ||
                 textArea.endsWith("tan") || textArea.endsWith("log")) {
        textArea.chop(3);
      } else if (textArea.endsWith("ln")) {
        textArea.chop(2);
      } else {
        if (textArea.endsWith("x")) {
          ui->pushButton_ques->setEnabled(false);
        }
        textArea.chop(1);
      }
    } else if (button->text() == "AC") {
      ui->pushButton_ques->setEnabled(false);
      ui->expArea->clear();
      ui->xArea->clear();
    } else {
      textArea = ui->expArea->text() + button->text();
    }
    ui->expArea->setText(textArea);
  } else if (!expAreas && xAreas) {
    if (button->text() == "×" || button->text() == "÷" ||
        button->text() == "+" || button->text() == "%" ||
        button->text() == "(" || button->text() == ")" ||
        button->text() == "X" || button->text() == "acos" ||
        button->text() == "asin" || button->text() == "atan" ||
        button->text() == "cos" || button->text() == "sin" ||
        button->text() == "tan" || button->text() == "sqrt" ||
        button->text() == "ln" || button->text() == "log" ||
        button->text() == "^") {
      textXArea = ui->xArea->text();
    } else if (button->text() == "⌫") {
      textXArea = ui->xArea->text();
      if (textArea.endsWith("x")) {
        ui->pushButton_ques->setEnabled(false);
      }
      textXArea.chop(1);
    } else if (button->text() == "AC") {
      ui->expArea->clear();
      ui->xArea->clear();
      ui->pushButton_ques->setEnabled(false);
    } else {
      textXArea = ui->xArea->text() + button->text();
    }
    ui->xArea->setText(textXArea);
  }
}

void MainWindow::on_pushButton_eq_clicked() {
  QString textArea = ui->expArea->text();
  QString xArea = ui->xArea->text();
  if (textArea.isEmpty()) {
  } else {
    std::string tmpArea = textArea.toUtf8().data();
    char tmpCharArea[256] = "\0";
    strcpy(tmpCharArea, tmpArea.c_str());
    std::string tmpXArea = xArea.toUtf8().data();
    char tmpCharXArea[256] = "\0";
    strcpy(tmpCharXArea, tmpXArea.c_str());
    setlocale(LC_NUMERIC, "C");
    QString result;
    result = QString("%1").arg(calc(tmpCharArea, tmpCharXArea));
    if (result.contains("incorrect input")) {
      QMessageBox *error = new QMessageBox;
      error->setWindowTitle("Ошибка!");
      error->setText("Одна ошибка и ты ошибся!\n(Некорректный ввод)");
      error->show();
    } else {
      ui->expArea->setText(result);
    }
  }
}

void MainWindow::on_creditus_triggered() {
  creditCalcWin->setWindowTitle("Кредитный калькулятор");
  creditCalcWin->show();
  emit cleanSig();
}

void MainWindow::on_pushButton_ques_clicked()
{
  graphicWin->setWindowTitle("Построение графиков");
  graphicWin->show();
  emit signalus(ui->expArea->text());
}

