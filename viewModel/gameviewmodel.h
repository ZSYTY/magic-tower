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
    std::function<void(int)> getPlayerChooseCommand();
    std::function<void()> getSaveCommand();
    std::function<void()> getLoadCommand();
    std::function<void()> getRestartCommand();
    std::function<void()> getUseBookCommand();

    void attachModel(const std::shared_ptr<GameModel>& gameModel) noexcept;
    std::shared_ptr<GameModel> detachModel() noexcept;
    std::shared_ptr<Player> getPlayer() const;
    std::shared_ptr<GameMap> getGameMap() const;

private:
    std::shared_ptr<GameModel> m_gameModel;

signals:

};

#endif // GAMEVIEWMODEL_H
