//MENU
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
  void setParentMenu(){} //TODO: Used to return to a previous menu
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

//Communication
typedef struct msgpack {
  int id; //For retransmission
  int type; //What kind of object is being transmitted
  int val; //Which value it being transmitted
  String msg;
} msgpack;

//Basic race structures
//Checkpoint container
typedef struct Checkpoint {
  float lat;
  float lon;
  int id;
  Checkpoint *next;
  int hash;
} Checkpoint;

//Race container
typedef struct Race {
  int id;
  String Name;
  bool looping;
  int8_t laps;
  int hash;
  Checkpoint *checkList;
  int chkpntCount;
} Race;

//Driver class
class Driver {
  private:
    int id; //Device MAC?
    int hash;
    String displayName;
    String make;
    String model;
    String color;
    float zeroToSixty;
    float qMile;
    float qMileSpeed;
    float maxSpeed;
    float thousand;
    float thousandSpd;
  public:
    int hasher(String code){} //Used to generate unique hash for user for identification purposes
};

//Individual driver score object
typedef struct Score {
  Driver *d;
  int raceID;
  //Start time - individual
  //End time
  //pentalties
  int hash;
} Score;

//Final results object
class scoreboard {
  private:
    int id;
    //Start time
    Score *scoreArr; //Results
    Race *race; //The race data
    bool cancelled; //If race was cancelled before all drivers finished
    int startSeed; //Given at the start of the race to all participants
    int endHash; //Finished race uses this for data integrity
  public:
    int generateSeed(){}
    void addToArr(Driver d){}
    void closeRace(){} //creates final hash
};
