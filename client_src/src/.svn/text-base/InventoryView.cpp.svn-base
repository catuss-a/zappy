#include <sstream>

#include "InventoryView.hpp"
#include "Core.hpp"

namespace			Game
{
  InventoryView::InventoryView() :
    GObject(Image::INVENTORYVIEW), player(NULL),
    stones(7), labels(7), resources(7), timer(1)
  {
    this->labels[0].SetScale(0.7, 0.7);
    for (size_t i = 1; i < this->labels.size(); ++i)
      this->labels[i].SetScale(0.6, 0.6);
    this->stones[0] = "Nourriture";
    this->stones[1] = "Linemate";
    this->stones[2] = "Deraumere";
    this->stones[3] = "Sibur";
    this->stones[4] = "Menbiane";
    this->stones[5] = "Phiras";
    this->stones[6] = "Thystane";

    this->resources[0] = new GObject(Image::FOOD);
    this->resources[1] = new GObject(Image::DOFUS1);
    this->resources[2] = new GObject(Image::DOFUS2);
    this->resources[3] = new GObject(Image::DOFUS3);
    this->resources[4] = new GObject(Image::DOFUS4);
    this->resources[5] = new GObject(Image::DOFUS5);
    this->resources[6] = new GObject(Image::DOFUS6);

    this->resources[0]->SetScale(0.5, 0.5);
    this->resources[1]->SetScale(0.5, 0.5);
    this->resources[2]->SetScale(0.5, 0.5);
    this->resources[3]->SetScale(0.5, 0.5);
    this->resources[4]->SetScale(0.5, 0.5);
    this->resources[5]->SetScale(0.5, 0.5);
    this->resources[6]->SetScale(0.5, 0.5);
  }

  void InventoryView::launch(void) {}

  void InventoryView::update(void)
  {
    Coord const& coord = Core::window.GetDefaultView().GetCenter();
    Coord pos;

    pos.x = coord.x - Core::window.getWidth() / 2 + 180;
    pos.y = coord.y + Core::window.getHeight() / 2 - this->GetSize().y;
    this->SetPosition(pos.x, pos.y);
    this->resources[0]->SetPosition(pos.x + 10, pos.y + 5);
    this->resources[1]->SetPosition(pos.x + 210, pos.y + 5);
    this->resources[2]->SetPosition(pos.x + 410, pos.y + 5);
    this->resources[3]->SetPosition(pos.x + 610, pos.y + 5);
    this->resources[4]->SetPosition(pos.x + 10, pos.y + 50);
    this->resources[5]->SetPosition(pos.x + 210, pos.y + 50);
    this->resources[6]->SetPosition(pos.x + 410, pos.y + 50);
    if (!this->player)
      return ;
    this->labels[0].SetPosition(pos.x + 50, pos.y + 5);
    this->labels[1].SetPosition(pos.x + 250, pos.y + 5);
    this->labels[2].SetPosition(pos.x + 450, pos.y + 5);
    this->labels[3].SetPosition(pos.x + 650, pos.y + 5);
    this->labels[4].SetPosition(pos.x + 50, pos.y + 50);
    this->labels[5].SetPosition(pos.x + 250, pos.y + 50);
    this->labels[6].SetPosition(pos.x + 450, pos.y + 50);
    if (--this->timer)
      return ;
    std::stringstream	ss;
    ss << "pin ";
    ss << this->player->getNum();
    ss << "\n";
    Core::socket.send(ss.str());
    this->timer = 20;
  }

  void InventoryView::draw(void)
  {
    GObject::draw();
    for (size_t i = 0; i < this->resources.size(); ++i)
      this->resources[i]->draw();
    if (!this->player)
      return ;

    InventoryVector const& inventory = this->player->getInventory();
    std::stringstream ss;

    for (size_t i = 0; i < this->labels.size(); ++i)
      {
	ss.str("");
	ss.clear();
	ss << this->stones[i];
	ss << ": ";
	ss << inventory[i];
	this->labels[i].SetText(ss.str());
	Core::window.Draw(this->labels[i]);
      }
  }

  void InventoryView::setPlayer(Player* player)
  {
    this->player = player;
  }

  InventoryView::~InventoryView(void) {}
}

