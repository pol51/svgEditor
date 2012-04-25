#include "view.h"

#include <QtGui/QGridLayout>
#include <QtGui/QDockWidget>
#include <QtGui/QMenuBar>
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

  _svg      = new QSvgWidget();
  _textEdit = new QsciScintilla();
  QDockWidget *SvgView = new QDockWidget(tr("preview"), this);
  SvgView->setWidget(_svg);

  setCentralWidget(_textEdit);

  addDockWidget(Qt::RightDockWidgetArea, SvgView);

  connect(_textEdit,  SIGNAL(textChanged()),
          this,       SLOT(updateSvg()));
}

void View::updateSvg()
{
  _svg->load(_textEdit->text().toUtf8());
}
