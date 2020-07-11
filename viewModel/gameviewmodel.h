#ifndef GAMEVIEWMODEL_H
#define GAMEVIEWMODEL_H

#include <memory>
#include <functional>
#include <QObject>
#include "model/gamemodel.h"

class GameViewModel : public QObject
{
    Q_OBJECT
public:
    explicit GameViewModel(QObject *parent = nullptr);
    GameViewModel(const GameViewModel&) = delete;
    GameViewModel& operator=(const GameViewModel&) = delete;

    std::function<void(MagicTower::Direction)> getPlayerMoveCommand();

    void attachModel(const std::shared_ptr<GameModel>& gameModel) noexcept;
    std::shared_ptr<GameModel> detachModel() noexcept;

private:
    std::shared_ptr<GameModel> m_gameModel;

signals:

};

#endif // GAMEVIEWMODEL_H
