//of the Arduino Board, refer to www.Surtrtech.com for more information
#include <Arduino.h>
#include <IRremote.h>   // Referring to the IRRemote function library, the header file 
                        //has defined PIN 3 as the signal output, so it can only connect 
                        //to PIN 3. If change, please change it in the header file  
const int bit3 = 6 ; //Declaring where the Out pin from the sensor is wired
const int bit2 = 4 ;
const int bit1 = 7 ;
const int bit0 = 5 ;
const int checkbit = 8;
#include "PinDefinitionsAndMore.h"

IRsend irsend;

// 2^3  2^2   2^1   2^0  (+)
// bit3 bit2  bit1  bit0 checkbit
// 0    0     0     0     1        = 0  -- aç/kapat
// 0    0     0     1     0        = 1  -- kanal 1
// 0    0     1     0     0        = 2  -- kanal 2
// 0    0     1     1     0        = 3  -- kanal 3
// 0    1     0     0     0        = 4  -- kanal 4
// 0    1     0     1     0        = 5  -- kanal 5
// 0    1     1     0     0        = 6  -- kanal 6 
// 0    1     1     1     0        = 7  -- kanal 7
// 1    0     0     0     0        = 8  -- kanal 8
// 1    0     0     1     0        = 9  -- kanal 9
// 1    0     1     0     0        = 10 -- kanal 0
// 1    1     1     0     0        = 11 -- ses arttırma
// 1    1     0     0     0        = 12 -- ses azaltma
// 0    0     1     1     1        = 13 -- kanal arttırma
// 0    0     0     1     1        = 14 -- kanal azaltma
// 1    1     1     1     0        = 15 -- mute



void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);

    // Just to know which program is running on my Arduino
    //Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * The IR library setup. That's all!
     */
    //IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}

