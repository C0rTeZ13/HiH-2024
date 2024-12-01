#include "RecognizeObjects.h"
#include "ui_RecognizeObjects.h"

CRecognizeObjects::CRecognizeObjects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CRecognizeObjects)
{
    ui->setupUi(this);

    ui->widget_objTree->setMinimumSize(QSize(0, 0));

    ui->widget_objTree->hide();
}

CRecognizeObjects::~CRecognizeObjects()
{
    delete ui;
}

void CRecognizeObjects::showRecognizeObj(QMap<QString, QVector<QString> > recObjs)
{
    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *parentItem = model->invisibleRootItem();

    for (const QString &nameObj : recObjs.keys())
    {
        QStandardItem *obj = new QStandardItem(nameObj);

        parentItem->appendRow(obj);

        for (const QString &parametr : recObjs[nameObj])
        {
            obj->appendRow(new QStandardItem(parametr));
        }
    }

    QTreeView *view = new QTreeView(ui->widget_objTree);
    view->setModel(model);

    view->setMinimumHeight(ui->widget_objTree->size().height());
    view->setStyleSheet("QTreeView { font-size: 27px; show-decoration-selected: 0; } QTreeView::branch:has-siblings:!adjoins-item { border-image: none; } QTreeView::branch:has-siblings:adjoins-item { border-image: none; } QTreeView::branch:!has-children:!has-siblings:adjoins-item { border-image: none;} QTreeView::branch:has-children:!has-siblings:closed, QTreeView::branch:closed:has-children:has-siblings { border-image: none; image: url(':images/images/right_arrow.png'); } QTreeView::branch:open:has-children:!has-siblings, QTreeView::branch:open:has-children:has-siblings  { border-image: none; image: url(':images/images/down_arrow.png'); } ");

    ui->widget_objTree->setMinimumSize(QSize(280, 150));
    ui->widget_objTree->show();
}

void CRecognizeObjects::hideRecognizeObj()
{
    ui->widget_objTree->setMinimumSize(QSize(0, 0));
    ui->widget_objTree->hide();
}
