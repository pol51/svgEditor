#include "view.h"

#include <QtGui/QDockWidget>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QLabel>

#include <QtSvg/QSvgWidget>

#include <Qsci/qsciscintilla.h>

View::View(QWidget *parent) :
  QMainWindow(parent)
{
  setWindowTitle("non-graphical Svg Editor");

  QMenuBar *Menu = new QMenuBar(this);
  QMenu *FileMenu = Menu->addMenu(tr("File"));
  FileMenu->addAction(tr("Exit"), this, SLOT(close()));
  setMenuBar(Menu);

  QStatusBar *StatusBar = new QStatusBar(this);
  _status = new QLabel(StatusBar);
  StatusBar->addWidget(_status);
  setStatusBar(StatusBar);

  _svg      = new QSvgWidget();
  _textEdit = new QsciScintilla();
  QDockWidget *SvgView = new QDockWidget(tr("preview"), this);
  SvgView->setWidget(_svg);

  setCentralWidget(_textEdit);

  addDockWidget(Qt::RightDockWidgetArea, SvgView);

  connect(_textEdit,  SIGNAL(textChanged()),                    SLOT(updateSvg()));
  connect(_textEdit,  SIGNAL(cursorPositionChanged(int, int)),  SLOT(updateStatus(int, int)));
}

void View::updateSvg()
{
  _svg->load(_textEdit->text().toUtf8());
}

void View::updateStatus(int line, int col)
{
  _status->setText(QString("li=%1 co=%2").arg(line).arg(col));
}
