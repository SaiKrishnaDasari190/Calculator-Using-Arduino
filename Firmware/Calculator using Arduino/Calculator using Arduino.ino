#include <LiquidCrystal.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
//char operator[15]; 

char keys[ROWS][COLS] = {

  {'7','8','9','D'},

  {'4','5','6','C'},

  {'1','2','3','B'},

  {'*','0','#','A'}

};

byte rowPins[ROWS] = {0, 1, 2, 3}; 
byte colPins[COLS] = {4, 5, 6, 7};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
long Operand1,Operand2;
int Key_Operand();
int operand;
char key ;
void setup() 
{
  lcd.begin(16,2);
  lcd.print("Arduino Calculator");
  lcd.setCursor(0,1);
  lcd.print("By Sai Krishna");
  delay(2000);
  
}

void loop()
{
lcd.clear();
int key = keypad.getKey();
if(key!=NO_KEY)
{
  lcd.print("The Pressed Key : ");
  Key_Operand();
  lcd.setCursor(0,1);
  lcd.print(operand);
}
}

int Key_Operand()
{
  if(key=="1")
  {
    operand = 1;
  }
  if(key=="2")
  {
    operand = 2;
  }
  if(key=="3")
  {
    operand = 3;
  }
  if(key=="4")
  {
    operand = 4;
  }
  if(key=="5")
  {
    operand = 5;
  } 
  if(key=="6")
  {
    operand = 6;
  }
  if(key=="7")
  {
    operand = 7;
  } 
  if(key=="8")
  {
    operand = 8;
  }
  if(key=="9")
  {
    operand = 9;
  }
  if(key=="0")
  {
    operand = 0;
  }      
}
/*void Key_Operator()
{
  if(key=="A")
  {
    operator="Addition";
  }
  if(key=="B")
  {
    operator="Subtraction";
  }
  if(key=="C")
  {
    operator="Multiplication";
  }
  if(key=="D")
  {
    operator="Division";
  }
  if(key=="#")
  {
    operator="=";
  }
  if(key=="*")
  {
    operator="clear";
  }
}*/
