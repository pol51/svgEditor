#include <QtGui/QApplication>

#include <view.h>

int main(int argc, char *argv[])
{
  QApplication App(argc, argv);

  View MyView;
  MyView.show();

  return App.exec();
}
