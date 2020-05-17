//Get message data and put it into he correct place
void processMsg(){
  //Get data from struct
  int id = incomingData.id;
  int type = incomingData.type;
  int val = incomingData.val;
  String msg = incomingData.msg;
  
  //Check id and type to see if object exists
  switch(type){
    case RACE:
      //Create new object if not existing, grab existing object otherwise
      //Another switch for val
      //copy data into field
      break;
    case DRIVER:
      break;
    case CHKPNT:
      break;
    case SCORE:
      break;
    case SCOREBRD:
      break;
  }
}
