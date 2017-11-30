#include <iostream>
//#include <delay.h>
#include <iotDataQueue.h>

void init(void);
void lcd_init(void);
void read_sens(void);
void print_data(void);

int count=0;
volatile int8_t number[]= {1,2,3,4,5,6,7,8,9,10};
int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
int h1, h2, h3, h4, h5, h6, h7, h8, h9, h10;
volatile int temp[]= {t1,t2,t3,t4,t5,t6,t7,t8,t9,t10};
volatile int hum[]= {h1,h2,h3,h4,h5,h6,h7,h8,h9,h10};
int input;


using namespace std;

int main()
{

    init();

    lcd_init();
    while(1)
    {

    if (count < 10)
    {
      read_sens();
    }
    else{
        count = 0;
        print_data();
    }


    //iotDataQueue temperature, humidity; //create two queue objects

    //temperature.init();
    //humidity.init();

    //temperature.qput(10);
    //humidity.qput(19);

    //temperature.qput(20);
    //humidity.qput(1);
    //this is a comment
    //cout << "\nContents of Temperature queue: ";

    //cout << temperature.qget() << " ";
    //cout << temperature.qget() << "\n";

    //cout << "Contents of Humidity queue: ";
    //cout << humidity.qget() << " ";
    //cout << humidity.qget() << "\n";

    //return 0;

        //cin >>




    }
}

void init(void)
{
cout << "Welcome!\n Your System is now Initialised.";
//delay(2000);
    //Initialise the MCU Manager items here
}

void lcd_init(void)
{
//initialise the Display items here
cout << "\nYour Display is now Initialised.";
//delay(2000);
}

void read_sens()
{
 cout << "\nPlease manually enter Sensor Temperature #" << (count+1) << " (0-100 Deg C):" << endl;
 cin >> input;
 cout << "\nYou entered: " << input << " Deg C" << endl;
 temp[count] = input;
 cout << "\nPlease manually enter Sensor Humidity #" << (count+1) << " (0-100 % RH):" << endl;
 cin >> input;
 cout << "\nYou entered: " << input << " % RH " << endl;
 hum[count] = input;
 count++;
}

void print_data()
{
 int out_num = 1;

 while (out_num < 11)
 {
         //cout << "\nThis is where our dislay printout will happen!!!";
 cout << "\nTemperature Reading #" <<out_num;
 cout << " = " <<temp[out_num-1];
 cout << "     Humidity Reading #" <<out_num;
 cout << " = " <<hum[out_num-1];
 out_num++;
 }
cout << "\n\n\nThe IoT_Data_Queue is now empty and ready for the next 10 Sensor Data Sets!";
}


