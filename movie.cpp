#include <iostream>
#include "movie.h"
#include "media.h"
#include <cstring>
#include "music.h"
using namespace std;
movie::movie() : music::music(){
	if(type == 1){
		cout << "Enter the fields in the following format: title,director,year,duration,rating"<<endl;
		cin.getline(response,150);
		strcpy(title, strtok(response, ","));
		strcpy(field_one, strtok(NULL, ","));
		strcpy(year,strtok(NULL, ","));
		strcpy(field_two, strtok(NULL,","));
		strcpy(field_three, strtok(NULL, ","));		
	}
}
char * movie::get_rating(){
	return this->field_three;
}
