#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QToolBar>
#include <QBoxLayout>

MainWindow::MainWindow()

{
    QWidget* pWidget = new QWidget(this);
    pWidget->setStyleSheet("background-color: #E0FFFF");
    setCentralWidget(pWidget);

    //main layout
    QVBoxLayout* mainLayout = new QVBoxLayout();
    pWidget->setLayout(mainLayout);

    QLabel* title = new QLabel("Task list", this);
    mainLayout->addWidget(title);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 40pt; margin: 10%;");

    QHBoxLayout* layoutForLabels = new QHBoxLayout();
    mainLayout->addLayout(layoutForLabels);

    QLabel* currentTask = new QLabel("Current Task", this);
    currentTask->setStyleSheet("font-size: 15pt;");
    layoutForLabels->addWidget(currentTask);

    QLabel* completeTask = new QLabel("Completed Task", this);
    completeTask->setStyleSheet("font-size: 15pt;");
    layoutForLabels->addWidget(completeTask);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    mainLayout->addLayout(pHLayout);

    //add drag to models
    m_newTask = new QListView(this);
    m_newTask->setDragEnabled(true);
    m_newTask->setAcceptDrops(true);
    m_newTask->setDropIndicatorShown(true);
    m_newTask->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_newTask);


    m_completedTask = new QListView(this);
    m_completedTask->setDragEnabled(true);
    m_completedTask->setAcceptDrops(true);
    m_completedTask->setDropIndicatorShown(true);
    m_completedTask->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_completedTask);


    m_newTask->setModel(new QStringListModel());
    m_completedTask->setModel(new QStringListModel());

    m_newTask->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #E74C3C; padding: 10%;"
     "border: 1px solid #C0392B; }"
     "QListView::item::hover { background-color: #C0392B }");

    m_completedTask->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #2ECC71; padding: 10%;"
     "border: 1px solid #27AE60; }"
     "QListView::item::hover { background-color: #27AE60 }");

    QToolBar* pToolBar = new QToolBar(this);
    addToolBar(pToolBar);


    m_pActnewTask = new QAction(this);
    m_pActnewTask->setIcon(QIcon(":/resources/add.png"));
    connect(m_pActnewTask, &QAction::triggered, this, &MainWindow::AddTask);

    m_pActcompletedTask = new QAction(this);
    m_pActcompletedTask->setIcon(QIcon(":/resources/remove.png"));
    connect(m_pActcompletedTask, &QAction::triggered, this, &MainWindow::RemoveTask);

    pToolBar->addAction( m_pActnewTask);
    pToolBar->addAction(m_pActcompletedTask);

}

void MainWindow::AddTask()
{
    m_newTask->model()->insertRow(m_newTask->model()->rowCount());
       QModelIndex oIndex = m_newTask->model()->index(
                   m_newTask->model()->rowCount() - 1, 0);

       m_newTask->edit(oIndex);
}

void MainWindow::RemoveTask()
{
    QModelIndex oIndex = m_newTask->currentIndex();
       m_newTask->model()->removeRow(oIndex.row());
}


