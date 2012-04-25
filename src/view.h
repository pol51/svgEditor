#ifndef __VIEW_H__
#define __VIEW_H__

#include <QtGui/QMainWindow>

class QSvgWidget;
class QLabel;
class QsciScintilla;

class View : public QMainWindow
{
  Q_OBJECT

  public:
    View(QWidget *parent = NULL);

  protected slots:
    void updateSvg();
    void updateStatus(int line, int col);

  protected:
    QWidget       *_centralW;
    QLabel        *_status;
    QSvgWidget    *_svg;
    QsciScintilla *_textEdit;
};

#endif
