//Controlling 2 RGB LED strips via 1 particle photon over the internet
#include <string>
//set pinout
int led4 = D0;
int led5 = D1;
int led6 = D2;

int led1 = D3;
int led2 = RX;
int led3 = TX;
//initialize variables
double r1 = 0, g1 = 0, b1 = 0, r2 = 0, b2 = 0, g2 = 0, dim = 0;

String print, t;
bool nightTime = false, party = false, userColor = false, strobe = false, rain = false, initParty = false, initRain = true, rainOff = false, initNight = true, nightOff = false;

Timer timer(7200000, LEDTimeOut);
//setup
void setup()
{
    timer.start();
    
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    
    Particle.function("led",ledToggle);
    Particle.function("led2",ledToggle2);
    Particle.function("dim",ledDim);
    Particle.variable("color", &print, STRING);
}
//main loop
void loop()
{
    while(strobe == true)
    {
        initNight = true;
        analogWrite(led1, r1);
        analogWrite(led2, g1);
        analogWrite(led3, b1);
        analogWrite(led4, r2);
        analogWrite(led5, g2);
        analogWrite(led6, b2);
        delay(25);
        analogWrite(led1, 0);
        analogWrite(led2, 0);
        analogWrite(led3, 0);
        analogWrite(led4, 0);
        analogWrite(led5, 0);
        analogWrite(led6, 0);
        delay(25);
    }

    while(party == true)
    {
        if(initParty == true)
        {
            changeLEDColor(255, 0, 0, 0, 255, 0);   
            initParty = false;
        }
        else
        {
        int r = 255;
        int g = 0;
        int b = 0;
        for( int i = 0 ; i < 255 && party == true  ; i += 1 )
        {
            g += 1;
            r -= 1;
            analogWrite(led2,  g );
            analogWrite(led1,  r );
            analogWrite(led6,  g );
            analogWrite(led5,  r );
            delay(5);
        }
        r = 0;
        b = 0;
        g = 255;
        for( int i = 0 ; i < 255 && party == true ; i += 1 )
        {
            b += 1;
            g -= 1;
            analogWrite( led3,  b );
            analogWrite( led2,  g );
            analogWrite( led4,  b );
            analogWrite( led6,  g );
            delay(5);
        }
        r = 0;
        b = 255;
        g = 0;
        for( int i = 0 ; i < 255 && party == true ; i += 1 )
        {
            r += 1;
            b -= 1;
            analogWrite( led1,  r );
            analogWrite( led3,  b);
            analogWrite( led4,  b );
            analogWrite( led5,  r);
            delay(5);
        }
        }
    }
    
    if(rain == true && userColor == false && nightTime == false)
    {
        if(initRain == true)
        {
        changeLEDColor(0,0,0,100,0,0);
        initRain = false;
        }
        else
        {
           
        }
    }
    else if(rainOff == true)
    {
        changeLEDColor(0,0,0,0,0,0);
        rainOff = false;
    }
    else if(nightTime == true && userColor == false && rain == false)
    {
        if(initNight == true)
        {
        changeLEDColor(0,0,0,100,0,0);
        initNight = false;
        }
        else
        {
           
        }
    }
    else if(nightOff == true)
    {
        changeLEDColor(0,0,0,0,0,0);
        nightOff = false;
    }
    else
    {
        
    }
}



void changeLEDColor(double r1f, double g1f, double b1f, double r2f, double g2f, double b2f)
{
    double r1double = r1, g1double = g1, b1double = b1, r2double = r2, g2double = g2, b2double = b2;
    for( int i = 1 ; i <= 255; i += 1 )
    {
        //Strip 1
        if (r1 < r1f)
        {
            r1double += (r1f-r1)/255.0;
        }
        else
        {
            r1double -= (r1-r1f)/255.0;
        }
        if (g1 < g1f)
        {
            g1double += (g1f-g1)/255.0;
        }
        else
        {
            g1double -= (g1-g1f)/255.0;
        }
        if (b1 < b1f)
        {
            b1double += (b1f-b1)/255.0;
        }
        else
        {
            b1double -= (b1-b1f)/255.0;
        }
        //strip2
        if (r2 < r2f)
        {
            r2double += (r2f-r2)/255.0;
        }
        else
        {
            r2double -= (r2-r2f)/255.0;
        }
        if (g2 < g2f)
        {
            g2double += (g2f-g2)/255.0;
        }
        else
        {
            g2double -= (g2-g2f)/255.0;
        }
        if (b2 < b2f)
        {
            b2double += (b2f-b2)/255.0;
        }
        else
        {
            b2double -= (b2-b2f)/255.0;
        }
        
        analogWrite(led1, r1double);
        analogWrite(led2, g1double);
        analogWrite(led3, b1double);
        analogWrite(led4, r2double);
        analogWrite(led5, g2double);
        analogWrite(led6, b2double);
        delay(3);
    }
    r1 = r1f;
    b1 = b1f;
    g1 = g1f;
    r2 = r2f;
    b2 = b2f;
    g2 = g2f;
    analogWrite(led1, r1);
    analogWrite(led2, g1);
    analogWrite(led3, b1);
    analogWrite(led4, r2);
    analogWrite(led5, g2);
    analogWrite(led6, b2);
}


void LEDTimeOut()
{
changeLEDColor(0,0,0,0,0,0);
print = "#FFFFFF";
timer.stop();
userColor = false;
}

int ledDim(String dimming) {
     int dim = atoi(dimming.c_str());
     double r1Dim = r1*dim/100;
     double b1Dim = b1*dim/100;
     double g1Dim = g1*dim/100;
     double r2Dim = r2*dim/100;
     double b2Dim = b2*dim/100;
     double g2Dim = g2*dim/100;
     changeLEDColor(r1Dim, b1Dim, g1Dim, r2Dim, b2Dim, g2Dim);
}

int ledToggle(String command) 
{
    initRain = true;
    initNight = true;
    print = command;
    if (command == "party")
    {
        party = true;
        initParty = true;
        print = "#FFFFFF";
        return 42;
    }
    else if (command == "off")
    {
        party = false;
        changeLEDColor(0,0,0,0,0,0);
        timer.stop();
        print = "#FFFFFF";
        strobe = false;
        userColor = false;
    }
    else if (command == "strobe")
    {
        strobe = true;
    }
    else
    {
        int rt, bt, gt;
        sscanf(command, "#%02x%02x%02x", &rt, &gt, &bt);
        party = false;
        changeLEDColor(rt, gt, bt, rt, gt, bt);
        userColor = true;
        timer.start();
    }
}
int ledToggle2(String command) {
    initRain = true;
    initNight = true;
    if(command == "sunrise")
    {
        nightTime = false;
        if(userColor == false && rain == false)
        {
            nightOff = true;
        }
        else
        {
            
        }
    }
    else if(command == "sunset")
    {
        nightTime = true;
        initNight = true;
    }
    else if(command == "rain")
    {
        rain = true;
        initRain = true;
    }
    else if(command == "clear")
    {
        rain = false;
        if(userColor == false && nightTime == false)
        {
            rainOff = true;
        }
        else
        {
            
        }
    }
    else
    {
        
    }
}
