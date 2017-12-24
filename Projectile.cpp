//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {
  // Your code here ...
  
  float thetadeg = 1.0;
  float Vy = v;
  float Vh = v;
  float timeinit1;
  float timeinit2;
 float t1 = t;
 float h1 = h;
 float difh = h1-t1;
 float dish;
 float builddis = b;
 float buildandwidth = w;
 float targetdistrue = d;
 float h2 = t;
 float timefinal1;
 float timefinal2;
 float Vy2 = 0;
 
  
  
  //Convert theta from degree to rad.
  //float thetadeg = theta * (M_PI/180);
	thetadeg = theta * (M_PI/180.0);
  //Vertical component of velocity. 
 Vh = Vh*(cos(thetadeg));
 Vy=Vy*(sin(thetadeg));
  
  //Test for disriminant
  timeinit1 = (-Vy+sqrt(pow(Vy,2)+(4.9*4)*(difh)))/(-9.8);
  timeinit2 = (-Vy-sqrt(pow(Vy,2)+(4.9*4)*(difh)))/(-9.8);
  
  
  float time1 = 0;
	
	//Gets time for ball to fall to height h. 
	if (timeinit1 > timeinit2){
		time1 = timeinit1;
	}
	else {
		time1 = timeinit2;
	}
	
	
  dish = Vh*time1;
  buildandwidth = b + w;
  
   
   
   //Now my calculation for if the ball hits the walls. 
   //First find the time at wall one. 
   
   float time3 = b/Vh;
   float disy = (Vy*(time3)) + ((-4.9)*(pow(time3,2)))+h;
   
   float time4 = (b+w)/Vh;
   float disy2 = (Vy*(time4)) + ((0.5)*(-9.8)*(pow(time4,2)))+h;
   
  float timeinit5 = (Vy+sqrt(pow(Vy,2)-(4.9*4)*(-h)))/(9.8);
  float timeinit6 = (Vy-sqrt(pow(Vy,2)-(4.9*4)*(-h)))/(9.8);
  float time9 = 0;
	
	
	
	//Gets time for ball to fall to height h. 
	
	
	if (w <=0 || b<=0 || h<0 || theta<-90 || theta >270 || m<0 || v<0){
		return false;
	}
	
	if (theta == 90 || v==0 || theta == -90 || theta == 270){
		destX = 0;
		destY=h;
		return true;
	}
	
	if (timeinit5 > timeinit6){
		time9 = timeinit5;
	}
	else {
		time9 = timeinit6;
	}
   
   float dishground = Vh*time9;
   
   
   
  
	 if (Vh<0){
		destX = dishground;
	  destY = 0;
	  
	  return true;
	}
	
    if ((dish >= builddis) && (dish <= buildandwidth)){
	  destX = dish;
	  destY = t;
	  return true;

  }
   
   else if (t>0){
	   if (disy > 0 && disy < t){
	  
	  destX = b;
	  destY = disy;
	  
	  return true;
	  
	  /* //Case 1
	  //NOw is taking the velocity at the height of the second building and finding the time it takes to hit the ground. 
	  Vy2 = (difh + (-0.5)*(-9.8)*(pow(time1,2))/(time1));
	  //Taking the time it takes to fall from height of the building to the ground. 
	  timefinal1 = (Vy2+sqrt(pow(Vy2,2)-(4.9*4)*(t1)))/(9.8);
	  
	  int dish2=Vh*timefinal1;
	   */
  }
	   
   }
   else if (disy2 < 0 && disy > t){
	   destX = b;
	  destY = disy2;
	  return true;
   }
  
 
 
	 destX = dishground;
	 destY=0;
	 return true;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....

  float h = 50;
  float v = 9.2;
  float m = 1;
  float theta = 67.89;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 50;
  float b = 10;
  float w = 20;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
