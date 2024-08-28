#include "TRecFolderSelector.h"
#include <QAction>
#include <QFileDialog>
#include <QToolButton>


CTRecFolderSelector::CTRecFolderSelector(QWidget* parent)
    : QLineEdit(parent)
{
    m_action = new QAction(this);
    m_action->setIcon(QPixmap("..//..//Res//Folder.svg"));
    addAction(m_action, QLineEdit::TrailingPosition);
    connect(m_action, &QAction::triggered, this, &CTRecFolderSelector::chooseFolder);
}


void CTRecFolderSelector::chooseFolder()
{
    QString folderName = QFileDialog::getExistingDirectory(
                this,
                tr("Выберете папку для сохранения"),
                "/home",
                QFileDialog::ShowDirsOnly);

    if(!folderName.isEmpty())
    {
        QDir d = QFileInfo(folderName).absoluteDir();
        QString absolutePath = d.absolutePath();
        setText(absolutePath);
        emit editingFinished();
    }
}
