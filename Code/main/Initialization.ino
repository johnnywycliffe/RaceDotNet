//TEST CODE
void dummy(){
  Serial.println("dummy");
}
//END TEST CODE

//Menus
//TODO: Add all submenus, replace dummy functions
const int8_t maxArrLen = 10;
String arr1[maxArrLen] = {"Cat & Mouse","P-2-P","Course","Sprint","Drag","Random","Stats",
"Driver Profile","Options","About"};
String arr2[maxArrLen] = {"Two drivers, pass or  pull away","Get from A to B.","Drive a predefined course",
"Drive a predefined route from A to B","Two drivers ASAP to 1/4 mile","Go somewhere, come back","View statistics",
"View and edit profiles","Edit preferences","Other info"};
void (*ptr[maxArrLen])() = {dummy,dummy,dummy,dummy,dummy,dummy,dummy,dummy,dummy,dummy};//CANNOT BE UNINITIALIZED
Menu m(maxArrLen,arr1,arr2,ptr,NULL);
