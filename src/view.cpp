#include "view.h"

#include <QtGui/QGridLayout>
#include <QtGui/QTextEdit>
#include <QtGui/QSplitter>

#include <QtSvg/QSvgWidget>

View::View(QWidget *parent) :
  QMainWindow(parent)
{
  setWindowTitle("non-graphical Svg Editor");

  _svg      = new QSvgWidget();
  _textEdit = new QTextEdit();

  _splitter = new QSplitter(Qt::Horizontal);
  setCentralWidget(_splitter);

  _splitter->addWidget(_svg);
  _splitter->addWidget(_textEdit);

  connect(_textEdit,  SIGNAL(textChanged()),
          this,       SLOT(updateSvg()));
}

void View::updateSvg()
{
  _svg->load(_textEdit->toPlainText().toUtf8());
}
