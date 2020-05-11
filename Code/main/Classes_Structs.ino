struct MenuItem {
  String title;
  String subtitle;
  void (*func)();
};

class Menu {
private:
  MenuItem *arr;
  Menu *prevMenu;
  int8_t selector;
  int8_t arrLen;
public:
  Menu(int8_t arrlength, String *titleArr, String *subArr, void (*ptr[])(),Menu *parent){
    arr = new MenuItem[arrlength];
    arrLen = arrlength;
    for (int8_t i=0;i<arrLen;i++){
      arr[i].title = titleArr[i];
      arr[i].subtitle = subArr[i];
      arr[i].func = ptr[i];
    }
    selector = 0;
    prevMenu = parent;
  };
  ~Menu(){
    delete[] arr;
  }
  void setParentMenu(){} //Used to return to a previous menu
  int8_t runMenu(){
    bool inProg = true;
    do{
      int8_t output = input(selector,arrLen);
      switch(output){
        case SELECT: //Selection made
          arr[selector].func();
          inProg = false;
          break;
        case BACK: //Back button
          if (prevMenu != NULL){
            inProg = false;
            //prevMenurunMenu();
          } else {
            //Do nothing
          }
          break;
        default: //Update screen
          String dTitle = arr[output].title;
          String dSubtitle = arr[output].subtitle;
          bool upArrow = true;
          bool downArrow = true;
          if (output == 0){
            upArrow = false;
          }
          if (output == arrLen-1){
            downArrow = false;
          }
          drawMenuScreen(dTitle,dSubtitle, upArrow, downArrow);
          delay(1000); //REMOVE
          break;
      } 
    } while (inProg);
  }
};
