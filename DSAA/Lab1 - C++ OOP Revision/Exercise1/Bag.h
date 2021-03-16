#ifndef BAG_H
#define BAG_H

class Bag{
 public:
  Bag(float = 15.6, int = 5);
  bool setSize(float);
  bool setSlots(int);
  bool setPrice(float);
  float getSize();
  int getSlots();
  float getPrice();
  int Compare(Bag);
  void PrintInfo();
  void ReadInfo();

 private:
  float size;
  int slots;
  float price;
};

#endif
