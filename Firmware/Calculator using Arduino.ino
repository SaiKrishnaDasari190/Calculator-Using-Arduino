#include <LiquidCrystal.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
//char Operator[15]; 

char keys[ROWS][COLS] = {

                          {'7','8','9','D'},

                          {'4','5','6','C'},

                          {'1','2','3','B'},

                          {'*','0','#','A'}

                        };

byte rowPins[ROWS] = {A0, A1, A2, A3}; 
byte colPins[COLS] = {1, 2, 3, 4};

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
long operand1,operand2,final_Result;
int operand;
char key,Operator;
bool operater_Notpressed,result;
void key_Pressed();
void operand_Calculation();
void result_Calculation();

void setup() 
{
  operand1=0;
  operand2=0;
  operand=0;
  final_Result=0;
  operater_Notpressed = true;
  result = false;
  lcd.begin(16,2);
  lcd.print("Arduino Calculator");
  lcd.setCursor(0,1);
  lcd.print("By Sai Krishna");
  delay(2000);
  lcd.clear();
}

void loop()
{
  key = kpd.getKey();
  if(key!=NO_KEY)
  {
    key_Pressed();
    operand_Calculation();
  }
  if(result==true)
  {
    result_Calculation();
  }
}

void key_Pressed()
{
  if(key=="0"||key=="1"||key=="2"||key=="3"||key=="4"||key=="5"||key=="6"||key=="7"||key=="8"||key=="9")
  {  
    operater_Notpressed = true;
    result = false; 
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
    lcd.print(operand);
  }
  
  else if(key=="A"||key=="B"||key=="C"||key=="D")
  {
    operater_Notpressed = false;
    result = false;    
    if(key=="A")
    {
      Operator="+";
    }
    if(key=="B")
    {
      Operator="-";
    }
    if(key=="C")
    {
      Operator="x";
    }
    if(key=="D")
    {
      Operator="/";
    }
    lcd.print(Operator);   
  }
  
  else if(key=="#")
  {
    operater_Notpressed = true;    
    result = true;
    lcd.print("=");
  }
  else
  {
    operater_Notpressed = true;
    result = false;    
    reset(); //Clear all the number that user entered
    lcd.clear();
  }    
}

void operand_Calculation()
{
  if(operater_Notpressed == true)
  {
    operand1=(operand1*10)+operand;
  }
  else
  {
    operand2=(operand2*10)+operand;
  }

}
void result_Calculation()
{
    if(Operator=="+")
    {
      final_Result = operand1 + operand2;
    }
    if(Operator=="-")
    {
      final_Result = operand1 - operand2;
    }
    if(Operator=="x")
    {
      final_Result = operand1 * operand2;
    }
    if(Operator=="/")
    {
      final_Result = operand1 / operand2;
    }
    lcd.setCursor(0, 1);
    lcd.print(final_Result); 
}
void reset()
{
  operand1=0;
  operand2=0;
  operand=0;
  final_Result=0;
  operater_Notpressed = true;
  result = false;
}
/*
void DisplayResult()
{
   // set the cursor to column 0, line 1 and display the results
  lcd.setCursor(0, 0);  
  lcd.print(operand1); lcd.print(Operator); lcd.print(operand2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(final_Result);}

   // set the cursor to column 0, line 1 and display the result
  lcd.setCursor(0, 1);  
  lcd.print(final_Result);
}
*/
