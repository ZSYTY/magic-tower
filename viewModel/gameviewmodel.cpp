#include "gameviewmodel.h"

GameViewModel::GameViewModel(QObject *parent) : QObject(parent)
{

}


std::function<void(MagicTower::Direction)> GameViewModel::getPlayerMoveCommand() {
    return [this] (MagicTower::Direction dir) {
        return this->m_gameModel->playerMove(dir);
    };
}

std::function<void(int)> GameViewModel::getPlayerChooseCommand() {
    return [this] (int choice) {
        return this->m_gameModel->playerChoose(choice);
    };
}

void GameViewModel::attachModel(const std::shared_ptr<GameModel>& gameModel) noexcept {
    m_gameModel = gameModel;
}

std::shared_ptr<GameModel> GameViewModel::detachModel() noexcept {
    return std::shared_ptr<GameModel>(std::move(m_gameModel));
}

std::shared_ptr<Player> GameViewModel::getPlayer() const {
    return m_gameModel->getPlayer();
}

std::shared_ptr<GameMap> GameViewModel::getGameMap() const{
    return m_gameModel->getGameMap();
}
