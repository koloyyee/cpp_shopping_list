
#include <iostream>
#include <vector>


enum class Status { ADDED, REMOVED, PURCHASED };

Status &operator--(Status &s) {
  if (s == Status::ADDED) {
    return s = Status::REMOVED;
  }
  return s;
};

Status &operator++(Status &s) {
  if (s == Status::ADDED) {
    return s = Status::PURCHASED;
  }
  return s;
};

std::string to_string(Status s ) {
  switch(s) {
    case (Status::ADDED): return "ADDED";
    case (Status::REMOVED): return "REMOVED";
    case (Status::PURCHASED): return "PURCHASED";
  }
};

class Item {
private:
  std::string name;
  Status status;

public:
  Item(std::string itemName) : name{itemName}, status{Status::ADDED} {}
  int status_int() { return static_cast<int>(status); }
  Status curr_status() { return status; }
  std::string item_name() { return name; }
  void update_status(Status s) { status = s; };
};

int main() {
  bool cont = true;
  std::vector<Item> items;

  while (cont) {
    std::cout << "Enter item add your cart:" << std::endl;
    std::string item_name;
    // cin >> item_name;
    getline(std::cin, item_name); // this accepts space between string.

    items.push_back(Item(item_name));

    std::cout << std::endl;

    std::cout << "Any thing else? Y/N: ";
    std::string choice;
    // cin >> choice;
    getline(std::cin, choice);
    if (choice == "N" || choice == "n") {
      cont = false;
      break;
    }
  }

  for(int i = 0; i < items.size(); ++i)
  {
    char choice;
    std::cout << "Do you want buy " + items[i].item_name()  + "? Y to purchase, N to remove from basket." << std::endl;
    std::cin >> choice;
    switch(choice) {
      case 'Y':
      case 'y':
        items[i].update_status(Status::PURCHASED);
        break;
      case 'N':
      case 'n':
        items[i].update_status(Status::REMOVED);
        break; 
      default:
        break;
    }
  }

  for(auto i : items) 
  {
    std::cout << i.item_name() + " has been " + to_string(i.curr_status()) << std::endl;
  }

  return 0;
}
