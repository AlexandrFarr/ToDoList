#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected slots:
   void AddTask();
   void RemoveTask();

private:
   QListView* m_newTask = nullptr;
   QListView* m_completedTask = nullptr;

   QAction* m_pActnewTask = nullptr;
   QAction* m_pActcompletedTask = nullptr;
};
#endif // MAINWINDOW_H
