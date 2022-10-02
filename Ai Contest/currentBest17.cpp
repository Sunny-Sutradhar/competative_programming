#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int MINION_FOR_TASK0 = -1;
int MINION_FOR_TASK1 = -1;
int MINION_FOR_TASK2 = -1;
int MINION_FOR_TASK3 = -1;
int MINION_FOR_TASK4 = -1;
int MyActualFlagPositionX=-1,MyActualFlagPositionY=-1;

int OPPONENT_MINION = -1;

vector<string>output;

void printMove(int id,int moveX,int moveY){
    string s = "MOVE "+to_string(id)+" "+to_string(moveX)+" "+to_string(moveY);
    output.push_back(s);
}
void fireORfirze(string type,int id){
    string s= type+" "+to_string(id);
    output.push_back(s);
}
void mineInsert(int id,int x,int y){
    string s = "MINE "+to_string(id)+" "+to_string(x)+" "+to_string(y);
}

void printOutput(){
    int n = output.size();
    
    for(int i=0;i<n-1;i++){
        cout<<output[i]<<" | ";
    }
   if(n!=0) cout<<output[n-1]<<endl;
    output.clear();
}

float distance(int x1, int y1, int x2, int y2)
{
    
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

int task0(map<int,vector<int>> &my_minion,int ofx,int ofy,int mx,int my){
    float min_dist = 100000;
    int id = MINION_FOR_TASK0;

    if(id==-1){
        for(auto it : my_minion){
            vector<int>temp;
            temp = it.second;
            //cout<<temp[0]<<" "<<temp[1]<<" "<<x<<" "<<y<<endl;
            float dist = distance(temp[0],temp[1],ofx,ofy);
            //cout<<dist<<endl;
            if(dist<min_dist){
                id = it.first;
                min_dist = dist;
                MINION_FOR_TASK0 = id;
                
            }
        }
    }
    else{
        vector<int>temp;
        temp = my_minion[id];
        min_dist = distance(temp[0],temp[1],ofx,ofy);
    }
    if(min_dist==0){
        printMove(id,mx,my);
    }else{
        printMove(id,ofx,ofy);
    }

    return id;
}

//guardian of My flag
// Task---> 1;
int mineOne = 0,mineTwo=false;
int fire = 0;
int task1(map<int,vector<int>>&my_minion, int my_flag_pos_r,int my_flag_pos_c){
    float min_dist = 100000;
    int id = MINION_FOR_TASK1 ;
    int x,y;
    
    if(id==-1){
       for(auto it : my_minion){
        vector<int>temp;
        temp = it.second;
        float dist = distance(temp[0],temp[1],my_flag_pos_r,my_flag_pos_r);
        if(dist<min_dist){
            id = it.first;
            min_dist = dist;
            x = temp[0];
            y = temp[1];
            MINION_FOR_TASK1 = id;

        }
      }
    }
    else{
       auto mit= my_minion.find(MINION_FOR_TASK1);
       if(mit==my_minion.end()) MINION_FOR_TASK1=-1;
        vector<int>temp;
        temp = my_minion[id];
        min_dist = distance(temp[0],temp[1],my_flag_pos_r,my_flag_pos_r);
    }
   
    if(mineOne==1){
        cout<<"MINE "<<id<<" "<<MyActualFlagPositionX<<" "<<MyActualFlagPositionY;
        mineOne = 2;
    }
    else if(MyActualFlagPositionX!=my_flag_pos_r || MyActualFlagPositionY!=my_flag_pos_c){
        if(fire%5==0){
            fireORfirze("FIRE",id);
        }
        else if(fire==1){
            fireORfirze("FREEZE",id);
        }
        else{
             printMove(id,my_flag_pos_r,my_flag_pos_c);
        }

        fire++;
           
    }
    else if(MyActualFlagPositionX==my_flag_pos_r || MyActualFlagPositionY==my_flag_pos_c){
        
        if(mineOne==0){
            printMove(id,my_flag_pos_r,my_flag_pos_c);
            //if(x==my_flag_pos_r && y==my_flag_pos_c+1)mineOne = 1;
        }
        else{
            if(y==15)mineOne=3;
            if(y==0)mineOne=2;
            if(mineOne==2){
                printMove(id,x,15);
            }else{
                printMove(id,x,0);
            }
        }
    }   
    else{
        fireORfirze("WAIT",id);
    }



    return id;
}

int task2(map<int,vector<int>> &my_minion,map<pair<int,int>,int> &coinAddress){
    float min_dist = 100000;
    int id = MINION_FOR_TASK2;
    int x,y;
    int nearX=-1,nearY=-1;
    if(id==-1){
       auto it = my_minion.begin();
       id = it->first;
       MINION_FOR_TASK2 = id;
    }
    vector<int>temp;
    temp = my_minion[id];
    x = temp[0];
    y = temp[1];

    // for(auto it: coinAddress){
    //     int tempX,tempY;
    //     tempX = it.first.first;
    //     tempY = it.first.second;
    //     float dist = distance(x,y,tempX,tempY);

    //     if(dist<min_dist){
    //         dist = min_dist;
    //         nearX = tempX;
    //         nearY = tempY;
    //     }
    // }
    auto it = coinAddress.begin();
    nearX = it->first.first;
    nearY = it->first.second;
    if(nearX!=-1){
        printMove(id,nearX,nearY);
        
    }

    return id;

}

int task3(map<int,vector<int>>&my_minion, map<int,vector<int>>&oppnent_minion,int oppnentFlagX,int oppnentFlagY){

    int id = MINION_FOR_TASK3;
    int x,y;

    if(id==-1){
       auto it = my_minion.begin();
       id = it->first;
       MINION_FOR_TASK2 = id;
    }
    vector<int>temp;
    temp = my_minion[id];
    x = temp[0];
    y = temp[1];

    if(oppnent_minion.size()==0){
         printMove(id,oppnentFlagX,oppnentFlagY);
         return id;
    }
    
    int oppnent_pos_x , oppnent_pos_y;
    bool fire = false;
    for(auto it : oppnent_minion){
        vector<int>temp;
        temp = it.second;
        oppnent_pos_x = temp[0];
        oppnent_pos_y = temp[1];
        if((x==oppnent_pos_x && y==oppnent_pos_y) || (x==oppnent_pos_x-1 && y==oppnent_pos_y) || (x==oppnent_pos_x+1 && y==oppnent_pos_y) || (x==oppnent_pos_x && y==oppnent_pos_y-1) || (x==oppnent_pos_x && y==oppnent_pos_y+1)){
            fire = true;
        }
    }

   
    
    
    
    if(fire){
        cout<<"FIRE "<<id;
    }else{
        printMove(id,oppnentFlagX,oppnentFlagY);
    }

    return id;
}


int main()
{
    int height;
    int width;
    cin >> height >> width; cin.ignore();
    vector<string> maze;
    char mat[50][50];

    for (int i = 0; i < height; i++) {
        string row;
        cin >> row; cin.ignore();
        maze.push_back(row);    
    }

    



    int my_flag_base_r;
    int my_flag_base_c;
    cin >> my_flag_base_r >> my_flag_base_c; cin.ignore();
    int opponent_flag_base_r;
    int opponent_flag_base_c;
    cin >> opponent_flag_base_r >> opponent_flag_base_c; cin.ignore();
    string fire_name;
    int fire_price;
    int fire_damage;
    cin >> fire_name >> fire_price >> fire_damage; cin.ignore();
    string freeze_name;
    int freeze_price;
    int freeze_damage;
    cin >> freeze_name >> freeze_price >> freeze_damage; cin.ignore();
    string mine_name;
    int mine_price;
    int mine_damage;
    cin >> mine_name >> mine_price >> mine_damage; cin.ignore();

    // game loop
    int index = 0,sz,returnIndex = 0;
    vector<pair<int,int>> path;
    map<int,vector<pair<int,int>>>all_path;
    bool cond = true;
    bool FlagPos= true;
    while (1) {
        int my_score;
        int opponent_score;
        cin >> my_score >> opponent_score; cin.ignore();
        int my_flag_pos_r;
        int my_flag_pos_c;
        int my_flag_carrier;
        cin >> my_flag_pos_r >> my_flag_pos_c >> my_flag_carrier; cin.ignore();
        int opponent_flag_pos_r;
        int opponent_flag_pos_c;
        int opponent_flag_carrier;
        cin >> opponent_flag_pos_r >> opponent_flag_pos_c >> opponent_flag_carrier; cin.ignore();
        int my_alive_minion_cnt;
        cin >> my_alive_minion_cnt; cin.ignore();
        //edit
        map<int,vector<int>>my_minion,opponent_minion;
        
        for (int i = 0; i < my_alive_minion_cnt; i++) {
            vector<int>temp;
            int id;
            int pos_r;
            int pos_c;
            int health;
            int timeout;
            cin >> id >> pos_r >> pos_c >> health >> timeout; cin.ignore();
            //edit
            temp.push_back(pos_r);
            temp.push_back(pos_c);
            temp.push_back(health);
            temp.push_back(timeout);
            my_minion[id] = temp;
        }
        int visible_minion_cnt;
        cin >> visible_minion_cnt; cin.ignore();
        for (int i = 0; i < visible_minion_cnt; i++) {
            vector<int>temp;
            int id;
            int pos_r;
            int pos_c;
            int health;
            int timeout;
            cin >> id >> pos_r >> pos_c >> health >> timeout; cin.ignore();
            //edit
            temp.push_back(pos_r);
            temp.push_back(pos_c);
            temp.push_back(health);
            temp.push_back(timeout);
            opponent_minion[id] = temp;
        }
        int visible_coin_cnt;
        map<pair<int,int>,int>coin;
        cin >> visible_coin_cnt; cin.ignore();
        for (int i = 0; i < visible_coin_cnt; i++) {
            int pos_r;
            int pos_c;
            cin >> pos_r >> pos_c; cin.ignore();
            coin.insert({{pos_r,pos_c},0});
        }
        
        //Task Stated

         if(FlagPos==true){
            MyActualFlagPositionX = my_flag_pos_r;
            MyActualFlagPositionY = my_flag_pos_c;
            FlagPos= false;

        }
        //Chaking existing minion is alive or not
        auto idChaker0 = my_minion.find(0);
        if(idChaker0==my_minion.end())MINION_FOR_TASK0=-1;
        auto idChaker1 = my_minion.find(1);
        if(idChaker1==my_minion.end())MINION_FOR_TASK1=-1;
        auto idChaker2 = my_minion.find(2);
        if(idChaker2==my_minion.end())MINION_FOR_TASK2=-1;
        auto idChaker3 = my_minion.find(3);
        if(idChaker3==my_minion.end())MINION_FOR_TASK3=-1;
        auto idChaker4 = my_minion.find(4);
        if(idChaker4==my_minion.end())MINION_FOR_TASK4=-1;

        
        
        int numberOfFreeMinion = my_minion.size();
        if(numberOfFreeMinion==0)continue;

        //1st Minion Task Start
          int minion_nearest_opponant_flag = task0(my_minion,opponent_flag_pos_r,opponent_flag_pos_c,my_flag_base_r,my_flag_base_c);
          numberOfFreeMinion --;
          my_minion.erase(minion_nearest_opponant_flag);
        //1st Minion Task End
        

        //2nd Minion Task Start
           int guardinaMinion = task1(my_minion,my_flag_pos_r,my_flag_pos_c);
           numberOfFreeMinion --;

           my_minion.erase(guardinaMinion);

        //2nd Minion Task End


        //3rd Minion Task Start
           int coinFinderMinion = task2(my_minion,coin);
           numberOfFreeMinion --;
           my_minion.erase(coinFinderMinion);

        //3rd Minion Task End
        
        //4th Minion Task Start

        //    int oppoentKiller = task3(my_minion,opponent_minion,opponent_flag_pos_r,opponent_flag_pos_c);
        //    numberOfFreeMinion --;
        //    if(numberOfFreeMinion!=0){
        //       cout<<" | ";
        //    }else{
        //       cout<<endl;
        //       continue;
        //    }
        //    my_minion.erase(oppoentKiller);
         
        
        //4th Minion Task Stop

        
        vector<int> aliveMinion;
        
        for(auto it: my_minion){
            aliveMinion.push_back(it.first);
        }
        int numberOfAliveMinion = aliveMinion.size();

        for(int i=0;i<numberOfAliveMinion;i++){
             //one Minion Always Capture the flag and return to base
             vector<int>minion_data;
             int minion_id = aliveMinion[i];
             minion_data = my_minion[minion_id];
             int x = minion_data[0];
             int y = minion_data[1];
             
             
                if(x==opponent_flag_pos_r && y==opponent_flag_pos_c){
                     printMove(minion_id,my_flag_base_r,my_flag_base_c);
                }else{
                    printMove(minion_id,opponent_flag_pos_r,opponent_flag_pos_c);
                }
                //printMove(minion_id,my_flag_base_r,my_flag_base_r);
               
             
            
        }
        printOutput();

    }
}