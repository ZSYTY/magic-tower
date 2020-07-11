#include "gameviewmodel.h"

GameViewModel::GameViewModel(QObject *parent) : QObject(parent)
{

}


std::function<void(MagicTower::Direction)> GameViewModel::getPlayerMoveCommand() {
    return [this] (MagicTower::Direction dir) {
        return this->m_gameModel->playerMove(dir);
    };
}

void GameViewModel::attachModel(const std::shared_ptr<GameModel>& gameModel) noexcept {
    m_gameModel = gameModel;
}

std::shared_ptr<GameModel> GameViewModel::detachModel() noexcept {
    return std::shared_ptr<GameModel>(std::move(m_gameModel));
}
