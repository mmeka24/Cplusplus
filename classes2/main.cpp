/*
Nov 15 2023. manasvi meka. classes project. 
objective: create a media database to add, delete, and search items. 
*/
#include <iostream>
#include <vector>
#include <cstring>
#include "game.h"
using namespace std;
//Master manages vectors of pointers to media obj. methods are add, rm (remove), and search/del
class Master{
	public:
		vector<media*>* list = new vector<media*>;
		void add(char * input){//get type and add
			cout << "Type which media: Music, Game, or Movie? "<<endl;
			cin.getline(input,10);
			//media wanted to add. identify based on static var num. 
			if(strcmp(input, "Music")==0){
				media::type = 0;
				music *mus = new music();
				list->push_back(mus);
				mus->print();

			}
			else if(strcmp(input,"Game")==0){
				media::type = 2;
				game *gme = new game();
				list->push_back(gme);
				gme->print();
			}
			else if(strcmp(input,"Movie")==0){
				media::type = 1;
				movie *mov = new movie();
				list->push_back(mov);
				mov->print();
			}
			else{
				cout << "Invalid media type"<<endl;
			}
		}
		void rm(vector<media*>*list, vector<media*>::iterator &i, bool del){
		  if(del){// if delete is true otherwise just print when searching
				delete(*i);
				list->erase(i);
				i--;
			}
			else{
				(*i)->print();
			}
		}
		void search_del(char * input, bool del){
			cout << "Search by Title or Year enter as is"<<endl;
			cin.getline(input,10);
			static bool title;//get search field
			if(strcmp("Title", input) == 0){
				cout << "Title?"<<endl;
				cin.getline(input, 30);
				title = true;
			}
			else if(strcmp("Year", input) == 0){
				cout << "Year?"<<endl;
				cin.getline(input, 30);
				title = false;
			}
			else{
				cout <<"Invalid Field"<<endl;
				return search_del(input, del);
			}//search for given field
			for(auto i = list->begin();i!=list->end();++i){
				if(title){
					if(!strcmp(input,(*i)->get_title())){
						rm(list, i, del);		
					}
				}
				else{
					if(!strcmp(input,(*i)->get_year())){
						rm(list, i, del);		
					}
				}
			}
		}
};
int main(){
	static char* input = media::response;//use our response
	static Master * master = new Master();//use class
	cout << "ADD, SEARCH, DELETE, or QUIT"<<endl;
	cin.getline(input,10);
	if(strcmp(input, "QUIT")==0){
		return 0;	
	}
	if(strcmp(input, "ADD")==0){
		master->add(input);//recurse to command
	}
	if(strcmp(input, "SEARCH") == 0){
		master->search_del(input, false);
	}
	if(strcmp(input, "DELETE") == 0){
		master->search_del(input, true);
	}
	return main();
}	