void loop() {
         if (digitalRead(bit3)==HIGH && digitalRead(bit2)==HIGH && digitalRead(bit1)==HIGH && digitalRead(bit0)==LOW && digitalRead(checkbit)==HIGH )      //Check the sensor output if it's high -- 1
             {
               
               Serial.print("1 tuşu yollandı\n");
               unsigned int raw[68] = {4550,4400,600,1600,600,1650,600,1600,600,550,550,550,600,550,550,550,550,550,550,1650,600,1600,600,1650,600,500,600,500,600,550,600,500,600,500,600,500,600,550,550,1650,600,500,600,550,550,550,600,500,600,500,600,1650,600,1600,600,500,600,1650,600,1600,600,1650,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
               
             }
          else if(digitalRead(bit3)==HIGH && digitalRead(bit2)==HIGH && digitalRead(bit1)==LOW && digitalRead(bit0)==HIGH && digitalRead(checkbit)==HIGH )      //Check the sensor output if it's high -- 2
             {
               
               Serial.print("2 tuşu yollandı\n");
               unsigned int raw[68] = {4500,4450,600,1600,600,1650,600,1600,600,500,600,550,600,500,600,500,600,500,600,1650,600,1600,600,1650,600,500,600,500,600,500,600,500,600,550,600,1600,600,500,600,1650,600,500,600,500,600,550,550,550,600,500,600,500,600,1650,600,500,600,1600,600,1650,600,1600,600,1650,600,1550,700,};
               irsend.sendRaw(raw,68,38);


               delay(1500);
  
             }
          else if(digitalRead(bit3)==HIGH && digitalRead(bit2)==HIGH && digitalRead(bit1)==LOW && digitalRead(bit0)==LOW && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 3
             {
               
               Serial.print("3 tuşu yollandı\n");
               unsigned int raw[68] = {4550,4400,600,1650,550,1650,600,1600,600,550,600,500,600,500,600,500,600,550,550,1650,600,1600,600,1650,600,500,600,500,600,550,550,550,600,500,600,500,600,1650,600,1600,600,500,600,550,600,500,600,500,600,500,600,1650,600,500,600,500,600,1650,600,1550,650,1650,550,1650,600,1600,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }
          else if(digitalRead(bit3)==HIGH && digitalRead(bit2)==LOW && digitalRead(bit1)==HIGH && digitalRead(bit0)==HIGH && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 4
             {
               
               Serial.print("4 tuşu yollandı\n");
               unsigned int raw[68] = {4500,4400,600,1650,600,1600,600,1650,600,500,600,500,600,500,600,550,600,500,600,1600,600,1650,600,1600,600,500,600,550,600,500,600,500,600,500,600,550,600,500,600,500,600,1600,600,550,600,500,600,500,600,500,600,1650,600,1600,600,1650,600,500,600,1600,600,1650,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }   
 
           else if(digitalRead(bit3)==HIGH && digitalRead(bit2)==LOW && digitalRead(bit1)==HIGH && digitalRead(bit0)==LOW && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 5
             {
               
               Serial.print("5 tuşu yollandı\n");
               unsigned int raw[68] = {4550,4450,550,1650,600,1600,600,1650,600,500,600,500,600,550,550,550,600,500,600,1600,600,1650,600,1600,600,550,550,550,600,500,600,500,600,500,600,1650,600,500,600,500,600,1650,600,500,600,500,600,550,550,550,600,500,600,1600,600,1650,600,500,600,1650,550,1650,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }
  
            else if(digitalRead(bit3)==HIGH && digitalRead(bit2)==LOW  && digitalRead(bit1)==LOW && digitalRead(bit0)==HIGH && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 6
             {
               
               Serial.print("6 tuşu yollandı\n");
               unsigned int raw[68] = {4500,4400,600,1650,600,1600,600,1650,600,500,600,500,600,550,550,550,600,500,600,1600,600,1650,600,1600,600,550,550,550,600,500,600,500,600,500,600,550,600,1600,600,500,600,1650,600,500,600,500,600,550,550,550,600,1600,600,500,600,1650,600,500,600,1650,550,1650,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);


               delay(1500);
  
             }
  
            else if(digitalRead(bit3)==HIGH && digitalRead(bit2)==LOW  && digitalRead(bit1)==LOW && digitalRead(bit0)==LOW  && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 7
             {
               
               Serial.print("7 tuşu yollandı\n");
               unsigned int raw[68] = {4550,4400,600,1650,600,1600,650,1600,550,550,600,550,550,550,550,550,550,550,600,1500,700,1650,550,1650,600,550,550,550,550,550,600,550,550,500,600,500,600,550,600,1600,600,1650,550,550,600,550,550,500,650,500,550,1650,600,1600,600,550,550,550,600,1600,600,1650,600,1600,600,1650,550,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }
  
            else if(digitalRead(bit3)==LOW && digitalRead(bit2)==HIGH && digitalRead(bit1)==HIGH && digitalRead(bit0)==HIGH && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 8
             {
               
               Serial.print("8 tuşu yollandı\n");
               unsigned int raw[68] = {5850,3350,600,1600,600,1650,600,1600,600,500,600,550,550,550,600,500,600,500,600,1650,600,1600,600,1600,600,550,600,500,600,500,600,500,600,550,600,1600,600,500,600,1650,600,1600,600,500,600,550,600,500,600,500,600,500,600,1650,600,550,550,500,600,1650,600,1600,600,1650,600,1600,600,};
               irsend.sendRaw(raw,68,38);
               delay(1500);
  
             }

             else if(digitalRead(bit3)==LOW && digitalRead(bit2)==HIGH && digitalRead(bit1)==HIGH && digitalRead(bit0)==LOW && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 9
             {
               
               Serial.print("9 tuşu yollandı\n");
               unsigned int raw[68] = {4550,4400,600,1650,550,1650,600,1600,600,550,600,500,600,550,550,550,550,550,600,1600,600,1650,550,1650,600,550,550,550,550,550,600,500,600,550,550,550,550,1650,600,1600,600,1650,600,550,550,550,550,550,550,550,600,1600,600,550,550,550,550,550,600,1600,600,1650,550,1650,600,1650,550,};
               irsend.sendRaw(raw,68,38);
               delay(1500);
  
             }

             else if(digitalRead(bit3)==LOW && digitalRead(bit2)==HIGH && digitalRead(bit1)==LOW && digitalRead(bit0)==HIGH && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- 0
             {
               
               Serial.print("0 tuşu yollandı\n");
               unsigned int raw[68] = {4550,4400,600,1650,550,1650,600,1600,600,550,550,550,600,550,550,550,550,550,550,1650,600,1650,550,1650,600,550,550,550,550,550,550,550,600,500,600,1600,600,550,550,550,600,550,550,1650,550,550,600,550,550,550,550,550,550,1650,600,1600,600,1650,600,550,550,1600,600,1650,600,1600,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }

             else if(digitalRead(bit3)==LOW && digitalRead(bit2)==LOW && digitalRead(bit1)==LOW )      //Check the sensor output if it's high  -- VOL UP
             {
               
               Serial.print("VOL UP tuşu yollandı\n");
               unsigned int raw[68] = {4500,4450,600,1600,600,1600,600,1650,600,500,600,500,600,550,600,500,600,500,600,1650,550,1650,600,1600,600,550,600,500,600,500,600,500,600,550,550,1650,600,1600,600,1650,600,500,600,500,600,550,550,550,600,500,600,500,600,550,550,550,600,1600,600,1650,550,1650,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);

               delay(100);
  
             }

             else if(digitalRead(bit3)==LOW && digitalRead(bit2)==LOW && digitalRead(bit1)==HIGH )      //Check the sensor output if it's high -- VOL DOWN
             {
               
               Serial.print("VOL DOWN tuşu yollandı\n");
               unsigned int raw[68] = {4500,4450,600,1600,600,1600,600,1650,600,550,550,550,550,550,550,550,600,550,550,1650,550,1650,600,1600,600,550,550,550,600,550,550,550,550,550,550,1650,600,1600,600,550,600,1600,600,550,550,550,550,550,600,550,550,550,550,550,550,1650,600,550,550,1650,600,1600,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);
               delay(100);
  
             }

             else if(digitalRead(checkbit)==LOW && digitalRead(bit1)==LOW && digitalRead(bit0)==LOW)      //Check the sensor output if it's high -- CH UP
             {
               
               Serial.print("CH UP tuşu yollandı\n");
               unsigned int raw[68] = {4500,4450,600,1600,600,1650,550,1650,600,550,550,550,550,550,600,550,550,550,550,1650,550,1650,600,1650,550,550,600,550,550,550,550,550,550,550,600,550,550,1600,600,550,550,550,600,1600,600,550,550,550,600,550,550,1600,600,550,600,1600,600,1650,550,550,600,1600,600,1650,600,1600,600,};
               irsend.sendRaw(raw,68,38);
               delay(1500);
  
             }

             else if(digitalRead(checkbit)==LOW && digitalRead(bit1)==HIGH && digitalRead(bit0)==LOW )      //Check the sensor output if it's high -- CH DOWN
             {
               
               Serial.print("CH DOWN tuşu yollandı\n");
               unsigned int raw[68] = {4450,4450,550,1700,550,1650,600,1650,550,600,500,600,550,550,550,550,550,600,500,1650,600,1650,550,1650,600,550,550,550,550,600,500,600,550,550,500,600,550,600,500,600,550,550,550,1650,550,600,500,600,550,550,550,1650,550,1700,550,1650,550,1700,500,600,550,1700,500,1700,550,1650,550,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }

             else if(digitalRead(bit3)==LOW && digitalRead(bit2)==LOW && digitalRead(bit1)==LOW && digitalRead(bit0)==LOW && digitalRead(checkbit)==HIGH)      //Check the sensor output if it's high -- MUTE
             {
               
               Serial.print("MUTE tuşu yollandı\n");
               unsigned int raw[68] = {4500,4400,600,1650,600,1600,600,1650,600,550,550,550,550,550,550,550,600,550,550,1600,600,1650,600,1600,600,550,550,550,600,550,550,550,550,550,550,1650,600,1600,600,1650,600,1600,600,550,550,550,600,550,550,550,550,550,550,550,600,500,600,550,550,1650,550,1650,600,1600,600,1650,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }

             else if(digitalRead(checkbit)== LOW && digitalRead(bit3)==HIGH && digitalRead(bit2)==HIGH && digitalRead(bit1)==HIGH && digitalRead(bit0)==HIGH)      //Check the sensor output if it's high - ON/OFF
             {
               
               Serial.print("ON/OFF tuşu yollandı\n");
               unsigned int raw[68] = {4500,4450,550,1650,600,1600,600,1650,600,550,550,550,550,550,600,500,600,550,550,1650,550,1650,600,1600,600,550,600,500,600,550,550,550,550,550,550,550,600,1600,600,550,550,550,600,550,550,550,550,550,550,550,600,1600,600,550,550,1650,600,1600,600,1650,600,1600,600,1650,550,1650,600,};
               irsend.sendRaw(raw,68,38);

               delay(1500);
  
             }
    
  

            else
            {
              //digitalWrite(13, HIGH);    // Turn the LED OFF if there's no signal on the ProxSensor
              Serial.print("Kumanda komutu yok\n");
              delay(500);



              
             }            

}
