#ifndef __VIEW_H__
#define __VIEW_H__

#include <QtGui/QMainWindow>

class QGridLayout;
class QSvgWidget;
class QTextEdit;
class QSplitter;

class View : public QMainWindow
{
  Q_OBJECT

  public:
    View(QWidget *parent = NULL);

  protected slots:
    void updateSvg();

  protected:
    QWidget       *_centralW;
    QGridLayout   *_layout;
    QSvgWidget    *_svg;
    QTextEdit     *_textEdit;
    QSplitter     *_splitter;
};

#endif
