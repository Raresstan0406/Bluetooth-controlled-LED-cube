void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  //pinMode(LED_BUILTIN,OUTPUT);
  for(int i=2;i<14;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void led(int x, int y, int z)
{
  int pin2, pin3, pin4, pin5 , pin6, pin7, pin8, pin9, pin10, pin11, pin12, pin13;
    //bitRead(x,0);
    if(z==0)
    {
      pin4 = 0;
      pin7 = 0;
      digitalWrite(4,pin4);
      digitalWrite(7,pin7);
      //stabilim z=layer 0
      pin3=bitRead(x,1);
      pin2=bitRead(x,0);
      pin6=bitRead(y,1);
      pin5=bitRead(y,0);
      digitalWrite(3,pin3);
      digitalWrite(2,pin2);
      digitalWrite(6,pin6);
      digitalWrite(5,pin5);   
    }
    else if(z==1)
    {
      pin4 = 1;
      pin7 = 1;
      digitalWrite(4,1);
      digitalWrite(7,1);
      //stabilim z=layer 1
      pin3=x/2;
      pin2=x%2;
      digitalWrite(3,pin3);
      digitalWrite(2,pin2);
      pin6=y/2;
      pin5=y%2;
      digitalWrite(6,pin6);
      digitalWrite(5,pin5);   
     }
    else if(z==2)
    {
      pin10 = 0;
      pin13 = 0;
      digitalWrite(10,0);
      digitalWrite(13,0);
      //stabilim z=layer 2
      pin9=bitRead(x,1);
      pin8=bitRead(x,0);
      pin12=bitRead(y,1);
      pin11=bitRead(y,0);
      digitalWrite(9,pin9);
      digitalWrite(8,pin8);
      digitalWrite(12,pin12);
      digitalWrite(11,pin11);  
    }
    else if(z==3)
    {
      pin10 = 1;
      pin13=1;
      digitalWrite(10,1);
      digitalWrite(13,1);
      //stabilim z=layer 3
      pin9=bitRead(x,1);
      pin8=bitRead(x,0);
      pin12=bitRead(y,1);
      pin11=bitRead(y,0);
      digitalWrite(9,pin9);
      digitalWrite(8,pin8);
      digitalWrite(12,pin12);
      digitalWrite(11,pin11);  
    }

}
void test(int d)
{
  digitalWrite(4,0);
  digitalWrite(3,0);
  digitalWrite(2,0);
  delay(d);
  digitalWrite(4,0);
  digitalWrite(3,0);
  digitalWrite(2,1);
  delay(d);
  digitalWrite(4,0);
  digitalWrite(3,1);
  digitalWrite(2,0);
  delay(d);
  digitalWrite(4,0);
  digitalWrite(3,1);
  digitalWrite(2,1);
  delay(d);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,0);
  delay(d);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,1);
  delay(d);
  digitalWrite(4,1);
  digitalWrite(3,1);
  digitalWrite(2,0);
  delay(d);
  digitalWrite(4,1);
  digitalWrite(3,1);
  digitalWrite(2,1);
  delay(d);
  
}

void spirala(int intarziere)
{
  delay(intarziere);
  int x=0, y=0,z=0;
  for(int i=0;i<10;i++)
  {
  for(z=0;z<4;z++)
  {
    for(x=0;x<4;x++)
    {
      y=0;
      led(x,y,z);
      delay(intarziere);
    }
    for(y=0;y<4;y++)
    {
      x=3;
      led(x,y,z);
      delay(intarziere);
    }
    for(x=3;x>=0;x--)
    {
      y=3;
      led(x,y,z);
      delay(intarziere);
    }
    for(y=3;y>=0;y--)
    {
      x=0;
      led(x,y,z);
      delay(intarziere);
    }
  }
  for(z=3;z>=0;z--)
  {
    for(y=0;y<4;y++)
    {
      x=0;
      led(x,y,z);
      delay(intarziere);
    }
    for(x=0;x<4;x++)
    {
      y=3;
      led(x,y,z);
      delay(intarziere);
    }
    for(y=3;y>=0;y--)
    {
      x=3;
      led(x,y,z);
      delay(intarziere);
    }
    for(x=3;x>=0;x--)
    {
      y=0;
      led(x,y,z);
      delay(intarziere);
    }
  }
  }
}
void on_all(int intarziere)
{  
   int x=0, y=0,z=0;
   for(int i=0;i<300;i++)
   {
   for(z=0;z<2;z++)
   {
      for(x=0;x<4;x++)
      {
        for(y=0;y<4;y++)
        {
          led(x,y,z);
          led(x,y,z+2);
          delay(intarziere);
        }
      } 
   }
   }

}

