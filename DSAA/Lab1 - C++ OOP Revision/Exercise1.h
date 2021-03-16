#ifndef BAG_H
#define BAG_H

class Bag{
 public:
  Bag(float mySize = 15.6, int mySlots = 5);
  bool setSize(float mySize);
  bool setSlots(int mySlots);
  bool setPrice(float myPrice);
  float getSize();
  int getSlots();
  float getPrice;
  int Compare(Bag otherBag);
  void PrintInfo();
  void ReadInfo();

 private:
  float size;
  int slots;
  float price;
};

#endif
