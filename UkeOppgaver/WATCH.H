//  ***************************************************************
//  ***************************************************************
//  ***                                                         ***
//  ***  NB:  Deler av koden virker KUN under/p† BORLAND 4.5 !  ***
//  ***                                                         ***
//  ***************************************************************
//  ***************************************************************


#ifndef  __WATCH_H
#define  __WATCH_H

#include <iostream.h>        //  cout
#include <dos.h>             //  struct time, gettime

class Watch  {
  private:
    time* start_time;
    time* stop_time;
    int   time_taken;

  public:
    Watch()  {  time_taken = 0;  }
    void start();
    void stop();
    void used_time();
};


void Watch::start()  {
  time_taken = 0;
  gettime(start_time);
}


void Watch::stop()  {
  time_taken = 1;
  gettime(stop_time);
}


void Watch::used_time()  {
  if (time_taken)  {
     long start_ti, stop_ti;
     long diff;
     start_ti = (int(start_time->ti_hour)*360000)
	      + (int(start_time->ti_min)*6000)
	      + (int(start_time->ti_sec)*100)
	      +  int(start_time->ti_hund);
     stop_ti  = (int(stop_time->ti_hour)*360000)
	      + (int(stop_time->ti_min)*6000)
	      + (int(stop_time->ti_sec)*100)
	      +  int(stop_time->ti_hund);
     diff = stop_ti - start_ti;
     cout << diff/100 << ':';
     if (diff % 100  < 10)  cout << '0';
     cout << diff % 100;
  } else
    cout << "\nNo time-difference available.\n";
}

#endif