void val(int intarziere_val, int intarziere_layer)
{
  delay(intarziere_val);
  int x=0, y=0,z=0;
  for(int j=0;j<10;j++)
  {
  for(z=0;z<4;z++)
  {
    if(z==0)
    {
      led(x,y,z);
      delay(intarziere_layer+2);
    }
    if(z==1)
    {
      for(int i=0;i<40;i++)
      {
      y=1;
      for(x=0;x<=z;x++)
      {
        y=1; 
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=x-1;y>=0;y--)
      {
        x=z;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==2)
    {
      for(int i=0;i<20;i++)
      {
      y=2;
      for(x=0;x<=z;x++)
      {
        y=2;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=x-1;y>=0;y--)
      {
        x=z;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==3)
    {
      for(int i=0;i<20;i++)
      {
      y=3;
      for(x=0;x<=z;x++)
      {
        y=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=x-1;y>=0;y--)
      {
        x=z;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    delay(intarziere_val);
  }
  for(z=3;z>=0;z--)
  {
    if(z==3)
    {
      for(int i=0;i<20;i++)
      {
      y=0;
      for(x=3;x>=0;x--)
      {
        y=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=x+1;y<=3;y++)
      {
        x=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==2)
    {
      for(int i=0;i<20;i++)
      {
      y=1;
      for(x=3;x>=1;x--)
      {
        y=1;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=x+1;y<=3;y++)
      {
        x=1;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==1)
    {
      for(int i=0;i<40;i++)
      {
      y=2;
      for(x=3;x>=2;x--)
      {
        y=2;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=x+1;y<=3;y++)
      {
        x=2;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==0)
    {
      x=3;
      y=3;
      z=0;
      led(x,y,z);
      delay(intarziere_layer+2);
      
    }
    delay(intarziere_val);
  }
  }
}

void clepsidra(int intarziere_val, int intarziere_layer)
{
  delay(intarziere_layer);
  int x=0, y=0,z=0;
    for(int j=0;j<10;j++)
  {
  for(z=0;z<4;z++)
  {
    if(z==0)
    {
      for(int i=0;i<40;i++)
      {
      for(x=0;x<4;x++)
      {
        y=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=0;y<4;y++)
      {
        x=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(x=3;x>=0;x--)
      {
        y=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=3;y>=0;y--)
      {
        x=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==1)
    {
      for(int i=0;i<50;i++)
      {
        for(x=1;x<3;x++)
        {
          for(y=1;y<3;y++)
          {
            led(x,y,z);
            delay(intarziere_layer);
          }
        }
      }
    }
    if(z==2)
    {
      for(int i=0;i<40;i++)
      {
      for(x=0;x<4;x++)
      {
        y=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=0;y<4;y++)
      {
        x=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(x=3;x>=0;x--)
      {
        y=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=3;y>=0;y--)
      {
        x=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==3)
    {
      for(int i=0;i<50;i++)
      {
      for(x=1;x<3;x++)
        {
          for(y=1;y<3;y++)
          {
            led(x,y,z);
            delay(intarziere_layer);
          }
        }
      }
    }
    
    delay(intarziere_val);
  }
  for(z=3;z>=0;z--)
  {
    if(z==3)
    {
      for(int i=0;i<40;i++)
      {
      for(x=0;x<4;x++)
      {
        y=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=0;y<4;y++)
      {
        x=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(x=3;x>=0;x--)
      {
        y=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=3;y>=0;y--)
      {
        x=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==2)
    {
      for(int i=0;i<50;i++)
      {
        for(x=1;x<3;x++)
        {
          for(y=1;y<3;y++)
          {
            led(x,y,z);
            delay(intarziere_layer);
          }
        }
      }
    }
    if(z==1)
    {
      for(int i=0;i<40;i++)
      {
      for(x=0;x<4;x++)
      {
        y=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=0;y<4;y++)
      {
        x=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(x=3;x>=0;x--)
      {
        y=3;
        led(x,y,z);
        delay(intarziere_layer);
      }
      for(y=3;y>=0;y--)
      {
        x=0;
        led(x,y,z);
        delay(intarziere_layer);
      }
      }
    }
    if(z==0)
    {
      for(int i=0;i<50;i++)
      {
      for(x=1;x<3;x++)
        {
          for(y=1;y<3;y++)
          {
            led(x,y,z);
            delay(intarziere_layer);
          }
        }
      }
    }
    
    delay(intarziere_val);
  }
  }
}
char c;
void loop() {
   if(Serial1.available()){
    c = (char)Serial1.read();
    Serial.println(c);
  }
    if(c=='1')
    {
      on_all(0.01);
    }
    if(c=='2')
    {
      spirala(10);
    }
    if(c=='3')
    {
      val(2,2);
    }
    if(c=='4')
    {
      clepsidra(1,1);
    } 
    delay(1);
      
}
